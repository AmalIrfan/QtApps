#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>

class QPushButton;
class Window : public QWidget
{
 public:
  explicit Window(QWidget *parent = 0);
 private:
  QPushButton *m_button;
};

#endif // WINDOW_HPP
