#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    // void on_cla_com_but_2_clicked();

    // void on_cla_cle_but_2_clicked();

    // void on_depa_com_but_5_clicked();

    // void on_depa_cle_but_5_clicked();

    // void on_per_cle_but_clicked();

    // void on_per_com_but_clicked();

    // //    void on_tabWidget_tabBarClicked(int index);

    // void on_pushButton_clicked();

    // void on_chg_com_clicked();

    // void on_chg_cle_clicked();

    // void on_rw_cle_clicked();
    // void on_rw_com_clicked();

    // void on_pns_cle_clicked();

    // void on_pns_com_clicked();

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

  private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
