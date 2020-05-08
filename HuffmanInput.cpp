#include <iostream>
#include "HuffmanInput.h"

using namespace std;
void printArr(int []);
void HuffmanInput::set_size(int s, int h)
{
    int i;
    size=s;
    count=0;
    d=new char[size];
    code=new int*[size];
    for(i=0; i<size; i++)
    {
        code[i]=new int[h];
    }
}
HuffmanInput::~HuffmanInput()
{
    int i;
    size=0;
    count=0;
    delete d;
    for(i=0; i<size; i++)
    {
        delete [] code[i];
    }
    delete code;
}
HuffmanInput::HuffmanInput()
{
    code=NULL;
    d=NULL;
}
void HuffmanInput::sendCode(char ch, int p[], int s)
{
    int i;
    d[count]= ch;
    code[count][0]=s;
    for(i=1; i<=s; i++)
    {
        code[count][i]=p[i-1];
    }
    count++;
    if(count==size)
    {
        printCode();
    }
}
void HuffmanInput::printCode()
{
    int s=input.length();
    int i, j;
    for(i=0; i<s; i++)
    {
        for(j=0; j<size; j++)
        {
            if(input[i]==d[j])
            {
                printArr(code[j]);
                break;
            }
        }
    }
}
