#include "Decryption.h"
#include "Node.h"
#include <iostream>

using namespace std;

Decryption :: Decryption(int num)
{
    root = NULL;
    this->num = num;
    int* freq = new int [num];
    char* chars = new char [num];
}


int Decryption :: input()
{
    int sum = 0;
    cout << "Please enter the characters and their respective frequencies" << endl;
    for(int i = 0; i <num; i++)
    {
        cin >> chars[i];
        cin >> freq[i];
        sum += freq[i];
    }
    return sum;
}

 int Decryption :: findMin1()
 {
     int min = 9999999;
     int i, j;
     for(i = 0; i < num; i++)
     {
         if(min > freq[i])
         {
             min = freq[i];
             j = i;
         }
     }
     return j;

 }

int Decryption :: findMin2(int index_1)
 {
     int min2 = 9999999;
     int i, j;
     for(i = 0; i < num; i++)
     {
         if(min2 > freq[i] && i != index_1)
         {
             min2 = freq[i];
             j = i;
         }
     }
     return j;

 }

void Decryption :: deleteIndex (int index)
 {
     for(int i = index; i < num-1; i++)
     {
         freq[i] = freq[i+1];
          chars[i] = chars[i+1];
     }
    num--;
 }

void Decryption :: decode(Node* root)
{
    if(num != 1)
    {
        if(root == NULL)
        {
            int index_1 = findMin1( );
            int index_2 = findMin2(index_1);
            int sum = freq[index_1] + freq[index_2];
            Node* lnode_1 = new Node (chars[index_1], freq[index_1]);
            Node* lnode_2 = new Node (chars[index_2], freq[index_2]);
            Node* node = new Node ('`', sum);
            node->left = lnode_1;
            node->right = lnode_2;
            root = node;
            deleteIndex(index_1 );
            deleteIndex(index_2 );
        }
        else
        {

        }

    }
    else
    {
        return;
    }
}
