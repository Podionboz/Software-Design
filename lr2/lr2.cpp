#include "lr2.h"
#include "ui_lr2.h"
#include "lr1.h"

#include <QMessageBox>

lr2::lr2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lr2)
{
    ui->setupUi(this);
}

lr2::~lr2()
{
    delete ui;
}

void lr2::on_radioButton1_clicked(bool checked) {
    if(checked) {
        ui->label->setStyleSheet("image: url(:/img/img/game.png)");
    }
}

void lr2::on_radioButton2_clicked(bool checked) {
    if(checked) {
        ui->label->setStyleSheet("image: url(:/img/img/book.png)");
    }
}

void lr2::on_radioButton3_clicked(bool checked) {
    if(checked) {
        ui->label->setStyleSheet("image: url(:/img/img/music.png)");
    }
}

void lr2::on_radioButton4_clicked(bool checked) {
    if(checked) {
        ui->label->setStyleSheet("image: url(:/img/img/film.png)");
    }
}

void lr2::on_radioButton5_clicked(bool checked) {
    if(checked) {
        ui->label_2->setStyleSheet("background-color: rgb(219, 245, 214);");
    }
}

void lr2::on_radioButton6_clicked(bool checked) {
    if(checked) {
        ui->label_2->setStyleSheet(" ");
    }
}

void lr2::on_actionForm_2_changed() {

}

void lr2::on_actionForm_1_triggered() {
    /*
     * для того, щоб при обранні певного пункту меню відкривати іншу форму:
     * 1. створити у проєкті новий елемент - правою кнопкою миші на назву проєкту, далі "Добавить новый...". У вікні, яке з'явилося обрати розділ Qt, а справа обрати "Класс формы Qt Designer". Далі у новому вікну обрати шаблон. Зверніть увагу! Необхідно обрати будь-який варіант саме діалогового вінка, наприклад, якщо потрібне порожнє, то "Dialog without Buttons".
     * 2. підключити у cpp файлі головної форми (де меню) заголовочний файл створенної форми #include "dialog.h"
     * 3. створити обробку події кліку на пункт меню (у режимі дизайну обрати пункт меню, правою кнопкою миші, "Перейти к слоту...". Обрати подію triggered
     * 4. створити екземпляр класу створеної форми
     * 5. вказати влкастивість модального вікна setModal(true)
     * 6. вказати метод відображення цього вікна, цієї форми exec()
    */
    lr1 w;
    w.setModal(true);
    w.exec();
}
