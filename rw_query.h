#ifndef RW_QUERY_H
#define RW_QUERY_H

#include <QWidget>

namespace Ui {
class rw_query;
}

class rw_query : public QWidget
{
    Q_OBJECT

  public:
    explicit rw_query(QWidget *parent = nullptr);
    ~rw_query();

  private slots:
    void on_tableWidget_entered(const QModelIndex &index);

  private:
    Ui::rw_query *ui;
};

#endif // RW_QUERY_H
