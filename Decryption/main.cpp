#include <iostream>
#include "LeafNode.h"
#include "Node.h"
#include "Decryption.h"

using namespace std;


int main()
{
    string code[1024] = {"0"};
    int i, j, k;
    cout << "Please enter the number of characters: ";
    int num;
    cin >> num;
    int* freq = new int [num];
    char* chars = new char [num];

    Decryption obj(num);
    int sum = obj.input();

    /*cout << "Please enter the code" << endl;
    for(i = 0; i<sum; i++)
    {
            cin >> code[i];
    }*/
    obj.decode(obj.root);
    return 0;
}
