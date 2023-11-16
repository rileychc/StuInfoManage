#ifndef CLS_QUERY_H
#define CLS_QUERY_H

#include <QWidget>

namespace Ui {
class cls_query;
}

class cls_query : public QWidget
{
    Q_OBJECT

  public:
    explicit cls_query(QWidget *parent = nullptr);
    ~cls_query();

  private slots:
    void on_tableWidget_entered(const QModelIndex &index);

  private:
    Ui::cls_query *ui;
};

#endif // CLS_QUERY_H
