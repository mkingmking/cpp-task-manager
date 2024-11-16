#include "task_manager_gui.h"

TaskManagerGUI::TaskManagerGUI(QWidget* parent) : QWidget(parent) {
    model = new TaskModel(this);  // Initialize TaskModel
    view = new TaskView(this);   // Initialize TaskView

    // Set up layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(view);

    // Connect signals from the view to slots in the GUI
    connect(view->getAddButton(), &QPushButton::clicked, this, &TaskManagerGUI::handleAddTask);
    connect(view->getCompleteButton(), &QPushButton::clicked, this, &TaskManagerGUI::handleCompleteTask);

    // Connect signals from the model to the GUI
    connect(model, &TaskModel::tasksUpdated, this, &TaskManagerGUI::updateView);

    // Initialize the view with data from the model
    updateView();
}

TaskManagerGUI::~TaskManagerGUI() {
    delete model;
    delete view;
}

void TaskManagerGUI::handleAddTask() {
    QString taskDescription = view->getTaskInput()->text();
    if (!taskDescription.isEmpty()) {
        model->addTask(taskDescription);  // Add task to the model
        view->getTaskInput()->clear();   // Clear the input field
    } else {
        QMessageBox::warning(this, "Warning", "Task description cannot be empty!");
    }
}

void TaskManagerGUI::handleCompleteTask() {
    QListWidgetItem* selectedItem = view->getTaskList()->currentItem();
    if (selectedItem) {
        int taskId = selectedItem->data(Qt::UserRole).toInt();
        model->completeTask(taskId);  // Mark task as completed in the model
    } else {
        QMessageBox::warning(this, "Warning", "Please select a task to complete!");
    }
}

void TaskManagerGUI::updateView() {
    view->getTaskList()->clear();  // Clear the current task list
    auto tasks = model->listTasks(false);  // Fetch incomplete tasks from the model
    for (const auto& task : tasks) {
        QListWidgetItem* item = new QListWidgetItem(QString::number(task.first) + ". " + task.second);
        item->setData(Qt::UserRole, task.first);  // Store task ID in the item
        view->getTaskList()->addItem(item);       // Add item to the view
    }
}
