#ifndef DELETEFORM_H
#define DELETEFORM_H

#include <QWidget>

namespace Ui {
class deleteForm;
}

class deleteForm : public QWidget
{
    Q_OBJECT

public:
    explicit deleteForm(QWidget *parent = nullptr);
    ~deleteForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deleteForm *ui;
};

#endif // DELETEFORM_H
