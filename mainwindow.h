#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QTableView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTableView *createView(const QString &title, QSqlTableModel *model);
    void initializeModel(QSqlTableModel *model);
    
private slots:
    void on_searchLineEdit_textChanged(const QString &arg1);

    void on_actionAdd_triggered();

    void on_actionDelete_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QSqlTableModel  *model;
};

#endif // MAINWINDOW_H
