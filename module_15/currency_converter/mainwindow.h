#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "conversioncalculator.h"
#include "mylineedit.h"
#include "qcombobox.h"
#include "qgridlayout.h"
#include "qlabel.h"
#include "qmessagebox.h"
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void currencyName_comboBox_currentIndexChanged(int index);
    void byn_myLineEdit_textChanged(const QString &arg);
    void byn_myLineEdit_focussed(bool hasFocus);
    void other_myLineEdit_textChanged(const QString &arg);
    void other_myLineEdit_focussed(bool hasFocus);

private:
    Ui::MainWindow *ui{};
    QNetworkAccessManager *manager{};    
    ConversionCalculator* cc{};
    QWidget *centralwidget{};
    QWidget *gridLayoutWidget{};
    QGridLayout *gridLayout{};
    MyLineEdit* byn_myLineEdit{};
    MyLineEdit *other_myLineEdit{};
    QLabel *label{};
    QComboBox *currencyName_comboBox{};
    QNetworkRequest request{};
    QMessageBox* messageBox{};
    bool _isBynFocussed{};
    bool _isOtherFocussed{};
};
#endif // MAINWINDOW_H
