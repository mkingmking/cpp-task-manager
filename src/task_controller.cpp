#include "task_controller.h"

TaskController::TaskController(TaskModel* model, TaskView* view, QObject* parent)
    : QObject(parent), model(model), view(view) {
    connect(view->getAddButton(), &QPushButton::clicked, this, &TaskController::addTask);
    connect(view->getCompleteButton(), &QPushButton::clicked, this, &TaskController::completeTask);
    connect(model, &TaskModel::tasksUpdated, this, &TaskController::updateView);

    updateView();
}

void TaskController::addTask() {
    QString description = view->getTaskInput()->text();
    if (!description.isEmpty()) {
        model->addTask(description);
        view->getTaskInput()->clear();
    }
}

void TaskController::completeTask() {
    auto selected = view->getTaskList()->currentItem();
    if (selected) {
        int id = selected->data(Qt::UserRole).toInt();
        model->completeTask(id);
    }
}

void TaskController::updateView() {
    view->getTaskList()->clear();
    auto tasks = model->listTasks();
    for (const auto& task : tasks) {
        QListWidgetItem* item = new QListWidgetItem(QString::number(task.first) + ". " + task.second);
        item->setData(Qt::UserRole, task.first);
        view->getTaskList()->addItem(item);
    }
}
