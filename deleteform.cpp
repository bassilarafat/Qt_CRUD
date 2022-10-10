#include "deleteform.h"
#include "mainwindow.h"
#include "ui_deleteform.h"

#include <QMessageBox>

deleteForm::deleteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteForm)
{
    ui->setupUi(this);
}

deleteForm::~deleteForm()
{
    delete ui;
}

void deleteForm::on_pushButton_clicked()
{
    QString name =ui->lineEditName->text();

    MainWindow w;

    QMessageBox msgBox;
       msgBox.setText("Do you want to remove "+name+" user ?");
       msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
     int ret = msgBox.exec();
     switch (ret) {
         case QMessageBox::Ok:
              w.deleteUser(name);
                break;
         case QMessageBox::Cancel:
                 // Cancel was clicked
                 break;
         default:
                 // should never be reached
                 break;
           }


}

