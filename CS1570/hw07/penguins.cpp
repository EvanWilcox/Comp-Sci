//Name: EVAN WILCOX       Date: 10/20/17
//Class: CS1570           Section: B
//Filename: penguins.cpp
//Desc: 

#include "penguins.h"

int main()
{
  srand(time(NULL));
  
  Penguin penguins[NUM_PENGUINS];
  randomize_penguins(penguins);
  cout << "======Initial Data Set.======" << endl;
  print_penguins(penguins);


  //creating wingSpan index 
  int wingSpan_index[NUM_PENGUINS];
  create_index(wingSpan_index);

  //creating array of penguins wingSpans 
  int wingSpans[NUM_PENGUINS];
  get_wingSpan_array(penguins, wingSpans);

  cout << endl;
  
  //sorts wingSpan_index[] smallest to biggest based on wingSpans[] values
  sort(wingSpans, wingSpan_index);

  cout << "======Top half sorted by wing span.======" << endl;
  print_penguins(penguins, wingSpan_index, NUM_PENGUINS/2);


  //creating neuroticism index
  int neuroticism_index[NUM_PENGUINS];
  create_index(neuroticism_index);

  //creating array of penguins neuroticism level
  float neuroticism[NUM_PENGUINS];
  get_neuroticism_array(penguins, neuroticism);
  
  //sorts neuroticism_index[] smallest to biggest based on wingSpans[] values
  sort(neuroticism, neuroticism_index);

  cout << endl;

  int neuroticismCategories[NUM_CATEGORIES][NUM_PENGUINS];
  
  int cat0Counter = 0;
  int cat1Counter = 0;
  int cat2Counter = 0;
  int cat3Counter = 0;
  
  for(int i = NUM_PENGUINS-1; i >= 0;i--)
  {
    if(neuroticism[i] >= CATEGORY0_MIN && neuroticism[i] < CATEGORY0_MAX)
    {
      neuroticismCategories[CATEGORY0][cat0Counter] = neuroticism_index[i];
      cat0Counter++;
    }
    else if(neuroticism[i] >= CATEGORY1_MIN && neuroticism[i] < CATEGORY1_MAX)
    {
      neuroticismCategories[CATEGORY1][cat1Counter] = neuroticism_index[i];
      cat1Counter++;
    }
    else if(neuroticism[i] >= CATEGORY2_MIN && neuroticism[i] < CATEGORY2_MAX)
    {
      neuroticismCategories[CATEGORY2][cat2Counter] = neuroticism_index[i];
      cat2Counter++;
    }
    else if(neuroticism[i] >= CATEGORY3_MIN && neuroticism[i] <= CATEGORY3_MAX)
    {
      neuroticismCategories[CATEGORY3][cat3Counter] = neuroticism_index[i];
      cat3Counter++;
    }
  }

  cout << "=====Penguins with greatest Neuroticism.=====" << endl;
  for(int i = 0;i < cat3Counter;i++)
  {
    print_penguin(penguins[neuroticismCategories[CATEGORY3][i]]);
  }
  
  Penguin breeders[NUM_PENGUINS];

  int numBreeders = 0;

  for(int i = NUM_PENGUINS-1; i >= NUM_PENGUINS - MAX_NUM_BREEDERS;i--)
  {
    if(penguins[wingSpan_index[i]].m_personality.m_neuroticism < CATEGORY0_MAX)
    {
      breeders[numBreeders] = penguins[wingSpan_index[i]];
      numBreeders++;
    }
  }
  

  //Prints superbreeders and super penguin if any
  if(numBreeders)
  {
    cout << endl << "=====Super Breeders=====" << endl;
    print_penguins(breeders, numBreeders);
    
    cout << endl << "=====Super Penguin=====" << endl;
    print_penguin(get_superPenguin(breeders, numBreeders));
    
  }
  else 
  {
    cout << endl << "PENGUIN EUGENICS WILL FAIL:  THE WORLD IS SAFE!" << endl;
  }
 
  return 0;
}
