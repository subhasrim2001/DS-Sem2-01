#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
    char resident;
    char inner_text;
    Node* link;
public:
    Node(char);
    friend class List;
};

Node :: Node (char resident)
{
    this->resident = resident;
    inner_text = '`';
    link = NULL;
}


class List
{
    Node* head;
public:
    List();
    void insertEnd(char);
    void display();
};

List :: List ()
{
    head = NULL;
}

void List :: insertEnd(char resident)
{
    Node* node = new Node (resident);
    node->link = head;
    if(head == NULL)
    {
        head = node;
        node->link = head;
    }
    else
    {
        Node* temp = head;
        while(temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = node;

    }
}

void List::display() {
        if(head == NULL )
        {
                cout << "The list is empty" << endl;
        }
        else
        {
               Node* temp = head;
                while(true)
                {
                        cout << temp->resident << "->";
                        if(temp->link == head)
                                break;
                        temp = temp->link;
                }
                cout << "Head" << endl;
        }
}

class Encryption
{
    List list;
public:
    void encrypt(char*, char);
};

int main()
{
    string input;
    cout << "Please enter the input:" << endl;
    cin >> input;

    char keyword;
    cout << "Please enter the keyword: ";
    cin >> keyword;
    Encryption obj;
    //obj.encrypt(, keyword);


    int input_length = input.length();

    // declaring character array
    char char_array[input_length + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, input.c_str());

    for (int i = 0; i < input_length; i++)
        cout << char_array[i];
    cout << "keyword: " << keyword;
    return 0;
}
