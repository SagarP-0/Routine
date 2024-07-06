#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //first page to be routine page
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//buttons to switch  betn pages

void MainWindow::on_RoutineBut_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ToDoBut_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_SyllabusBut_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



