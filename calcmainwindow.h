#ifndef CALCMAINWINDOW_H
#define CALCMAINWINDOW_H

#include <QWidget>
#include <QSignalMapper>

//Предварительное объвление классов
class QPushButton;
class QLabel;
class QSignalMapper ;
class CalcMainWindow : public QWidget
{
    Q_OBJECT // - макрос, который будет обработан метаобъектным компилятором moc
    //Это одно из требований для участия с сигнально-слотовом взаимодействии
public:
    CalcMainWindow(QWidget *parent = nullptr);
    ~CalcMainWindow();

private:
    //посредник между объектами посылающими сигнал и слотом, который принимает параметр
    //изменяющийся в зависимости от объекта, который его выполнил.
    QSignalMapper *mMapper ;

    //Отдельный метод для создания GUI
    void createWidgets();
    //Цифровые кнопки
    QPushButton *pushBut_1;
    QPushButton *pushBut_2;
    QPushButton *pushBut_3;
    QPushButton *pushBut_4;
    QPushButton *pushBut_5;
    QPushButton *pushBut_6;
    QPushButton *pushBut_7;
    QPushButton *pushBut_8;
    QPushButton *pushBut_9;
    QPushButton *pushBut_0;
    //+ - x /
    QPushButton *pushButAdd;
    QPushButton *pushButSub;
    QPushButton *pushButMul;
    QPushButton *pushButDiv;
    //кнопка вывода результата
    QPushButton *pushButRes;
    //кнопка сброса результата
    QPushButton *pushButC;
    //(должен быть QLCDNumber)виджет - цифровой дисплей
    QLabel *lcdNumber ;

private slots:
    void slotClear();   //Обработка нажатия кнопки сброса
    void slotButPress(int pNum); //Обработка нажатия цифр. кнопок
    void slotButAdd();
    void slotButSub();
    void slotButMul();
    void slotButDiv();
    void slotButRes(); //Обработка кнопки "результат"

private:
    double mNextNumber1;
    double mNextNumber2;
    char OperationSumbol; // Символ операции над числами
};
#endif // CALCMAINWINDOW_H
