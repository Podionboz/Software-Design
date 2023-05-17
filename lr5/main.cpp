#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

/* Напишіть програму, яка використовує <QTextStream> для зчитування даних з текстового файлу.
 * Програма повинна зчитувати кожен рядок з файлу та виводити його на екран консолі.*/
void task_1();
/* Напишіть програму, яка використовує <QTextStream> для запису даних у текстовий файл.
 * Програма повинна запитувати користувача про введення рядка тексту, та записувати цей рядок у файл.*/
void task_2();
/* Напишіть програму, яка використовує <QTextStream> для зчитування даних з консолі та виводу їх на екран.
 * Програма повинна чекати введення користувача та виводити введений рядок на екран.*/
void task_3();
/* Напишіть програму, яка використовує <QTextStream> для зчитування чисел з текстового файлу та знаходження їх середнього
 * арифметичного. Програма повинна зчитувати кожне число з файлу та додавати його до змінної, яка зберігає загальну суму чисел.
 * Після цього програма повинна обчислити середнє арифметичне за допомогою формули sum / n, де sum - загальна сума чисел,
 * а n - кількість чисел.*/
void task_4();
/* Напишіть програму, яка використовує <QTextStream> для зчитування даних з текстового файлу та запису даних у інший текстовий файл.
 * Програма повинна зчитувати кожен рядок з файлу та записувати його до нового файлу, при цьому замінюючи усі входження певного
 * слова на інше слово. Слова для заміни програма повинна запитувати у користувача*/
void task_5();

int main() {
    qDebug() << "Input variant [1-5]\n1. Read file\n2. Enter a string to the file\n3. Enter a string to the file and show\n4. Find averange\n5. Write in new file and replace all value what entered user";
    QTextStream s(stdin);
    QString variant = s.readLine();

    if (variant == '1') {
        task_1();
        return 0;
    }
    else if (variant == '2') {
        task_2();
        return 0;
    }
    else if (variant == '3') {
        task_3();
        return 0;
    }
    else if (variant == '4') {
        task_4();
        return 0;
    }
    else if (variant == '5') {
        task_5();
        return 0;
    }
    else {
        qDebug() << "Error (press ENTER to close app)";
        return 1;
    }
}

void task_1() {
    QFile file("C:/Users/rodio/work/DSTU/2c.,4s/OOP/lr5/app/lr5/resourses/task_1.txt");
    QTextStream in(&file);

    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        qDebug() << "File not exists or corrupt (press ENTER to close app)";
    }

    else {
        while(!in.atEnd()) {
            qDebug() << in.readLine();
        }
        qDebug() << "Press ENTER to close app";
    }
}

void task_2() {
    QFile file("C:/Users/rodio/work/DSTU/2c.,4s/OOP/lr5/app/lr5/resourses/task_2.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "File not exists or corrupt (press ENTER to close app)";
    }
    else {
        qDebug() << "Enter a string: ";
        QTextStream s(stdin);
        QString string = s.readLine();

        QTextStream out(&file);
        out << string;

        file.close();
        qDebug() << "Press ENTER to close app";
    }
}

void task_3() {
    QFile file("C:/Users/rodio/work/DSTU/2c.,4s/OOP/lr5/app/lr5/resourses/task_3.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "File not exists or corrupt (press ENTER to close app)";
    }
    else {
        qDebug() << "Enter a string: ";
        QTextStream s(stdin);
        QString string = s.readLine();

        QTextStream out(&file);
        out << string;
        file.close();
        qDebug() << "Result (press ENTER to close app): " << string;
    }
}

void task_4() {
    double sum = 0;
    int n = 0;
    QFile file("C:/Users/rodio/work/DSTU/2c.,4s/OOP/lr5/app/lr5/resourses/task_4.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File not exists or corrupt (press ENTER to close app)";
    }
    else {
        QTextStream in(&file);
        QString line;

        while (!in.atEnd()) {
            line = in.readLine();
            sum += line.toDouble();
            n++;
        }

        qDebug() << "Average (press ENTER to close app): " << sum / n;

        file.close();
    }
}

void task_5() {
    QFile onlyRead("C:/Users/rodio/work/DSTU/2c.,4s/OOP/lr5/app/lr5/resourses/task_5_onlyRead.txt");
    QFile onlyWrite("C:/Users/rodio/work/DSTU/2c.,4s/OOP/lr5/app/lr5/resourses/task_5_onlyWrite.txt");

    qDebug() << "What do you want to change? (Enter a value of string)";
    QTextStream s1(stdin);
    QString old_value = s1.readLine();

    qDebug() << "Enter a new value, please:";
    QTextStream s2(stdin);
    QString new_value = s2.readLine();

    if (!onlyRead.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File not exists or corrupt (press ENTER to close app)";
    }
    else if (!onlyWrite.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "File not exists or corrupt (press ENTER to close app)";
    }
    else {
        QTextStream in(&onlyRead);
        QTextStream out(&onlyWrite);
        QString line;
        while (!in.atEnd()) {
            line = in.readLine();
            if (line == old_value)
                out << new_value << '\n';
            else
                out << line << '\n';
        }
    }
}
