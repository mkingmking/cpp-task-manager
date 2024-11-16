#ifndef TASK_MANAGER_GUI_H
#define TASK_MANAGER_GUI_H

#include "task_model.h"
#include "task_view.h"
#include <QWidget>

class TaskManagerGUI : public QWidget {
    Q_OBJECT

private:
    TaskModel* model;  // Reference to the model
    TaskView* view;    // Reference to the view

public:
    explicit TaskManagerGUI(QWidget* parent = nullptr);
    ~TaskManagerGUI() override;

private slots:
    void handleAddTask();
    void handleCompleteTask();
    void updateView();
};

#endif // TASK_MANAGER_GUI_H
