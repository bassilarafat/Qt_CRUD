#include "dbmanager.h"

#include <QMessageBox>
#include<QSqlError>
#include <QSqlQuery>

dbmanager::dbmanager()
{

    //db connection

    mydb=QSqlDatabase::addDatabase("QMYSQL");
    mydb.setHostName("127.0.0.1");
    mydb.setPort(3306);
    mydb.setDatabaseName("qtcrud");
    mydb.setUserName("root");
    mydb.setPassword("A1a2a3@sdzxc");

    if(!mydb.open())
    {
        QMessageBox::critical(nullptr,"Error" , mydb.lastError().text());
        return;
    }
    else
        printf("db connected successfully");

}

dbmanager::~dbmanager(){
    if (mydb.isOpen())
       {
           mydb.close();
    }
}

bool dbmanager::userExists(const QString &name) const
{
    bool exists = false;

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT name FROM Students WHERE name = (:name)");
        checkQuery.bindValue(":name", name);

        if (checkQuery.exec())
        {
            if (checkQuery.next())
            {
                exists = true;
            }
        }
        else
        {
            qDebug() << "User not found:" << checkQuery.lastError();
        }

        return exists;
}

//add new student data in db
bool dbmanager::addUser(const QString &name, const int &grade)
{
    bool success =false;

    if(!name.isEmpty()){
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Students (name, grade) "
                         "VALUES (?, ?)");
        queryAdd.bindValue(0,name);
        queryAdd.bindValue(1,grade);

        if(queryAdd.exec())
                {
                    success = true;
                    QMessageBox::information(nullptr,"Success" , "new data added successfully");
                }
                else{
                    qDebug() <<"Error adding user:" << queryAdd.lastError();
                     }
          }
    else
          {
          qDebug() <<"Error adding user: name cannot be empty";
          }
    return success;

}

bool dbmanager::removeUsername(const QString &name)
{

    bool success = false;
    if (userExists(name))
       {
           QSqlQuery queryDelete;
           queryDelete.prepare("DELETE FROM Students WHERE name = (:name)");
           queryDelete.bindValue(":name", name);
           success = queryDelete.exec();

           if(!success)
               qDebug() << "Delete user failure:" << queryDelete.lastError();
           else
               qDebug() << "User successfully deleted" << name;

       }
       else
       {
           qDebug() << "Error deleting user: user does not exist";
       }

       return success;

}



bool dbmanager::removeAllUsers()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM Students");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Delete all users failed:" << removeQuery.lastError();
    }

    return success;
}
