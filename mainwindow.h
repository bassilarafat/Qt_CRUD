#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void addNew(QString name ,int grade);
    void deleteUser(QString name);

    ~MainWindow();

private slots:
    void on_pushButtonUpdate_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonDeleteAll_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
