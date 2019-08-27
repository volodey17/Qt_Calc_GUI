#ifndef CALCMAINWINDOW_H
#define CALCMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class CalcMainWindow;
}

class CalcMainWindow : public QMainWindow //CalcMainWindow унаследуем от QmainWindow
{   //Это одно из требований для участия в сигнально-слотовом взаимодействии
    Q_OBJECT // - макрос, который будет обработан метаобъектным компилятором moc

public:
    //Явный конструктор - предотвращает неявное преобразование типов при инициализации
    explicit CalcMainWindow(QWidget *parent = nullptr);
    ~CalcMainWindow();

private:
    Ui::CalcMainWindow *ptrUi; //через этот указатель будем обращаться к элементам UI
    double mNextNumber1;
    double mNextNumber2;
    char OperationSumbol; // Символ операции над числами
    //посредник между объектами посылающими сигнал и слотом, который принимает параметр
    //изменяющийся в зависимости от объекта, который его выполнил.
    //QSignalMapper *mMapper ;
private slots:
    void slotClickedNumber();
};
#endif // CALCMAINWINDOW_H
