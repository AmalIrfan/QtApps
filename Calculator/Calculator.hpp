#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <QApplication>
#include <QWidget>
#include <QToolButton>
#include <QGridLayout>
#include <QLineEdit>

class Calculator : public QWidget
{
Q_OBJECT

public:
 Calculator(QWidget *parent = nullptr);

private slots:
 void digitClicked();
 void plusClicked();
 void timesClicked();
 void equalsClicked();
 void clearClicked();

private:
 QLineEdit *display;
 int registerA;
 int registerB;
};

#endif // CALCULATOR_HPP
