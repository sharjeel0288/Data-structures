#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Pqueue
{

public:
    int size, *arr, f;
    Pqueue()
    {
        size = 0;
        f = -1;
    }
    Pqueue(int s)
    {
        size = s;
        f = -1;
        arr = new int[size];
    }
    void enqueue(int key)
    {
        if (f == size - 1)
        {
            cout << "Queue if full" << endl;
            return;
        }
        cout << "enqueue successfully" << endl;
        if (f == -1)
        {
            arr[0] = key;
            f++;
            return;
        }
        else
        {
            int i = 0; // 2 5 6 8 9      0
            bool isswaped = false;
            for (i = 0; i < f + 1; i++)
            {
                if (key < arr[i])
                {
                    // cout<<"k : "<<key<<" arr[i] : "<<arr[i]<<endl;;
                    for (int j = f; j >= i; j--)
                    {
                        arr[j + 1] = arr[j];
                    }
                    arr[i] = key;
                    isswaped = true;
                    break;
                }
                if (isswaped == false)
                {
                    arr[f + 1] = key;
                }
            }
            f++;
        }
    }
    int dequeue()
    {
        if (f == -1)
        {
            cout << "Queue is empty" << endl;
            return -999;
        }
        else
        {
            int data = arr[f];
            f--;
            cout << "dequeue successfully" << endl;
            return data;
        }
    }
    int length()
    {
        return f + 1;
    }
    void print()
    {
        for (int i = 0; i <= f; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
    }
};

int main()
{
    int n;
    cout << "Enter queue size : ";
    cin >> n;
    Pqueue q(n);
    while (1)
    {
        cout << endl
             << "Press 1 to enqueue element " << endl
             << "Press 2 to dequeue element" << endl
             << "Press 3 to find used length" << endl
             << "Press 4 to print queue" << endl
             << "Press 0 to exit" << endl
             << endl;
        cin >> n;
        if (n == 0)
            break;
        switch (n)
        {
        case 1:
            cout << endl
                 << "Enter data to enqueue : ";
            cin >> n;
            q.enqueue(n);
            break;
        case 2:
            cout << endl
                 << "Dequeued elememt : " << q.dequeue() << endl;
            break;
        case 3:
            cout << endl
                 << "Used length : " << q.length() << endl;
            break;
        case 4:
            cout << endl
                 << "Printing Queue    :    ";
            q.print();
        default:
            break;
        }
    }

    return 0;
}