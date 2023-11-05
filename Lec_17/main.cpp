#include <iostream>
using namespace std;
#include "BST.h"

int main()
{
    BST<int> tree;
    //cout << tree.FindIterative(8) << endl;
    cout << tree.FindUsingRecursion(8) << endl;
    tree.Add(25);
    tree.Add(20);
    tree.Add(36);
    tree.Add(10);
    tree.Add(22);
    tree.Add(30);
    tree.Add(40);
    tree.Add(5);
    tree.Add(12);
    tree.Add(28);
    tree.Add(38);
    tree.Add(48);
    tree.Add(1);
    tree.Add(8);
    tree.Add(15);
    tree.Add(45);
    tree.Add(50);
    //cout << tree.FindIterative(8) << endl;
    cout << tree.FindUsingRecursion(8) << endl;
    //cout << tree.FindIterative(-10) << endl;
    cout << tree.FindUsingRecursion(-10) << endl;
    tree.inOrderTraversal();
    return 0;
}