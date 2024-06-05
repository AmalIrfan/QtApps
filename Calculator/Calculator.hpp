#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <QWidget>

class QPushButton;
class Calculator : public QWidget
{
 public:
  explicit Calculator(QWidget *parent = nullptr);
 private:
  QPushButton *m_button;
};

#endif // CALCULATOR_HPP
