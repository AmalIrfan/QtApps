#include "Calculator.hpp"

Calculator::Calculator(QWidget *parent)
 : QWidget(parent), registerA(0), registerB(0)
{
 QGridLayout *mainLayout = new QGridLayout;

 displayA = new QLineEdit("0");
 displayA->setReadOnly(true);
 displayA->setAlignment(Qt::AlignRight);
 displayA->setMaxLength(15);

 displayB = new QLineEdit("0");
 displayB->setReadOnly(true);
 displayB->setAlignment(Qt::AlignRight);
 displayB->setMaxLength(15);

 QFont font = displayA->font();
 font.setPointSize(font.pointSize() + 8);
 displayA->setFont(font);
 displayB->setFont(font);

 mainLayout->addWidget(displayA, 0, 0, 1, 4);
 mainLayout->addWidget(displayB, 1, 0, 1, 4);
 mainLayout->setSizeConstraint(QLayout::SetFixedSize);

 auto createButton = [](const std::string text, auto signal, auto obj, auto slot, int row, int col, auto layout)
 {
  QToolButton *button = new QToolButton;
  button->setFixedSize(50, 50);
  button->setText(text.c_str());
  connect(button, signal, obj, slot);
  layout->addWidget(button, row, col);
 };

 for (int i = 1; i <= 10; i++)
 {
  int row = (i-1) / 3 + 2;
  int col = (i-1) % 3;
  if (i == 10)
   i = 0;
 createButton(std::to_string(i), SIGNAL (clicked()), this, SLOT (digitClicked()), row, col, mainLayout);
  if (i == 0)
   break;
 }
 createButton("+", SIGNAL (clicked()), this, SLOT (plusClicked()), 2, 3, mainLayout);
 createButton("*", SIGNAL (clicked()), this, SLOT (timesClicked()), 3, 3, mainLayout);
 createButton("-", SIGNAL (clicked()), this, SLOT (minusClicked()), 4, 3, mainLayout);
 createButton("/", SIGNAL (clicked()), this, SLOT (dividesClicked()), 5, 3, mainLayout);
 createButton("C", SIGNAL (clicked()), this, SLOT (clearClicked()), 5, 2, mainLayout);
// createButton("=", SIGNAL (clicked()), this, SLOT (equalsClicked()), 5, 3, mainLayout);

 setLayout(mainLayout);
}

void Calculator::digitClicked()
{
 QToolButton *button = qobject_cast<QToolButton *>(sender());
 int digit = button->text().toInt();
 registerB = registerB * 10 + digit;
 displayB->setText(std::to_string(registerB).c_str());
}
void Calculator::plusClicked()
{
 registerA += registerB;
 registerB = 0;
 displayA->setText(std::to_string(registerA).c_str());
 displayB->setText(std::to_string(registerB).c_str());
}
void Calculator::minusClicked()
{
 registerA -= registerB;
 registerB = 0;
 displayA->setText(std::to_string(registerA).c_str());
 displayB->setText(std::to_string(registerB).c_str());
}
void Calculator::timesClicked()
{ 
 registerA *= registerB;
 registerB = 0;
 displayA->setText(std::to_string(registerA).c_str());
 displayB->setText(std::to_string(registerB).c_str());
}
void Calculator::dividesClicked()
{ 
 registerA /= registerB;
 registerB = 0;
 displayA->setText(std::to_string(registerA).c_str());
 displayB->setText(std::to_string(registerB).c_str());
}
void Calculator::equalsClicked()
{
 displayA->setText(std::to_string(registerA).c_str());
 displayB->setText(std::to_string(registerB).c_str());
}
void Calculator::clearClicked()
{
 registerA = 0;
 registerB = 0;
 displayA->setText(std::to_string(registerA).c_str());
 displayB->setText(std::to_string(registerB).c_str());
}

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Calculator calculator;
 calculator.show();

 return app.exec();
}
