#include"phonebook.h"

PhoneBook::PhoneBook()
{
  // Set Up Layout
  newnum = new newNumber;

  layout = new QVBoxLayout;
  layout->addWidget(newnum);

  QWidget* main = new QWidget;
  main->setLayout(layout);
  setCentralWidget(main);

  // TODO: Set up actions and file menu

  modified = false;
}

void PhoneBook::save()
{
  QString fileName = QFileDialog::getSaveFileName(
      this, // Parent
      "Save File", // Dialog Title
      "", // Directory
      "All Files (*)" // File Type Filters
    );

  if(fileName != "")
  {
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
      QMessageBox::critical(
          this, // Parent
          "Error", // Dialog Title
          "Could not write to file" // Dialog Text
        );
    }
    else
    {
      QTextStream out(&file);
      // TODO: Write data out (as you would to an ofstream)
      file.close();
    }
  }
}

void PhoneBook::open()
{
  QString fileName = QFileDialog::getOpenFileName(
      this, // Parent
      "Open File", // Dialog Title
      "", // Directory
      "All Files (*)" // File Type Filters
    );

  if(fileName != "")
  {
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
      QMessageBox::critical(
          this, // Parent
          "Error", // Dialog Title
          "Could not open file" // Dialog Text
        );
    }
    else
    {
      QTextStream in(&file);
      // TODO: Read data in (readAll() returns a QString with all text)
      file.close();
    }
  }
}

void PhoneBook::quit()
{
  // TODO: Prompt to quit if there is unsaved data
}

QString PhoneBook::serialize()
{
  QString data = "";
  for(unsigned int i = 0; i < entries.size(); i++)
  {
    Entry* e = entries[i];
    data.append(e->getName() + ";" + e->getNumber() + "\n");
  }

  return data;
}

void PhoneBook::deserialize(QString data)
{
  // Clear all the phone numbers
  for(unsigned int i = 0; i < entries.size(); i++)
  {
    layout->removeWidget(entries[i]);
    delete entries[i];
  }
  entries.clear();

  QStringList split = data.split("\n",QString::SkipEmptyParts);
  for(int i = 0; i < split.size(); i++)
  {
    QStringList vals = split[i].split(";");

    QString name = vals[0];
    QString number = vals[1];

    // TODO: Do something with the names and numbers
  }
}
