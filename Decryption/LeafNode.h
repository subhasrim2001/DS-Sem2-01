#ifndef LEAFNODE_H_INCLUDED
#define LEAFNODE_H_INCLUDED

class LeafNode
{
    char data;
    unsigned freq;
public:
    LeafNode(char, int);
    friend class Decryption;
};

#endif // LEAFNODE_H_INCLUDED
