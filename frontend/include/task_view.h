#ifndef TASK_VIEW_H
#define TASK_VIEW_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

class TaskView : public QWidget {
    Q_OBJECT

public:
    explicit TaskView(QWidget* parent = nullptr);
    QLineEdit* getTaskInput() const;
    QListWidget* getTaskList() const;
    QPushButton* getAddButton() const;
    QPushButton* getCompleteButton() const;

private:
    QLineEdit* taskInput;
    QListWidget* taskList;
    QPushButton* addButton;
    QPushButton* completeButton;
};

#endif // TASK_VIEW_H
