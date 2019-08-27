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

    bufNumber = (ptrUi->DisplayLabel->text() + bufButton->text()).toDouble();
    bufLabel = QString::number(bufNumber, 'g', 15);

    ptrUi->DisplayLabel->setText(bufLabel);
}
//void CalcMainWindow::slotClear()
//{
//    qDebug("slotClear");
//    lcdNumber->display("0");
//    mNextNumber1 = 0;
//    mNextNumber2 = 0;
//    OperationSumbol = NULL;
//}
//void CalcMainWindow::slotButPress(int pNum)
//{
//    qDebug("slotButPress");
//    QString bufText;

//    if (!OperationSumbol) {
//        mNextNumber1 = mNextNumber1*10 + pNum;
//        bufText = QString::number(mNextNumber1);}
//    else {
//        mNextNumber2 = mNextNumber2*10 + pNum;
//        bufText = QString::number(mNextNumber2);}

//    pointUi->DisplayLabel->setText(bufText);
//}
//void CalcMainWindow::slotButAdd()
//{
//    qDebug("slotButAdd");
//    if (OperationSumbol)
//        slotButRes();
//    OperationSumbol = '+';
//}
//void CalcMainWindow::slotButSub()
//{
//    qDebug("slotButSub");
//    if (OperationSumbol)
//        slotButRes();
//    OperationSumbol = '-';
//}
//void CalcMainWindow::slotButMul()
//{
//    qDebug("slotButMul");
//    if (OperationSumbol)
//        slotButRes();
//    OperationSumbol = '*';
//}
//void CalcMainWindow::slotButDiv()
//{
//    qDebug("slotButDiv");
//    if (OperationSumbol)
//        slotButRes();
//    OperationSumbol = '/';
//}
//void CalcMainWindow::slotButRes()
//{
//    qDebug("slotButRes");
//    switch (OperationSumbol) {
//    case '+': mNextNumber1 = mNextNumber1 + mNextNumber2; break;
//    case '-': mNextNumber1 = mNextNumber1 - mNextNumber2; break;
//    case '*': mNextNumber1 = mNextNumber1 * mNextNumber2; break;
//    case '/': mNextNumber1 = mNextNumber1 / mNextNumber2; break;
//    }

//    QString bufText = QString::number(mNextNumber1);
//    lcdNumber->display(bufText);
//    //mNextNumber1 = 0;
//    mNextNumber2 = 0;
//    OperationSumbol = NULL;
//}
