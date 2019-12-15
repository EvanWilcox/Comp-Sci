#include "matrix_search.h"


void get_identity(string my_id[])
{
  my_id[0] = "ebwkyk";
  my_id[1] = "12540849";
}

char ** build_matrix(int rows, int cols)
{
  // Allocate memory for rows
  char **arr = new char *[rows];

  // Allocate memory for collumns
  for(int i = 0; i < rows; i++)
  {
    arr[i] = new char[cols];
  }

  return arr;
}


void fill_matrix(int rows, int cols, char **matrix)
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      cin >> matrix[i][j];
    }
  }
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
  string wordReverse = word;
  string guess = "";
  short len = word.length();
  bool wordFound = false;
  char swap;

  for(int i = 0; i < len/2; i++)
  {
    swap = wordReverse[i];
    wordReverse[i] = wordReverse[len-i-1];
    wordReverse[len-i-1] = swap;
  }

  if(!wordFound)
  {
    // check horizontaly
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j <= cols - len; j++)
      {
        guess = "";
        for(int k = 0; k < len; k++)
        {
          guess += matrix[i][j+k];
        }
        
        if(guess == word)
        {
          wordFound = true;
          sol[0] = i;
          sol[1] = j;
          sol[2] = i;
          sol[3] = j+len-1;
        }
        else if(guess == wordReverse)
        {
          wordFound = true;
          sol[0] = i;
          sol[1] = j+len-1;
          sol[2] = i;
          sol[3] = j;
        }
      }
    }
  }
  if(!wordFound)
  {
    // check vertically
    for(int i = 0; i <= rows - len; i++)
    {
      for(int j = 0; j < cols; j++)
      {
        guess = "";
        for(int k = 0; k < len; k++)
        {
          guess += matrix[i+k][j];
        }
        
        if(guess == word)
        {
          wordFound = true;
          sol[0] = i;
          sol[1] = j;
          sol[2] = i+len-1;
          sol[3] = j;
        }
        else if(guess == wordReverse)
        {
          wordFound = true;
          sol[0] = i+len-1;
          sol[1] = j;
          sol[2] = i;
          sol[3] = j;
        }
      }
    }
  }
  if(!wordFound)
  {
    // check diagonally \

    for(int i = 0; i <= rows - len; i++)
    {
      for(int j = 0; j <= cols - len; j++)
      {
        guess = "";
        for(int k = 0; k < len; k++)
        {
          guess += matrix[i+k][j+k];
        }
        
        if(guess == word)
        {
          wordFound = true;
          sol[0] = i;
          sol[1] = j;
          sol[2] = i+len-1;
          sol[3] = j+len-1;
        }
        else if(guess == wordReverse)
        {
          wordFound = true;
          sol[0] = i+len-1;
          sol[1] = j+len-1;
          sol[2] = i;
          sol[3] = j;
        }
      }
    }
  }
  if(!wordFound)
  {
    // check diagonally /
    for(int i = 0; i <= rows - len; i++)
    {
      for(int j = cols - 1; j > cols - len; j--)
      {
        guess = "";
        for(int k = 0; k < len; k++)
        {
          guess += matrix[i+k][j-k];
        }
        
        if(guess == word)
        {
          wordFound = true;
          sol[0] = i;
          sol[1] = j;
          sol[2] = i+len-1; 
          sol[3] = j-len+1; 
        }
        else if(guess == wordReverse)
        {
          wordFound = true;
          sol[0] = i+len-1; 
          sol[1] = j-len+1; 
          sol[2] = i;
          sol[3] = j;
        }
      }
    }
  }
  
  if(!wordFound)
  {
    sol[0] = -1;
    sol[1] = -1;
    sol[2] = -1;
    sol[3] = -1;
  }
}


void print_matrix(int rows, int cols, char **matrix)
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}


void delete_matrix(int rows, char **matrix)
{
  // Deallocate
  for(int i  = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
  matrix = NULL;
}
