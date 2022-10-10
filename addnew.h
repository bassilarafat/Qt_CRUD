#ifndef ADDNEW_H
#define ADDNEW_H

#include <QWidget>

namespace Ui {
class AddNew;
}

class AddNew : public QWidget
{
    Q_OBJECT

public:
    explicit AddNew(QWidget *parent = nullptr);
    ~AddNew();

private slots:
    void on_pushButtonAdd_clicked();

private:
    Ui::AddNew *ui;
};

#endif // ADDNEW_H
