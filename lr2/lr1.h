#ifndef LR1_H
#define LR1_H

#include <QDialog>

namespace Ui {
class lr1;
}

class lr1 : public QDialog
{
    Q_OBJECT

public:
    explicit lr1(QWidget *parent = nullptr);
    ~lr1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::lr1 *ui;
};

#endif // LR1_H
