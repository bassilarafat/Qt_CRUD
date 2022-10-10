#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnew.h"
#include "deleteform.h"
#include "dbmanager.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include<QSqlError>
#include <QSQlQueryModel>
#include <QSqlQuery>
#include <addnew.h>
#include <QSqlTableModel>

dbmanager dbm;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //call db connection from dnmanager
    dbm;

    //TO DO     //view database data

    QSqlQueryModel *model =new QSqlQueryModel();

    model->setQuery("SELECT * FROM Students" ,dbm.mydb);
    ui->tableViewData->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addNew(QString name, int grade)
{
    //add method
    dbm.addUser(name,grade);

}

void MainWindow::deleteUser(QString name)
{
    dbm.removeUsername(name);

}



void MainWindow::on_pushButtonUpdate_clicked()
{
    //show db data
    QSqlTableModel *model = new QSqlTableModel(this);
    model->QSqlQueryModel::setQuery("SELECT * FROM Students" ,dbm.mydb);
    ui->tableViewData->setModel(model);

}


void MainWindow::on_pushButtonAdd_clicked()
{
    //open add new  widget

    AddNew *newW=0;
    newW =new AddNew();
    newW->show();
}


void MainWindow::on_pushButtonDelete_clicked()
{
    //open deleteform  widget

        deleteForm *newW=0;
        newW =new deleteForm();
        newW->show();

}


void MainWindow::on_pushButtonDeleteAll_clicked()
{
      QMessageBox msgBox;
      msgBox.setText("Do you want to remove All Users?");
      msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

//      QSqlQuery query;
//      query.prepare("DELETE FROM Students WHERE id= rowoidx");
//      query.exec();

      int ret = msgBox.exec();
           switch (ret) {
             case QMessageBox::Ok:
                 //delete all db
                 dbm.removeAllUsers();
                 break;
             case QMessageBox::Cancel:
                 // Cancel was clicked
                 break;
             default:
                 // should never be reached
                 break;
           }
}

