// Name: Evan Wilcox
// Class: CS3500


#include <iostream>
#include <string>
#include <regex>
using namespace std; 

void getToken();

bool isInteger();

bool isDecimal();

bool isString();

bool isKeyword();

bool isIdentifier();

bool isRelation();

bool isAddOperator();

bool isMulOperator();

void isExpression();

void isSimpleExpression();

void isTerm();

void isFactor();

void isAssignment();

void isPrintStatement();

void isRetStatement();

void isIfStatement();

void isWhileStatement();

void isStatement();

void isStatementSequence();

void isParamSequence();

void isFunctionDeclaration();

void isFunctionSequence();


string relations[4] = {"<", ">", "-", "#"};
string addOps[3] = {"+", "-", "OR"};
string mulOps[3] = {"*", "/", "AND"};
string keywords[25] = {":=", "+", "-", "*", "/", "OR", "AND", "~", "(", ")", "<", ">", "=", "#", ";", "PRINT", "IF", "ELSE", "ENDIF", "WHILE", "ENDW", "PROC", "RETURN",  "BEGIN", "END."};

string token;

int main()
{
  try
  {
    isFunctionSequence();
  }
  catch (string e)
  {
    cout << "INVALID!" << endl << e << endl;
  }

  return 0;
}





void getToken()
{
  cin >> token;
}

bool isInteger()
{
  return regex_match(token, regex("[+-]?[0-9]+"));
}

bool isDecimal()
{
  return regex_match(token, regex("[+-]?[0-9]+.[0-9]+"));
}

bool isString()
{
  return regex_match(token, regex("\".*\""));
}

bool isKeyword()
{
  bool b = false;

  for(int i = 0; i < 25; i++)
  {
    if(token == keywords[i])
    {
      b = true;
    }
  }

  return b;
}

bool isIdentifier()
{
  return regex_match(token, regex("[a-zA-Z][a-zA-Z0-9]*")) && !isKeyword();
}

bool isRelation()
{
  bool b = false;

  for(int i = 0; i < 4; i++)
  {
    if(token == relations[i])
    {
      b = true;
    }
  }

  return b;
}

bool isAddOperator()
{
  bool b = false;

  for(int i = 0; i < 3; i++)
  {
    if(token == addOps[i])
    {
      b = true;
    }
  }

  return b;
}

bool isMulOperator()
{
  bool b = false;

  for(int i = 0; i < 3; i++)
  {
    if(token == mulOps[i])
    {
      b = true;
    }
  }

  return b;
}

void isExpression()
{
  isSimpleExpression();
  
  if(isRelation())
  {
    getToken();
    isSimpleExpression();
  }
}

void isSimpleExpression()
{ 
  isTerm();

  while(isAddOperator())
  {
    getToken();
    isTerm();
  }
}

void isTerm()
{
  isFactor();

  while(isMulOperator())
  {
    getToken();
    isFactor();
  }
}
void isFactor()
{
  if(isInteger() || isDecimal() || isString() || isIdentifier())
  {
    getToken();
  }
  else if(token == "(")
  {
    getToken();
    isExpression();
    
    if(token == ")")
    {
      getToken();
    }
    else
    {
      throw string("Error: \')\' expected, got \"" + token + "\"");
    }
  }
  else if(token == "~")
  {
    getToken();
    isFactor();
  }
  else
  {
    throw string("Error: Factor expected, got \"" + token + "\"");
  }
}

void isAssignment()
{
  if(isIdentifier())
  {
    getToken();
    if(token == ":=")
    {
      getToken();
      isExpression();
    }
    else
    {
      throw string("Error: \':=\' expected, got \"" + token + "\"");
    }
  }
  else
  {
    throw string("Error: Identifier expected, got \"" + token + "\"");
  }
}

void isPrintStatement()
{
  if(token == "PRINT")
  {
    getToken();
    if(token == "(")
    {
      getToken();
      isExpression();
      
      if(token == ")")
      {
        getToken();
      }
      else
      {
        throw string("Error: \')\' expected, got \"" + token + "\"");
      }
    }
    else
    {
      throw string("Error: \'(\' expected, got \"" + token + "\"");
    }
  }
  else
  {
    throw string("Error: \'PRINT\' expected, got \"" + token + "\"");
  }
}

void isRetStatement()
{
  if(token == "RETURN")
  {
    getToken();
    if(isIdentifier())
    {
      getToken();
    }
    else
    {
      throw string("Error: Identifier expected, got \"" + token + "\"");
    }
  }
  else
  {
    throw string("Error: \'RETURN\' expected, got \"" + token + "\"");
  }
}

void isIfStatement()
{
  if(token == "IF")
  {
    getToken();
    if(token == "(")
    {
      getToken();
      isExpression();
      
      if(token == ")")
      {
        getToken();
        isStatementSequence();

        if(token == "ELSE")
        {
          getToken();
          isStatementSequence();
        }

        if(token == "ENDIF")
        {
          getToken();
        }
        else
        {
          throw string("Error: \'ENDIF\' expected, got \"" + token + "\"");
        }
      }
      else
      {
        throw string("Error: \')\' expected, got \"" + token + "\"");
      }
    }
    else
    {
      throw string("Error: \'(\' expected, got \"" + token + "\"");
    }
  }
  else
  {
    throw string("Error: \'IF\' expected, got \"" + token + "\"");
  }
}

void isWhileStatement()
{
  if(token == "WHILE")
  {
    getToken();
    if(token == "(")
    {
      getToken();
      isExpression();
      
      if(token == ")")
      {
        getToken();
        isStatementSequence();
        
        if(token == "ENDW")
        {
          getToken();
        }
        else
        {
          throw string("Error: \'ENDW\' expected, got \"" + token + "\"");
        }
      }
      else
      {
        throw string("Error: \')\' expected, got \"" + token + "\"");
      }
    }
    else
    {
      throw string("Error: \'(\' expected, got \"" + token + "\"");
    }
  }
  else
  {
    throw string("Error: \'WHILE\' expected, got \"" + token + "\"");
  }
}

void isStatement()
{
  if(isIdentifier())
  {
    isAssignment();
  }
  else if(token == "PRINT")
  {
    isPrintStatement();
  }
  else if(token == "IF")
  {
    isIfStatement();
  }
  else if(token == "WHILE")
  {
    isWhileStatement();
  }
  else
  {
    throw string("Error: Statement expected, got \"" + token + "\"");
  }
}

void isStatementSequence()
{
  isStatement();

  while(token == ";")
  {
    getToken();
    isStatement();
  }
}

void isParamSequence()
{
  if(isIdentifier())
  {
    getToken();

    while(token == ",")
    {
      getToken();
      if(isIdentifier())
      {
        getToken();
      }
      else
      {
        throw string("Error: Identifier expected, got \"" + token + "\"");
      }
    }
  }
  else
  {
    throw string("Error: Identifier expected, got \"" + token + "\"");
  }
}

void isFunctionDeclaration()
{
  if(token == "PROC")
  {
    getToken();
    if(isIdentifier())
    {
      getToken();
      if(token == "(")
      {
        getToken();
        if(token != ")")
        {
          if(isIdentifier())
          {
            isParamSequence();
          }
          else
          {
            throw string("Error: Identifier expected, got \"" + token + "\"");
          }
        }

        if(token == ")")
        {
          getToken();
          if(token == "BEGIN")
          {
            getToken();
            isStatementSequence();
            
            if(token == "RETURN")
            {
              isRetStatement();
            }

            if(token == "END.")
            {
              getToken();
            }
            else
            {
              throw string("Error: \'END.\' expected, got \"" + token + "\"");
            }
          }
          else
          {
            throw string("Error: \'BEGIN\' expected, got \"" + token + "\"");
          }
        }
        else
        {
          throw string("Error: \')\' expected, got \"" + token + "\"");
        }
      }
      else
      {
        throw string("Error: \'(\' expected, got \"" + token + "\"");
      }
    }
    else
    {
      throw string("Error: Identifier expected, got \"" + token + "\"");
    }
  }
  else
  {
    throw string("Error: Function declaration expected, got \"" + token + "\"");
  }
}

void isFunctionSequence()
{
  getToken();
  isFunctionDeclaration();

  while(token == "PROC")
  {
    isFunctionDeclaration();
  }

  cout << "CORRECT" << endl;
}

