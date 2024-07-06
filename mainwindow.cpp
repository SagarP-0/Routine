#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //first page to be routine page
    ui->stackedWidget->setCurrentIndex(0);

    //storing tododlist data
    //QFile file()
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



void MainWindow::on_AddTaskBut_clicked()
{
    //Lising the item in the listwidget
    QListWidgetItem* item = new QListWidgetItem(ui->tasktextbox->text(),ui->listWidget);
    ui->listWidget->addItem(item);

    //to be editable (stackoflol)
    //item->setFlags(item->flags() | Qt::ItemIsEditable);
    //clearing textbox after adding
    ui->tasktextbox->clear();
    //focusing on textbox after adding
    ui->tasktextbox->setFocus();
}


void MainWindow::on_DeleteTaskBut_clicked()
{
    //taking the item from current row and passing it
    //ot the actual "item" element in 'QListWidgetItem* item'
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void MainWindow::on_DeleteAllTasksBut_clicked()
{
    //self explanatory
    ui->listWidget->clear();
}

