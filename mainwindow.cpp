#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QFile>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    toDoList = new ToDoList(ui->listWidget, ui->tasktextbox, ui->AddTaskBut, ui->DeleteTaskBut, ui->DeleteAllTasksBut, this);
    //Initializing todolist w/ the widgets from the main window ui


    //first page to be routine page
    ui->stackedWidget->setCurrentIndex(0);

    /*
    //doing in inside the constructor
    //storing tododlist data
    QFile file(path);

    //if no file create it.
    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"Error",file.errorString());
    }

    //file from QFile file., accessing textstream
    QTextStream filein(&file);

    //reading item from the file same syntax as in reading from textbox
    while(!filein.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(filein.readLine(),ui->listWidget);
        ui->listWidget->addItem(item);
    }
    file.close();
    */

}

MainWindow::~MainWindow()
{

    //this destructor might be being called first (delete ui part)
    //before todolist destructor so cant put it in the todolist.cpp at the moment!
    //using destructor to ig save data to the file
    QFile file(path);

    //if no file create it. !!WRITEONLY!!!
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::information(0,"Error",file.errorString());
    }

    //file from QFile file., accessing textstream
    QTextStream fileout(&file);

    //reading item from the file same syntax as in reading from textbox
    //everything similar upto here
    for(int i=0; i<ui->listWidget->count(); ++i){
        //similar to cout
        fileout<<ui->listWidget->item(i)->text()<<"\n";
    }

    file.close();

    delete ui;

}

//buttons to switch  betn pages in stacked widgets.

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

/*

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
*/
