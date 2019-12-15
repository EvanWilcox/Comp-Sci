#pragma once
#include"entry.h"
#include"newNumber.h"

#include<QFileDialog>
#include<QMainWindow>
#include<QMessageBox>
#include<QString>
#include<QTextStream>
#include<QVBoxLayout>

#include<vector>

using namespace std;

/* A phonebook app */
class PhoneBook : public QMainWindow
{
  Q_OBJECT

  public:
    PhoneBook();

  // TODO: create a slot for adding a new entry

  private slots:
    void save();
    void open();
    void quit();
    void newEntry();

  private:
    // Read over the list of entries and turn them to a string
    QString serialize();

    // Read in a string of data and replace the GUI data with it
    void deserialize(QString data);

    // List of phone number entries
    vector<Entry*> entries;

    QVBoxLayout* layout;
    newNumber* newnum;

    QAction* quitAction;
    QAction* openAction;
    QAction* saveAction;
    QMenu* fileMenu;

    bool modified; // TODO: set this to 'true' whenever a new entry is added
};
