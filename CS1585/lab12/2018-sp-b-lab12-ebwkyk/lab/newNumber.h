#pragma once // Same as #ifdef ... / #define ... / #endif
#include<QFrame>
#include<QHBoxLayout>
#include<QLineEdit>
#include<QPushButton>

/* A frame (set of widgets) that adds new phone numbers to the phonebook. */
class newNumber : public QFrame
{
  Q_OBJECT

  public:
    newNumber();

  signals:
    // TODO: Create a signal that sends a pointer to an entry when it is added
    void newEntry(Entry *e);

  private slots:
    void addPress();

  private:
    QLineEdit* nameEdit;
    QLineEdit* numberEdit;
    QPushButton* addButton;
};
