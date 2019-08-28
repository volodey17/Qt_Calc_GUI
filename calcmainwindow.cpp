//(!)Файл реализации
//ПЕРЕПИСАТЬ клавиши операций через QSignalMapper!!! (уменшит число слотов)
#include <calcmainwindow.h>
#include <ui_calcmainwindow.h>

#include <QPushButton>
#include <QString>
#include <QDebug>

CalcMainWindow::CalcMainWindow(QWidget *parent) :   //конструктор
    QMainWindow(parent),
    ptrUi (new Ui::CalcMainWindow)
{
    ptrUi->setupUi(this);

//Способ#1 - подключение сигнала к слоту через макрос (устаревший метод)
    connect(ptrUi->pushButton_0, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_1, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_2, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_3, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_4, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_5, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_6, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_7, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_8, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_9, SIGNAL(clicked()), this, SLOT(slotClickedNumber()), Qt::UniqueConnection);

    connect(ptrUi->pushButton_Dot, SIGNAL(clicked()), this, SLOT(slotClickedDot()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_Invers, SIGNAL(clicked()), this, SLOT(slotClickedOperation()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_Percent, SIGNAL(clicked()), this, SLOT(slotClickedOperation()), Qt::UniqueConnection);

    connect(ptrUi->pushButton_Add, SIGNAL(clicked()), this, SLOT(slotClickedMath()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_Sub, SIGNAL(clicked()), this, SLOT(slotClickedMath()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_Mul, SIGNAL(clicked()), this, SLOT(slotClickedMath()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_Div, SIGNAL(clicked()), this, SLOT(slotClickedMath()), Qt::UniqueConnection);

    connect(ptrUi->pushButton_Equal, SIGNAL(clicked()), this,SLOT(slotClickedEqual()), Qt::UniqueConnection);
    connect(ptrUi->pushButton_AC, SIGNAL(clicked()), this,SLOT(slotClickedAC()), Qt::UniqueConnection);

//    connect(pushButC, SIGNAL(clicked()), this, SLOT(slotClear()), Qt::UniqueConnection);

//Способ#2 - QSignalMapper привязывает некоторое значение к каждому сигналу и позволяет
// избежать чрезмерного дополнительного создания слотов или специализированных классов.
//    mMapper = new QSignalMapper(this);
//    connect(pushBut_1, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
//      ...
//    mMapper->setMapping(pushBut_1, 1);
//      ...
//    connect(mMapper, SIGNAL(mapped(int)), this, SLOT(slotButPress(int)), Qt::UniqueConnection);
//Способ#3 - Подключение сигнала к слоту на основе указателей:
//    connect(button, &QPushButton::clicked, this, &MainWindow::slotButton);

    ptrUi->pushButton_Add->setCheckable(true); //теперь на клавише можно взвести флаг.
    ptrUi->pushButton_Sub->setCheckable(true);
    ptrUi->pushButton_Mul->setCheckable(true);
    ptrUi->pushButton_Div->setCheckable(true);
}

CalcMainWindow::~CalcMainWindow()   //деструктор
{
    delete ptrUi;
}

//  Реализация слотов обработки событий.
void CalcMainWindow::slotClickedNumber()
{   //           (QPushButton *) sender() - устаревший способ кастования объектов С-style
    //static_cast<QPushButton*>(sender()) - современный способ.
    QPushButton *bufButton = static_cast<QPushButton *>(sender());
    double bufNumber;
    QString bufLabel;

    if (ptrUi->DisplayLabel->text().contains('.') && bufButton->text() == "0")
    {
        bufLabel = (ptrUi->DisplayLabel->text() + bufButton->text());
    } else
    {
        bufNumber = (ptrUi->DisplayLabel->text() + bufButton->text()).toDouble();
        bufLabel = QString::number(bufNumber, 'g', 15);
    }
    ptrUi->DisplayLabel->setText(bufLabel);
}

void CalcMainWindow::slotClickedDot()
{
    if (!(ptrUi->DisplayLabel->text().contains('.')))
        ptrUi->DisplayLabel->setText(ptrUi->DisplayLabel->text() + ".");
}

void CalcMainWindow::slotClickedOperation()
{
    QPushButton *bufButton = static_cast<QPushButton *>(sender());
    double bufNumber;
    QString bufLabel;

    if (bufButton->text() == "+/-")
    {
        bufNumber = ptrUi->DisplayLabel->text().toDouble();
        bufNumber = bufNumber * -1;
    } else if (bufButton->text() == "%") {
        bufNumber = ptrUi->DisplayLabel->text().toDouble();
        bufNumber = bufNumber * 0.01;
    }
    bufLabel = QString::number(bufNumber, 'g', 15);
    ptrUi->DisplayLabel->setText(bufLabel);
}

void CalcMainWindow::slotClickedMath()
{
     QPushButton *bufButton = static_cast<QPushButton *>(sender());
     numberFirst = ptrUi->DisplayLabel->text().toDouble();
     ptrUi->DisplayLabel->clear();

     bufButton->setChecked(true);
}

void CalcMainWindow::slotClickedEqual()
{
    double bufNumber = 0;
    QString bufLabel;
    numberSecond = ptrUi->DisplayLabel->text().toDouble();

    if(ptrUi->pushButton_Add->isChecked())
    {
        bufNumber = numberFirst + numberSecond;
        ptrUi->pushButton_Add->setChecked(false);
    } else if (ptrUi->pushButton_Sub->isChecked())
    {
        bufNumber = numberFirst - numberSecond;
        ptrUi->pushButton_Sub->setChecked(false);
    } else if (ptrUi->pushButton_Mul->isChecked())
    {
        bufNumber = numberFirst * numberSecond;
        ptrUi->pushButton_Mul->setChecked(false);
    } else if (ptrUi->pushButton_Div->isChecked())
    {   qDebug() << "Div";
        if (numberSecond == 0.0)
        {
            qDebug() << "==0!";
            bufNumber = 0;
        } else
        {
            qDebug() << "div_oper";
            bufNumber = numberFirst / numberSecond;
        }
        ptrUi->pushButton_Div->setChecked(false);
    }

    bufLabel = QString::number(bufNumber, 'g', 15);
    ptrUi->DisplayLabel->setText(bufLabel);
}

void CalcMainWindow::slotClickedAC()
{
    ptrUi->pushButton_Add->setChecked(false);
    ptrUi->pushButton_Sub->setChecked(false);
    ptrUi->pushButton_Mul->setChecked(false);
    ptrUi->pushButton_Div->setChecked(false);

    ptrUi->DisplayLabel->setText("0");
}
