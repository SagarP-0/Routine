#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QStandardPaths>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_RoutineBut_clicked();

    void on_SyllabusBut_clicked();

    void on_ToDoBut_clicked();

    void on_AddTaskBut_clicked();

    void on_DeleteTaskBut_clicked();

    void on_DeleteAllTasksBut_clicked();

private:
    Ui::MainWindow *ui;

    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\todofile.txt";
};

#endif // MAINWINDOW_H
