#ifndef TASK_H
#define TASK_H

#include <string>


class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    // Constructor
    Task(int id, const std::string& desc);

    // Getters
    int getId() const;
    std::string getDescription() const;
    bool isCompleted() const;

    // Setters
    void markCompleted();

    // Utility
    std::string toString() const;
};

#endif // TASK_H
