/* main and it's supporting extras
*/

#include "MyUnorderedMap.h"


int main()
{
  std::string my_id[2];
  get_identity(my_id);
  std::cout <<  my_id[0] << "-" << my_id[1] << std::endl;

  MyUnorderedMap<std::string, int> unordered_map_obj;

  unordered_map_obj.insert(MyPair<std::string, int>("aoeu", 2));

  unordered_map_obj.insert(MyPair<std::string, int>("evan", 4));
  unordered_map_obj.insert(MyPair<std::string, int>("cat", 18));
  unordered_map_obj.insert(MyPair<std::string, int>("dog", 24));
  //unordered_map_obj.insert(MyPair<std::string, int>("kyle", 5));
  //unordered_map_obj.insert(MyPair<std::string, int>("lion", 6400));
  //unordered_map_obj.insert(MyPair<std::string, int>("elephant", 500));
  //unordered_map_obj.insert(MyPair<std::string, int>("panther", 1800000));
  //unordered_map_obj.insert(MyPair<std::string, int>("goat", 45));
  //unordered_map_obj.at("evan") = 1234;
  //unordered_map_obj["Andrew"] = 5678;
  unordered_map_obj.print();
  cout << unordered_map_obj.size() << endl;
  unordered_map_obj.erase("evan");
  cout << endl; 
  unordered_map_obj.print();
  cout << unordered_map_obj.size() << endl;
  cout << unordered_map_obj.find("nothing") << endl;

  unordered_map_obj["key5"] = 5;
  unordered_map_obj.at("key5") = 37;

  const MyPair<std::string, int> *temp = unordered_map_obj.find("key5");
  cout << temp->first << " " << temp->second << endl;

  cout << (unordered_map_obj.find("key5") == nullptr) << endl;
  unordered_map_obj.erase("key5");
  cout << (unordered_map_obj.find("key5") == nullptr) << endl;

  MyUnorderedMap<std::string, int> unordered_map_obj2(unordered_map_obj);

  MyUnorderedMap<std::string, int> unordered_map_obj3;
  unordered_map_obj3 = unordered_map_obj2 = unordered_map_obj; 

  unordered_map_obj2.print();
  cout << "Size is: " << unordered_map_obj2.size() << endl;
  cout << "Count for key3 is: " << unordered_map_obj2.count("key3") << endl << endl;

  //unordered_map_obj.clear();

  unordered_map_obj.print();

  cout << "Size is: " << unordered_map_obj.size() << endl;
  cout << "Count for key3 is: " << unordered_map_obj2.count("key3") << endl << endl;

  try
  {
    //unordered_map_obj.at("key5") = "k";
  }
  catch(const std::out_of_range &e)
  {
    cout << e.what();
  }

  return 0;
}

