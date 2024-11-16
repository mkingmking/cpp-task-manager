#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task.h"
#include <vector>
#include <memory>
#include <string>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>


class TaskManager {
private:
    std::vector<std::shared_ptr<Task>> tasks;
    int nextId;
    QSqlDatabase db;

    void executeQuery(const QString& query);  // Helper to execute SQL queries

public:
    TaskManager();
    ~TaskManager();

   void addTask(const QString& description);
    void completeTask(int id);
    void deleteTask(int id);
    
    std::vector<std::pair<int, QString>> listTasks(bool showCompleted = false);
};

#endif // TASK_MANAGER_H

