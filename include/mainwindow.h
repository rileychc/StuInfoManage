#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./ui_mainwindow.h"
#include "BaseCtl.h"
#include "Change.h"
#include "Class.h"
#include "Department.h"
#include "Punishment.h"
#include "Reward.h"
#include "Student.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <Qdebug>
#include <qlogging.h>
#include <stdio.h>
#include <string>

using namespace std;

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
    void update_slot(); // 更新操作,防止cellchanged信号一直被调用
    void base_query(BaseCtl *p); // 由查询摁钮信号调用的查询操作
    string single_query(string seleTg, BaseCtl *p, QTableWidgetItem *item,
                        bool b = true); // 当仅需要查询一个目标结果时

    ~MainWindow();

  private slots:
    // 不同库的提交和清除操作
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
    // 不同库的查询操作
    void on_stu_clapushButton_clicked();
    void on_stu_query_Button_clicked();
    void on_chg_query_p_clicked();
    void on_rw_query_p_clicked();
    void on_pns__query_p_clicked();
    void on_depa__query_p_clicked();
    void on_cls__query_p_clicked();

    void on_del_p_clicked(); // 对数据库进行删除操作

    void on_MainWindow_destroyed(QObject *arg1); // 窗口关闭时断开mysql链接
    void on_tableWidget_cellChanged(
        int row, int column); // 当单元格的数据被修改，则同步更新数据库

  private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
