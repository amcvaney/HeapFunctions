// Min Heap 
// Abigayle McVaney


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;


//class for Min heap implementation
class minHeap
{
private:
    int size;//size of heap
    int capacity;//max size of heap
    vector<int>heap;//store elements as a vector

    //returns parents, left child, and right child
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i +2;}

public:
    minHeap(int capacity); //constructor
    void insert(int k); //inserting key into min heap
    int extractMin();//deletes root
    void heapify(int i); //recursively heapify a sub-tree
    void printHeap();
};



//sets the heap size and capacity
minHeap::minHeap(int capacity)
{
    size = 0;
    this->capacity = capacity;
    heap.resize(capacity);
}

//insert key into min heap
void minHeap::insert(int k)
{
    if(size == capacity)
    {
        cout<< "Min Heap Full" <<endl;
        return;
    }

    size++;//increase amount of elements in the heap
    
    //insert new key at end
    int i = size -1;
    heap[i] = k;

    //fixing tree, moving elements up until i >= parent or root
    while (i != 0 && heap[parent(i)] > heap[i])
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

//function to maintain structure
void minHeap::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    //find smallest element of the tree
    if((l < size) && (heap[l] < heap[smallest]))
    {
        smallest = l;
    }
    if((r < size) && (heap[r] < heap[smallest]))
    {
        smallest = r;
    }
    //if smallest of l or r, continue heapify
    if(smallest !=i)
    {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

//removes smallest number, root
int minHeap::extractMin()
{
    if(size == 0)
    {
        cout<<"Empty Heap"<< endl;
        return -1;
    }
    //checking if only one element
    else if(size == 1)
    {
        size --;
        return heap[0];
    }
    else
    {   //stroe root
        int root = heap[0];
        //maintain theap shape then order
        heap[0] = heap[size-1];
        size--;
        heapify(0);
        //return min element
        return root;
    }

}

//printing heap
void minHeap::printHeap()
{
    int power = 0;
    int value = 1;

    for(int i = 0; i< size; i++)
    {
        if(i == value)
        {
            cout<<endl;
            power += 1;
            value += (1 << power);
        }
        cout<< heap[i] << " ";
    }
    cout<< endl;
}



int main()
{
    //min heap elements
    int a[11] = {28, 12, 17, 5, 7, 22, 13, 12, 4, 11, 16};
    int n = 11;
    int choice;
    
    //declare heap with space for n elements
    minHeap heap(n);


    while(1)
    {
        //prints out menu options
        cout<<"1) Build and print heap"<< endl;
        cout<<"2) Delete and print heap"<< endl;
        cout<<"3) End program"<< endl;
        cin>> choice;

        switch(choice)
        {
            case 1://inserting array a[] into heap
                for(int i=0; i< n; i++)
                   {
                       cout<< "Inserting Element "<< i+1<< endl;
                       heap.insert(a[i]);
                       heap.printHeap();
                       cout<< endl;
                   }
                break;
                
            case 2://case for deleting and printing root
                heap.extractMin();
                cout<<endl;
                heap.printHeap();
                cout<<endl;
                break;
                
            case 3:
                return 0;
        }
    }
    return 0;
}




