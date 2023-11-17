#ifndef MAINWINDOW_H
#define MAINWINDOW_H

 #include "./ui_mainwindow.h"
//#include "/Users/riley/Project/build-rileySQL-Desktop-Debug/StuInfoManage_autogen/include/ui_mainwindow.h"
#include "BaseCtl.h"
#include "Change.h"
#include "Class.h"
#include "Department.h"
#include "Punishment.h"
#include "Reward.h"
#include "Student.h"
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QVBoxLayout>
#include <Qdebug>
#include <qlogging.h>
#include <stdio.h>
#include <string>

using namespace std;

#include <QMainWindow>
#include <QTableWidgetItem>

extern MYSQL sqlObj;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
    int tb_select = 0; // 0为学生表
  public:
    MainWindow(QWidget *parent = nullptr);
    void query_slot();
    void base_query(BaseCtl *p);
    bool single_query(BaseCtl *p, QTableWidgetItem *item);

    ~MainWindow();

  private slots:
    void on_cls_ar_accepted();
    void on_cla_ar_rejected();
    void on_per_ar_accepted();
    void on_per_ar_rejected();
    void on_depa_ar_accepted();
    void on_depa_ar_rejected();
    void on_chg_accepted();
    void on_chg_rejected();
    void on_rw_accepted();
    void on_rw_rejected();
    void on_pns_accepted();
    void on_pns_rejected();

    void on_stu_clapushButton_clicked();
    void on_stu_query_Button_clicked();
    void on_chg_query_p_clicked();
    void on_rw_query_p_clicked();
    void on_pns__query_p_clicked();
    void on_depa__query_p_clicked();
    void on_cls__query_p_clicked();

    void on_del_p_clicked();

    void on_tabWidget_destroyed();

    void on_tableWidget_cellChanged(int row, int column);

  private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
