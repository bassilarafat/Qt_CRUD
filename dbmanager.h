#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>



class dbmanager
{
public:
    dbmanager();

    ~dbmanager();

    bool userExists(const QString& name) const;
    bool addUser(const QString& name,const int& grade);
    bool removeUsername(const QString& name);
    bool removeAllUsers();

public:
    QSqlDatabase mydb;
};

#endif // DBMANAGER_H
