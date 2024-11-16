#include "task_manager.h"
#include <iostream>
#include <algorithm>

TaskManager::TaskManager() : nextId(1) {}

void TaskManager::addTask(const std::string& description) {
    tasks.push_back(std::make_shared<Task>(nextId++, description));
    std::cout << "Task added successfully!\n";
}

void TaskManager::completeTask(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const auto& task) {
        return task->getId() == id;
    });

    if (it != tasks.end()) {
        (*it)->markCompleted();
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Task not found!\n";
    }
}

void TaskManager::deleteTask(int id) {
    auto it = std::remove_if(tasks.begin(), tasks.end(), [id](const auto& task) {
        return task->getId() == id;
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "Task deleted successfully!\n";
    } else {
        std::cout << "Task not found!\n";
    }
}

void TaskManager::listTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available!\n";
        return;
    }

    for (const auto& task : tasks) {
        std::cout << task->toString() << '\n';
    }
}
