#ifndef LR2_H
#define LR2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class lr2; }
QT_END_NAMESPACE

class lr2 : public QMainWindow
{
    Q_OBJECT

public:
    lr2(QWidget *parent = nullptr);
    ~lr2();

private slots:
    void on_radioButton1_clicked(bool checked);
    void on_radioButton2_clicked(bool checked);
    void on_radioButton3_clicked(bool checked);
    void on_radioButton4_clicked(bool checked);
    void on_radioButton5_clicked(bool checked);
    void on_radioButton6_clicked(bool checked);
    void on_actionForm_2_changed();
    void on_actionForm_1_triggered();
private:
    Ui::lr2 *ui;
};
#endif // LR2_H
