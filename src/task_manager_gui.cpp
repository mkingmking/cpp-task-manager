#include "task_manager_gui.h"

TaskManagerGUI::TaskManagerGUI(QWidget* parent) : QWidget(parent), manager() {
    QVBoxLayout* layout = new QVBoxLayout(this);

    taskInput = new QLineEdit(this);
    taskInput->setPlaceholderText("Enter a new task...");
    layout->addWidget(taskInput);

    QPushButton* addTaskButton = new QPushButton("Add Task", this);
    connect(addTaskButton, &QPushButton::clicked, this, [this]() {
        QString desc = taskInput->text();
        if (!desc.isEmpty()) {
            manager.addTask(desc);
            taskInput->clear();
            refreshTasks();
        } else {
            QMessageBox::warning(this, "Warning", "Task description cannot be empty!");
        }
    });
    layout->addWidget(addTaskButton);

    taskList = new QListWidget(this);
    layout->addWidget(taskList);

    QPushButton* refreshButton = new QPushButton("Refresh Tasks", this);
    connect(refreshButton, &QPushButton::clicked, this, [this]() {
        refreshTasks();
    });
    layout->addWidget(refreshButton);
}

void TaskManagerGUI::refreshTasks() {
    taskList->clear();
    auto tasks = manager.listTasks();
    for (const auto& task : tasks) {
        taskList->addItem(QString::number(task.first) + ". " + task.second);
    }
}
