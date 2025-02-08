#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylineedit.h"
#include "qtimer.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QValidator>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Currency Converter");
    this->setFixedSize(300,100);

    cc = new ConversionCalculator(this);

    messageBox = new QMessageBox(this);

    gridLayoutWidget = new QWidget(this);
    gridLayoutWidget->setObjectName("gridLayoutWidget");
    gridLayoutWidget->setGeometry(QRect(75, 5, 160, 80));

    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setObjectName("gridLayout");
    gridLayout->setContentsMargins(0, 0, 0, 0);

    label = new QLabel(gridLayoutWidget);
    label->setObjectName("label");
    label->setText("BYN");
    gridLayout->addWidget(label, 0, 1, 1, 1);

    currencyName_comboBox = new QComboBox(gridLayoutWidget);
    currencyName_comboBox->addItem(QString("USD"));
    currencyName_comboBox->addItem(QString("RUB"));
    currencyName_comboBox->addItem(QString("CNY"));
    currencyName_comboBox->setObjectName("currencyName_comboBox");
    gridLayout->addWidget(currencyName_comboBox, 1, 1, 1, 1);

    other_myLineEdit = new MyLineEdit(gridLayoutWidget);
    other_myLineEdit->setObjectName("other_myLineEdit");
    other_myLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    gridLayout->addWidget(other_myLineEdit, 1, 0, 1, 1);

    byn_myLineEdit = new MyLineEdit(gridLayoutWidget);
    byn_myLineEdit->setObjectName("byn_myLineEdit");
    byn_myLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    gridLayout->addWidget(byn_myLineEdit, 0, 0, 1, 1);

    connect(byn_myLineEdit,   &MyLineEdit::focussed, this, &MainWindow::byn_myLineEdit_focussed);
    connect(other_myLineEdit, &MyLineEdit::focussed, this, &MainWindow::other_myLineEdit_focussed);
    connect(byn_myLineEdit, &MyLineEdit::textChanged, this, &MainWindow::byn_myLineEdit_textChanged);
    connect(other_myLineEdit, &MyLineEdit::textChanged, this, &MainWindow::other_myLineEdit_textChanged);
    connect(currencyName_comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::currencyName_comboBox_currentIndexChanged);

    QRegularExpressionValidator* rxv = new QRegularExpressionValidator(QRegularExpression("[0-9]{1,9}[.]{0,1}[0-9]{1,9}"), this);
    byn_myLineEdit->setValidator(rxv);
    other_myLineEdit->setValidator(rxv);

    byn_myLineEdit->setText("0");
    other_myLineEdit->setText("0");

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished,
            this, [cc_val = cc, byn_myLineEdit_val = byn_myLineEdit, messageBox_val = messageBox](QNetworkReply *reply) {
                if (reply->error()) {
                    messageBox_val->critical(0,"Error",reply->errorString());
                    messageBox_val->setFixedSize(500,250);
                    return;
                }

                QString strReply = (QString)reply->readAll();
                QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
                QJsonObject jsonObject = jsonResponse.object();

                cc_val->setCurrencyScale(jsonObject["Cur_Scale"].toDouble());
                cc_val->setCurrencyRate(jsonObject["Cur_OfficialRate"].toDouble());

                cc_val->calculateByn();

                byn_myLineEdit_val->setText(QString::number(cc_val->getBynValue()));
            });

    request.setUrl(QUrl("https://api.nbrb.by/exrates/rates/431"));
    manager->get(request);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::currencyName_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        request.setUrl(QUrl("https://api.nbrb.by/exrates/rates/431"));
        manager->get(request);
        break;
    case 1:
        request.setUrl(QUrl("https://api.nbrb.by/exrates/rates/456"));
        manager->get(request);
        break;
    case 2:
        request.setUrl(QUrl("https://api.nbrb.by/exrates/rates/462"));
        manager->get(request);
        break;
    default:
        break;
    }
}

void MainWindow::byn_myLineEdit_textChanged(const QString &arg)
{
    cc->setBynValue(arg.toDouble());
    if(!_isOtherFocussed){
        cc->calculateOther();
        other_myLineEdit->setText(QString::number(cc->getOtherValue()));
    }
}

void MainWindow::byn_myLineEdit_focussed(bool hasFocus)
{
    if(hasFocus) {
        _isBynFocussed = true;
        QTimer::singleShot(100, byn_myLineEdit, &MyLineEdit::selectAll);
    } else {
        _isBynFocussed = false;
    }
}

void MainWindow::other_myLineEdit_textChanged(const QString &arg)
{    
    cc->setOtherValue(arg.toDouble());    
    if(!_isBynFocussed){
        cc->calculateByn();
        byn_myLineEdit->setText(QString::number(cc->getBynValue()));
    }
}

void MainWindow::other_myLineEdit_focussed(bool hasFocus)
{
    if(hasFocus) {
        _isOtherFocussed = true;
        QTimer::singleShot(100, other_myLineEdit, &MyLineEdit::selectAll);
    } else {
        _isOtherFocussed = false;
    }
}
