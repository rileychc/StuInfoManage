#ifndef DEPAR_WD_H
#define DEPAR_WD_H

#include <QWidget>

namespace Ui {
class depar_wd;
}

class depar_wd : public QWidget
{
    Q_OBJECT

  public:
    explicit depar_wd(QWidget *parent = nullptr);
    ~depar_wd();

  private slots:
    void on_tableWidget_entered(const QModelIndex &index);

  private:
    Ui::depar_wd *ui;
};

#endif // DEPAR_WD_H
