#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

class Notepad : public QWidget
{
  Q_OBJECT
  public:
    Notepad();
    virtual ~Notepad() {}

  private slots:
    void quit();

  private:
    QTextEdit* textEdit;
    QPushButton* quitButton;
};
