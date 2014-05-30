#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include "connection.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (!createConnection())
        exit(1);

    model = new QSqlTableModel;
    model->setTable("person");
    model->select();

    model->setHeaderData(1, Qt::Horizontal,"Name");
    model->setHeaderData(2, Qt::Horizontal,"Phone");

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
//    ui->tableView->resizeColumnsToContents();
     ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
     ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);




      ui->groupBox->setVisible(false);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchLineEdit_textChanged(const QString &arg1)
{


    model->setTable("person");
    model->setFilter("firstname like '%"+arg1+"%' or phone like '%"+arg1+"%'");

    model->select();

    ui->tableView->setModel(model);
}

void MainWindow::on_actionAdd_triggered()
{
    QIcon iconUp(":/new/icons/arrow-up-c.png");
    QIcon iconDown(":/new/icons/arrow-down-c.png");
    ui->groupBox->setVisible(!ui->groupBox->isVisible());
    ui->groupBox->isVisible()? ui->actionAdd->setIcon(iconUp): ui->actionAdd->setIcon(iconDown);
}

void MainWindow::on_actionDelete_triggered()
{
    model->removeRow(ui->tableView->currentIndex().row());
    model->submitAll();
    model->select();
//    ui->tableView->OnItem;
}

void MainWindow::on_pushButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString phone = ui->phoneLineEdit->text();

    if(name.trimmed().isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Please enter a name");
        msgBox.exec();
    }else if(phone.trimmed().isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Please enter a phone number");
        msgBox.exec();
    }else{

        int row = 0;

        model->insertRows(row, 1);
        model->setData(model->index(row ,1),name);
        model->setData(model->index(row ,2),phone);
        model->submitAll();

        ui->nameLineEdit->clear();
        ui->phoneLineEdit->clear();
        ui->nameLineEdit->setFocus();
    }
}
