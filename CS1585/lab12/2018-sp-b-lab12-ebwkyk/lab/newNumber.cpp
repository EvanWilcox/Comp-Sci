#include"newNumber.h"

newNumber::newNumber()
{
  nameEdit = new QLineEdit;
  numberEdit = new QLineEdit;
  addButton = new QPushButton("Add Number");

  connect(addButton, SIGNAL(clicked()), this, SLOT(addPress()));

  QLayout* layout = new QHBoxLayout;
  layout->addWidget(nameEdit);
  layout->addWidget(numberEdit);
  layout->addWidget(addButton);

  setLayout(layout);
}

void newNumber::addPress()
{
  // TODO: emit a signal that sends a new entry to the address book
  // then empty the text boxes
  
  Entry *e = new Entry(nameEdit->text(), numberEdit->text());
  emit newEntry(e);

  nameEdit->setText("");
  numberEdit->setText("");
  
  

}
