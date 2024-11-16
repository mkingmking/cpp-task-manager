#include "task_view.h"

TaskView::TaskView(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    taskInput = new QLineEdit(this);
    taskInput->setPlaceholderText("Enter a new task...");
    layout->addWidget(taskInput);

    addButton = new QPushButton("Add Task", this);
    layout->addWidget(addButton);

    completeButton = new QPushButton("Mark as Complete", this);
    layout->addWidget(completeButton);

    taskList = new QListWidget(this);
    layout->addWidget(taskList);
}

QLineEdit* TaskView::getTaskInput() const {
    return taskInput;
}

QListWidget* TaskView::getTaskList() const {
    return taskList;
}

QPushButton* TaskView::getAddButton() const {
    return addButton;
}

QPushButton* TaskView::getCompleteButton() const {
    return completeButton;
}
