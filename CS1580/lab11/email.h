//Name: Evan Wilcox     Date: 11/1/17
//Class: CS1580         Section: E
//Filename: email.h
//Desc: header file for the email class

#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <string>
using namespace std;

class email
{
  private:
    string m_subject;
    string m_reciever;
    string m_body;
    bool m_inMorse;

  public:
    //Desc: Reads in the information of the email
    //Pre:  None
    //Post: Informatin is set
    void writeEmail();
    
    //Desc: prints email to screen
    //Pre:  None
    //Post: email is printed to screen
    void printEmail();
    
    //Desc: consverts m_body to morse code
    //Pre:  none
    //Post: m_body is converted to morse code
    void translateBodyToMorse();

};


#endif
