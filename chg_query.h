#ifndef CHG_QUERY_H
#define CHG_QUERY_H

#include <QWidget>

namespace Ui {
class chg_query;
}

class chg_query : public QWidget
{
    Q_OBJECT

  public:
    explicit chg_query(QWidget *parent = nullptr);
    ~chg_query();

  private slots:
    void on_tableWidget_entered(const QModelIndex &index);

  private:
    Ui::chg_query *ui;
};

#endif // CHG_QUERY_H
