#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node
{
    Node* left;
    Node* right;
    char data;
    int freq;
public:
    Node(char, int);
    friend class Decryption;
};

#endif // NODE_H_INCLUDED
