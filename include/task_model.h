#ifndef TASK_MODEL_H
#define TASK_MODEL_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <vector>
#include <utility>

class TaskModel : public QObject {
    Q_OBJECT

private:
    QSqlDatabase db;

public:
    explicit TaskModel(QObject* parent = nullptr);
    ~TaskModel();

    void addTask(const QString& description);
    void completeTask(int id);
    std::vector<std::pair<int, QString>> listTasks(bool showCompleted = false);

signals:
    void tasksUpdated();  // Notify observers that the task list has changed
};

#endif // TASK_MODEL_H
