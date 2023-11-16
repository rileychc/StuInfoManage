#ifndef PNS_QUERY_H
#define PNS_QUERY_H

#include <QWidget>

namespace Ui {
class pns_query;
}

class pns_query : public QWidget
{
    Q_OBJECT

  public:
    explicit pns_query(QWidget *parent = nullptr);
    ~pns_query();

  private slots:
    void on_tableWidget_entered(const QModelIndex &index);

  private:
    Ui::pns_query *ui;
};

#endif // PNS_QUERY_H
