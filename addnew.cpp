#include "addnew.h"
#include "mainwindow.h"
#include "ui_addnew.h"

AddNew::AddNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNew)
{
    ui->setupUi(this);
}

AddNew::~AddNew()
{
    delete ui;
}

void AddNew::on_pushButtonAdd_clicked()
{
    QString name =ui->lineEditName->text();
    int grade =ui->lineEditGrade->text().toInt();

    MainWindow w;
    w.addNew(name,grade);
}

