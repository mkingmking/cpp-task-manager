#ifndef TASK_CONTROLLER_H
#define TASK_CONTROLLER_H

#include "task_model.h"
#include "task_view.h"
#include <QObject>

class TaskController : public QObject {
    Q_OBJECT

public:
    TaskController(TaskModel* model, TaskView* view, QObject* parent = nullptr);

private slots:
    void addTask();
    void completeTask();
    void updateView();

private:
    TaskModel* model;
    TaskView* view;
};

#endif // TASK_CONTROLLER_H
