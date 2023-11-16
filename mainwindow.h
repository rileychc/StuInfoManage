#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void on_cls_ar_accepted();
    void on_per_ar_accepted();
    void on_cla_ar_rejected();
    void on_depa_ar_accepted();
    void on_depa_ar_rejected();
    void on_per_ar_rejected();
    void on_chg_accepted();
    void on_chg_rejected();
    void on_rw_rejected();
    void on_rw_accepted();
    void on_pns_rejected();
    void on_pns_accepted();
    void on_stu_query_Button_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_demo_query_clicked();
    void on_stu_clapushButton_clicked();
    void on_rw_query_p_clicked();
    void on_pns_query_p_clicked();
    void on_depa_query_p_clicked();
    void on_cls_query_p_clicked();

  private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
