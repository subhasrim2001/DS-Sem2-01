#include "Node.h"
#include <iostream>

using namespace std;

Node :: Node (char data, int freq)
{
    this->data = data;
    this->freq = freq;
    left = NULL;
    right = NULL;
}
