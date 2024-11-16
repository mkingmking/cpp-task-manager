#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task.h"
#include <vector>
#include <memory>
#include <string>

class TaskManager {
private:
    std::vector<std::shared_ptr<Task>> tasks;
    int nextId;

public:
    TaskManager();

    void addTask(const std::string& description);
    void completeTask(int id);
    void deleteTask(int id);
    void listTasks() const;
};

#endif // TASK_MANAGER_H
