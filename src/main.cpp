#include "task_manager_gui.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    TaskManagerGUI gui;
    gui.setWindowTitle("Task Manager");
    gui.resize(400, 300);
    gui.show();

    return app.exec();
}

// Include MOC-generated file for main.cpp
#include "main.moc"
