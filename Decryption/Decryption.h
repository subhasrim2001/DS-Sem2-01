#ifndef DECRYPTION_H_INCLUDED
#define DECRYPTION_H_INCLUDED
#include "Node.h"
#include <string>

using namespace std;

class Decryption
{
    Node* root;
    int *freq;
    char *chars;
    int num;
public:
    Decryption(int);
    int input();
    void decode(Node*);
    int findMin1();
    int findMin2(int);
    void deleteIndex(int);


};

#endif // DECRYPTION_H_INCLUDED
