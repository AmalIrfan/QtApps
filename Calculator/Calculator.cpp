#include "Calculator.hpp"

Calculator::Calculator(QWidget *parent)
 : QWidget(parent), registerA(0), registerB(0)
{
 QGridLayout *mainLayout = new QGridLayout;

 display = new QLineEdit("0");
 display->setReadOnly(true);
 display->setAlignment(Qt::AlignRight);
 display->setMaxLength(15);

 QFont font = display->font();
 font.setPointSize(font.pointSize() + 8);
 display->setFont(font);

 mainLayout->addWidget(display, 0, 0, 1, 4);
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
  int row = (i-1) / 3 + 1;
  int col = (i-1) % 3;
  if (i == 10)
   i = 0;
 createButton(std::to_string(i), SIGNAL (clicked()), this, SLOT (digitClicked()), row, col, mainLayout);
  if (i == 0)
   break;
 }
 createButton("+", SIGNAL (clicked()), this, SLOT (plusClicked()), 1, 3, mainLayout);
 createButton("=", SIGNAL (clicked()), this, SLOT (equalsClicked()), 4, 3, mainLayout);
 createButton("*", SIGNAL (clicked()), this, SLOT (timesClicked()), 2, 3, mainLayout);
 createButton("C", SIGNAL (clicked()), this, SLOT (clearClicked()), 3, 3, mainLayout);

 setLayout(mainLayout);
}

void Calculator::digitClicked()
{
 QToolButton *button = qobject_cast<QToolButton *>(sender());
 int digit = button->text().toInt();
 registerB = registerB * 10 + digit;
 display->setText(std::to_string(registerB).c_str());
}
void Calculator::plusClicked()
{
 registerA += registerB;
 registerB = 0;
 display->setText(std::to_string(registerB).c_str());
}
void Calculator::timesClicked()
{ 
 if (registerA == 0)
  registerA = 1;
 registerA *= registerB;
 registerB = 0;
 display->setText(std::to_string(registerB).c_str());
}
void Calculator::equalsClicked()
{
 display->setText(std::to_string(registerA).c_str());
}
void Calculator::clearClicked()
{
 registerA = 0;
 registerB = 0;
 display->setText(std::to_string(registerB).c_str());
}

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 Calculator calculator;
 calculator.show();

 return app.exec();
}
