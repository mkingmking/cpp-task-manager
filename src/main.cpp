#include "task_manager.h"
#include <iostream>

void displayMenu() {
    std::cout << "\nTask Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Complete Task\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. List Tasks\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    TaskManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Clear newline
                std::string desc;
                std::cout << "Enter task description: ";
                std::getline(std::cin, desc);
                manager.addTask(desc);
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter task ID to complete: ";
                std::cin >> id;
                manager.completeTask(id);
                break;
            }
            case 3: {
                int id;
                std::cout << "Enter task ID to delete: ";
                std::cin >> id;
                manager.deleteTask(id);
                break;
            }
            case 4:
                manager.listTasks();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again!\n";
        }
    } while (choice != 5);

    return 0;
}
