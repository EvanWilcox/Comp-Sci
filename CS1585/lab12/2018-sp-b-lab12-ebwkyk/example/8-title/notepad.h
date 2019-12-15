#pragma once

#include <QApplication>
#include <QFileDialog>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextStream>
#include <QToolBar>

class Notepad : public QMainWindow
{
  Q_OBJECT
  public:
    Notepad();
    virtual ~Notepad() {}

  signals:
    void useFile(QString fileName);

  private slots:
    void quit();
    void open();
    void save();
    void setTitle(QString fileName);
    void unsaved();

  private:
    QTextEdit* textEdit;
    QAction* quitAction;
    QAction* openAction;
    QAction* saveAction;

    QMenu* fileMenu;
    QToolBar* fileToolbar;
};
