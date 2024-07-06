#ifndef TODOLIST_H
#define TODOLIST_H

#include <QWidget>

namespace Ui {
class todolist;
}

class todolist : public QWidget
{
    Q_OBJECT

public:
    explicit todolist(QWidget *parent = nullptr);
    ~todolist();

private:
    Ui::todolist *ui;
};

#endif // TODOLIST_H
