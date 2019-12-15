#include "matrix_search.h"
#include <time.h>
#include <fstream>
using std::ofstream;

int main()
{
  // time tracking
  clock_t startTime = clock();
  
  short rows;
  short cols;
  short numMatrixes;
  string word;
  int sol[4];

  ofstream fout("output.txt");
  
  cout << "How many matrixes?: ";
  cin >> numMatrixes;

  for(int i = 0; i < numMatrixes; i++)
  {
    cout << endl << "Number of rows?: ";
    cin >> rows;
    
    cout << endl << "Number of columns?: ";
    cin >> cols;
    cout << endl;
    
    char **matrix = build_matrix(rows, cols);
    
    fill_matrix(rows, cols, matrix);
    print_matrix(rows, cols, matrix);
    cin >> word;
    matrix_search(sol, word, rows, cols, matrix);
    cout << "Searching for \"" << word << "\" in matrix " << (i+1) <<" yields:\n\r";
    fout << "Searching for \"" << word << "\" in matrix " << (i+1) <<" yields:\n\r";
    
    if(sol[0] == -1)
    {
      cout << "The pattern was not found.\n\r";
      fout << "The pattern was not found.\n\n\r";
    }
    else 
    {
      cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")\n\n";
      fout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")\n\n";
    }
    
    delete_matrix(rows, matrix);
  }

  // time tracking
  cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
  return 0;
}
