#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>

namespace Ui {
class Application;
}

class Application : public QMainWindow
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();

private:
    Ui::Application *ui;

private slots:

};

#endif // APPLICATION_H
