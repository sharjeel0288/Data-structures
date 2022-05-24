#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Minheap
{
    int max_size, used_size, *arr;

public:
    Minheap()
    {
        arr = nullptr;
        max_size = 0;
        used_size = 0;
    }
    Minheap(int s)
    {
        max_size = s;
        arr = new int[s];
        used_size = 0;
    }
    int parent(int child) { return (child - 1) / 2; }

    int leftchild(int par) { return (par * 2) + 1; }

    int rightchild(int par) { return (par * 2) + 2; }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void insert(int key)
    {
        if (used_size == max_size)
        {
            cout << "Heap overflow" << endl;
            return;
        }
        used_size++;
        int i = used_size - 1;
        arr[i] = key;
        while (i > 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void decreasekeyat(int index, int newkey)
    {
        if (arr[index] > newkey)
        {
            arr[index] = newkey;
            while (index > 0 && arr[index] < arr[parent(index)])
            {
                swap(arr[index], arr[parent(index)]);
                index = parent(index);
            }
        }
    }
    void Minheapify(int i = 0)
    {
        int smallest = i, l = leftchild(i), r = rightchild(i);
        if (l < used_size && arr[l] < arr[smallest])
            smallest = l;
        if (r < used_size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(arr[smallest], arr[i]);
            Minheapify(smallest);
        }
    }
    void delkeyat(int i)
    {
        decreasekeyat(i,INT_MIN);
        del();

    }
    int del()
    {
        int root = arr[0];
        arr[0] = arr[used_size - 1];
        used_size--;
        Minheapify();
        return root;
    }
    void print()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << arr[i] << "\t\t";
        }
    }
    void printin2d()
    {
        int i=0;
        int space=used_size/2;
        int newline=1;
        int loop=0;
        for(i;i<used_size;i)
        {
            for(int j=0;j<=space;j++)
            {
                cout<<"\t";
            }
            space--;
            loop=0;
            while(loop<newline && i<used_size)
            {
              //  cout<<"i :"<<i<<"  ";
                cout<<arr[i]<<"\t   ";
                loop++;
                i++;
            }
            newline*=2;
            cout<<endl;

        }
    }
};

int main()
{
    Minheap heap(20);
    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    heap.insert(0);
    heap.insert(50);
    heap.insert(160);
    heap.printin2d();
    cout<<endl;
    cout<<heap.del()<<endl;
    heap.print();
    cout<<heap.del()<<endl;
    heap.delkeyat(2);
    heap.print();
    heap.decreasekeyat(5, 3);
    return 0;
}