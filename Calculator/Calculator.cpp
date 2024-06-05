#include <QApplication>
#include <QPushButton>
#include "Calculator.hpp"

Calculator::Calculator(QWidget *parent)
 : QWidget(parent)
{
 setFixedSize(200, 50);
 m_button = new QPushButton("Calculator!", this);
}

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Calculator calculator;
 calculator.show();

 return app.exec();
}
