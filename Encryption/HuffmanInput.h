#ifndef HUFFMANINPUT_H_INCLUDED
#define HUFFMANINPUT_H_INCLUDED

class HuffmanInput //To handle the Input Operations
{
    public:
    string input;
    int size; //total char present
    int count; //current values filled
    int **code;
    char *d;
    void set_size(int, int);
    void sendCode(char, int [], int );
    void printCode();
    HuffmanInput();
    ~HuffmanInput();
}H;

#endif // HUFFMANINPUT_H_INCLUDED
