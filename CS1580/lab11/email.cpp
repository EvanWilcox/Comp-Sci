//Name: Evan Wilcox     Date: 11/1/17
//Class: CS1580         Section: E
//Filename: email.cpp
//Desc: Implementation file for the email class

#include "email.h"

void email::writeEmail()
{
  char morse;

  cout << "What is the subject?: ";
  getline(cin, m_subject);
  cout << "Who is the message to?: ";
  getline(cin, m_reciever);
  cout << "What is the body?: ";
  getline(cin, m_body);
  cout << "Do you want your message in morse code?(y/n): ";
  cin >> morse;

  if(morse == 'y')
  {
    m_inMorse = true;
  }
  else 
  {
    m_inMorse = false;
  }
  return;
}

void email::printEmail()
{
  cout << "TO: " << m_reciever << endl;
  cout << "SUBJECT: " << m_subject << endl;

  if(m_inMorse)
  {
    translateBodyToMorse();
    cout << "BODY: " << m_body;
  }
  else
  {
    cout << "BODY: " << m_body << endl;
  }
  return;
}

void email::translateBodyToMorse() 
{
  string oldBody = m_body;
  m_body.clear();

  for(unsigned int i = 0;i < oldBody.length();i++)
  {
    char c = toupper(oldBody[i]);
    switch (c)
    {
      case 'A':
        m_body += ".- ";
        break;
      case 'B':
        m_body += "-... ";
      case 'C':
        m_body += "-.-. ";
        break;
      case 'D':
        m_body += "-.. ";
        break;
      case 'E':
        m_body += ". ";
        break;
      case 'F':
        m_body += "..-. ";
        break;
      case 'G':
        m_body += "--. ";
        break;
      case 'H':
        m_body += ".... ";
        break;
      case 'I':
        m_body += ".. ";
        break;
      case 'J':
        m_body += ".--- ";
        break;
      case 'K':
        m_body += "-.- ";
        break;
      case 'L':
        m_body += ".-.. ";
        break;
      case 'M':
        m_body += "-- ";
        break;
      case 'N':
        m_body += "-. ";
        break;
      case 'O':
        m_body += "--- ";
        break;
      case 'P':
        m_body += ".--. ";
        break;
      case 'Q':
        m_body += "--.- ";
        break;
      case 'R':
        m_body += ".-. ";
        break;
      case 'S':
        m_body += "... ";
        break;
      case 'T':
        m_body += "- ";
        break;
      case 'U':
        m_body += "..- ";
        break;
      case 'V':
        m_body += "...- ";
        break;
      case 'W':
        m_body += ".-- ";
        break;
      case 'X':
        m_body += "-..- ";
        break;
      case 'Y':
        m_body += "-.-- ";
        break;
      case 'Z':
        m_body += "--.. ";
        break;
    }
  }
  return;
}
