#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 QPushButton button;
 button.setText("Ich leib Informatik!");
 button.setToolTip("I love Computer Science!");

 QFont font ("Ubuntu");
 button.setFont(font);
 button.show();

 return app.exec();
}
