#include <iostream>
using namespace std;
#include "ArrayList.h"
#include "linkedList.h"

int main()
{
    /* Array List */
    /*ArrayList<int> list(50);

    for (int i = 0; i < 50; i++)
    {
        list.Add(i);
    }

    try {
        //list.Insert(50, 2);
        cout << "index of element = " << list.FindByElement(1) << endl;
        cout << "element in this index = " << list.FindByIndex(0) << endl;

        for (int i = 0; i < list.getCurrentIndex(); i++)
        {
            cout << list[i] <<  " ";
        }

        //list.Delete(5);
        cout << endl;

        cout << "===========================================================" << endl;

        list.DeleteRange(11, 33);
        cout << "we removed items from index 11 to 33 " << endl;
        for (int i = 0; i < list.getCurrentIndex(); i++)
        {
            cout << list[i] <<  " ";
        }

        list.erase();

    } catch (invalid_argument& e){
        cout << e.what() << endl;
    } */

    /* Linked List */
    LinkedList <int> arr;
    LinkedList <int> arr1;

    for(int i=0; i < 11; i++) {
        arr.AddBack(i);
    }
    arr.PrintAll();

    for(int i=0; i <= 10; i++) {
        arr1.AddFront(i);
    }
    arr1.DeleteByIndex(5);
    arr1.PrintAll();

    return 0;
}