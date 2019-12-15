// std:: version

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

// Your include files here
using std::cout;
using std::endl;


// This file is merely a rough guideline,
// and you should make your own for testing.
int main()
{
    // Heap
    std::priority_queue<int> q;

    cout << q.size() << endl;

    for(int k = 0; k < 10; k++)
        q.push(k);

    cout << q.size() << endl;

    while(!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }

    std::vector<int> my_array = {4, 6, 9, 12, 124, 4};
    std::priority_queue<int> q2(my_array.begin(), my_array.end());    // parameterized constructor

    std::priority_queue<int> q3(q2);             // copy constructor
    std::priority_queue<int> q4 = q2;            // copy constructor
    std::priority_queue<int> q5;                 // default constructor
    q5 = q4;                        // operator=

    while(!q4.empty())
    {
        cout << q4.top() << endl;
        q4.pop();
    }

    // Sort
    std::vector<int> my_array2 = {4, 6, 9, 12, 124, 4};

    cout << std::is_sorted(my_array2.begin(), my_array2.end()) << endl;
    std::sort(my_array2.begin(), my_array2.end());
    cout << std::is_sorted(my_array2.begin(), my_array2.end()) << endl;

    for(int k; k < 6; k++)
    {
        cout << my_array2[k] << endl;
    }

    return 0;
}

