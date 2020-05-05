#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

Node* getNode(char d, int f)
{
    Node *cur = new Node;
    cur->left = NULL;
    cur->right = NULL;
    cur->data = d;
    cur->frequency = f;
    return cur;
}

#endif // NODE_H_INCLUDED
