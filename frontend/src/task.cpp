#include "task.h"

// Constructor
Task::Task(int id, const std::string& desc) : id(id), description(desc), completed(false) {}

// Getters
int Task::getId() const { return id; }
std::string Task::getDescription() const { return description; }
bool Task::isCompleted() const { return completed; }

// Setters
void Task::markCompleted() { completed = true; }

// Utility
std::string Task::toString() const {
    return std::to_string(id) + ". " + description + (completed ? " [Completed]" : "");
}
