#include "task_model.h"
#include <iostream>

TaskModel::TaskModel(QObject* parent) : QObject(parent) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasks.db");

    if (!db.open()) {
        std::cerr << "Error opening database: " << db.lastError().text().toStdString() << std::endl;
        exit(1);
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS tasks ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "description TEXT NOT NULL, "
               "completed INTEGER NOT NULL DEFAULT 0);");
}

TaskModel::~TaskModel() {
    if (db.isOpen()) {
        db.close();
    }
}

void TaskModel::addTask(const QString& description) {
    QSqlQuery query;
    query.prepare("INSERT INTO tasks (description, completed) VALUES (:description, 0);");
    query.bindValue(":description", description);

    if (query.exec()) {
        emit tasksUpdated();
    } else {
        std::cerr << "Error adding task: " << query.lastError().text().toStdString() << std::endl;
    }
}

void TaskModel::completeTask(int id) {
    QSqlQuery query;
    query.prepare("UPDATE tasks SET completed = 1 WHERE id = :id;");
    query.bindValue(":id", id);

    if (query.exec()) {
        emit tasksUpdated();
    } else {
        std::cerr << "Error marking task as completed: " << query.lastError().text().toStdString() << std::endl;
    }
}

std::vector<std::pair<int, QString>> TaskModel::listTasks(bool showCompleted) {
    std::vector<std::pair<int, QString>> tasks;

    QSqlQuery query;
    if (showCompleted) {
        query.prepare("SELECT id, description FROM tasks;");
    } else {
        query.prepare("SELECT id, description FROM tasks WHERE completed = 0;");
    }

    if (query.exec()) {
        while (query.next()) {
            int id = query.value(0).toInt();
            QString description = query.value(1).toString();
            tasks.emplace_back(id, description);
        }
    } else {
        std::cerr << "Error fetching tasks: " << query.lastError().text().toStdString() << std::endl;
    }

    return tasks;
}
