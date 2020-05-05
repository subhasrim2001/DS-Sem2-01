#include <iostream>

using namespace std;

void printArr(int arr[])
{
    int i;
    for(i=1; i<=arr[0]; i++)
    {
        cout<<arr[i];
    }
}

Node* getNode(char d, int f)
{
    Node *cur = new Node;
    cur->left = NULL;
    cur->right = NULL;
    cur->data = d;
    cur->frequency = f;
    return cur;
}
void swapNodesOfMinHeap(Node* &t1, Node* &t2)
{
    Node *t=t1;
    t1=t2;
    t2=t;
}
void minHeapify(MinHeap* minHeap, int index)
{
    int small = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(((left) < (minHeap->cur_size)) && ((minHeap->arr[left]->frequency) < (minHeap->arr[small]->frequency)))
    {
        small = left;
    }
    if(((right) < (minHeap->cur_size)) && ((minHeap->arr[right]->frequency) < (minHeap->arr[small]->frequency)))
    {
        small = right;
    }
    if(small!=index)
    {
        swapNodesOfMinHeap(minHeap->arr[small], minHeap->arr[index]);
        minHeapify(minHeap, small);
    }
}
void makeMinHeap(MinHeap* minHeap)
{
    int i;
    for(i = (minHeap->cur_size - 2)/2; i>=0; i--)
    {
        minHeapify(minHeap, i); //the standard minHeapify function
    }
}
MinHeap* constructMinHeap(int size)
{
    MinHeap *minHeap = new MinHeap;
    minHeap->cur_size = 0;
    minHeap->max_size = size;
    minHeap->arr = new Node*[minHeap->max_size];
    //may require allocation to each node

}
MinHeap* constructAndMakeMinHeap(char data[], int freq[], int size)
{
    int i;
    MinHeap* minHeap = constructMinHeap(size);
    for(i=0; i<size; i++)
    {
        minHeap->arr[i] = getNode(data[i], freq[i]);
    }
    minHeap->cur_size = size;
    makeMinHeap(minHeap);
    return minHeap;
}
bool HeapConstructed(MinHeap *minHeap)
{
    return (minHeap->cur_size==1);
}
Node* returnMinNode(MinHeap *minHeap)
{
    Node *min = minHeap->arr[0];
    minHeap->arr[0]=minHeap->arr[minHeap->cur_size - 1];
    minHeap->cur_size=minHeap->cur_size - 1;
    minHeapify(minHeap, 0);
    return min;
}
void insertMinHeap(MinHeap *minHeap, Node *cur)
{
    int i = minHeap->cur_size;
    minHeap->cur_size = minHeap->cur_size + 1;
    while(i && cur->frequency < minHeap->arr[(i-1)/2]->frequency)
    {
        minHeap->arr[i] = minHeap->arr[(i-1)/2];
        i = (i-1)/2;
    }
    minHeap->arr[i] = cur;
}
Node* makeHuffmanTree(char data[], int freq[], int size)
{
    Node *left, *right, *parent;
    MinHeap* minHeap = constructAndMakeMinHeap(data, freq, size); //make a min-heap
    while(!HeapConstructed)
    {
        left = returnMinNode(minHeap);
        right = returnMinNode(minHeap);
        parent = getNode('#', left->frequency+right->frequency);
        parent->left = left;
        parent->right = right;
        insertMinHeap(minHeap, parent);
    }
    return returnMinNode(minHeap);
}
int maxHeight(Node* cur)
{
    if(cur==NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = maxHeight(cur->left);
        int rightHeight = maxHeight(cur->right);
        if(leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}
bool isLeafNode(Node *root)
{
    return (!((root->left) || (root->right)));
}
void storeCodes(Node *root, int arr[], int index)
{
    if(root->left)
    {
        arr[index] = 0;
        storeCodes(root->left, arr, index+1);
    }
    if(root->right)
    {
        arr[index] = 1;
        storeCodes(root->right, arr, index+1);
    }
    if(isLeafNode(root))
    {
        H.sendCode(root->data, arr, index);
    }
}
void HuffmanEncryption(char data[], int freq[], int size)
{
    int index=0;
    Node *root = makeHuffmanTree(data, freq, size);
    int height = maxHeight(root);
    int *arr = new int[height+1];
    H.set_size(size, height+1);
    storeCodes(root, arr, index);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
