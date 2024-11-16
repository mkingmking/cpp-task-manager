#ifndef TASK_MANAGER_GUI_H
#define TASK_MANAGER_GUI_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include "task_manager.h"

class TaskManagerGUI : public QWidget {
    Q_OBJECT  // Required for Qt meta-object system

private:
    TaskManager manager;
    QListWidget* taskList;
    QLineEdit* taskInput;

    void refreshTasks();

public:
    explicit TaskManagerGUI(QWidget* parent = nullptr);
    ~TaskManagerGUI() override = default;
};

#endif // TASK_MANAGER_GUI_H
