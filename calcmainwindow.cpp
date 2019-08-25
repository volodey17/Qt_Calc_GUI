//ЭТО файл реализации
// stop page is 370

#include "calcmainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QString>
#include <QDebug>

//конструктор
CalcMainWindow::CalcMainWindow(QWidget *parent)
    : QWidget(parent)
{
    resize(200, 300); // ширина х высота
    setWindowTitle("Калькулятор");
    createWidgets();
    connect(pushButC, SIGNAL(clicked()), this, SLOT(slotClear()), Qt::UniqueConnection);
    connect(pushButRes, SIGNAL(clicked()), this, SLOT(slotButRes()), Qt::UniqueConnection);
    connect(pushButAdd, SIGNAL(clicked()), this, SLOT(slotButAdd()), Qt::UniqueConnection);
    connect(pushButSub, SIGNAL(clicked()), this, SLOT(slotButSub()), Qt::UniqueConnection);
    connect(pushButMul, SIGNAL(clicked()), this, SLOT(slotButMul()), Qt::UniqueConnection);
    connect(pushButDiv, SIGNAL(clicked()), this, SLOT(slotButDiv()), Qt::UniqueConnection);

    //используем QSignalMapper для эффективного использования сигнально-слотовых соединений
    mMapper = new QSignalMapper(this);
    connect(pushBut_1, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushBut_2, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushBut_3, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushBut_4, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushBut_5, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushBut_6, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushBut_7, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushBut_8, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushBut_9, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    connect(pushBut_0, SIGNAL(clicked()), mMapper, SLOT(map()), Qt::UniqueConnection);
    mMapper->setMapping(pushBut_1, 1);
    mMapper->setMapping(pushBut_2, 2);
    mMapper->setMapping(pushBut_3, 3);
    mMapper->setMapping(pushBut_4, 4);
    mMapper->setMapping(pushBut_5, 5);
    mMapper->setMapping(pushBut_6, 6);
    mMapper->setMapping(pushBut_7, 7);
    mMapper->setMapping(pushBut_8, 8);
    mMapper->setMapping(pushBut_9, 9);
    mMapper->setMapping(pushBut_0, 0);
    slotClear();
    connect(mMapper, SIGNAL(mapped(int)), this, SLOT(slotButPress(int)), Qt::UniqueConnection);


}
//деструктор
CalcMainWindow::~CalcMainWindow(){}

//метод createWidgets() - ответственный за создание интерфейса программы-калькулятора
void CalcMainWindow::createWidgets()
{
    QGridLayout *_CalcLayout = new QGridLayout;
    setLayout(_CalcLayout);
    lcdNumber = new QLabel;
    pushBut_1 = new QPushButton("1");
    pushBut_2 = new QPushButton("2");
    pushBut_3 = new QPushButton("3");
    pushBut_4 = new QPushButton("4");
    pushBut_5 = new QPushButton("5");
    pushBut_6 = new QPushButton("6");
    pushBut_7 = new QPushButton("7");
    pushBut_8 = new QPushButton("8");
    pushBut_9 = new QPushButton("9");
    pushBut_0 = new QPushButton("0");
    pushButAdd = new QPushButton("+");
    pushButSub = new QPushButton("-");
    pushButMul = new QPushButton("*");
    pushButDiv = new QPushButton("/");
    pushButC = new QPushButton("C");
    pushButRes = new QPushButton("=");

    _CalcLayout->addWidget(lcdNumber, 0, 0, 1, 4);
    _CalcLayout->addWidget(pushButAdd, 1, 0);
    _CalcLayout->addWidget(pushButSub, 1, 1);
    _CalcLayout->addWidget(pushButMul, 1, 2);
    _CalcLayout->addWidget(pushButDiv, 1, 3);
    _CalcLayout->addWidget(pushBut_1, 2, 0);
    _CalcLayout->addWidget(pushBut_2, 2, 1);
    _CalcLayout->addWidget(pushBut_3, 2, 2);
    _CalcLayout->addWidget(pushButC, 2, 3);
    _CalcLayout->addWidget(pushBut_4, 3, 0);
    _CalcLayout->addWidget(pushBut_5, 3, 1);
    _CalcLayout->addWidget(pushBut_6, 3, 2);
    _CalcLayout->addWidget(pushBut_7, 4, 0);
    _CalcLayout->addWidget(pushBut_8, 4, 1);
    _CalcLayout->addWidget(pushBut_9, 4, 2);
    _CalcLayout->addWidget(pushBut_0, 5, 0, 1, 3);
    _CalcLayout->addWidget(pushButRes, 3, 3, 3, 1);

    //Задаем политики размера для кнопок: ГОР и ВЕРТ изменеие размера
    pushBut_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushBut_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushBut_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushBut_4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushBut_5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushBut_6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushBut_7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushBut_8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushBut_9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushBut_0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButAdd->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButSub->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButMul->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButDiv->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButC->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButRes->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    lcdNumber->setFixedHeight(50);
    lcdNumber->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QFont _lcdFont("Courier", 16);
    lcdNumber->setFont(_lcdFont);
}

//реализация слотов
void CalcMainWindow::slotClear()
{
    qDebug("slotClear");
    lcdNumber->setText("(Slot Clear) - 0");
    mSum = 0;
    mNextNumber = 0;
}
void CalcMainWindow::slotButPress(int pNum)
{
    qDebug("slotButPress");
    mNextNumber = mNextNumber*10 + pNum;
    QString bufText = QString::number(mNextNumber);
    lcdNumber->setText(bufText);
}
void CalcMainWindow::slotButAdd()
{
    qDebug("slotButAdd");
}
void CalcMainWindow::slotButSub()
{
    qDebug("slotButSub");
}
void CalcMainWindow::slotButMul()
{
    qDebug("slotButMul");
}
void CalcMainWindow::slotButDiv()
{
    qDebug("slotButDiv");
}
void CalcMainWindow::slotButRes()
{
    qDebug("slotRes");
    mSum += mNextNumber;
    QString bufText = QString::number(mSum);
    lcdNumber->setText(bufText);
    mNextNumber = 0;
}
