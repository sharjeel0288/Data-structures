#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Queue
{
    int sarr[2][6], larr[2][16];
    int sused, lused;
    int shead, stail;

    float threshold;

public:
    Queue()
    {
        sused = 0;
        lused = 0;
        threshold = 5;
        shead = 0;
        stail = 0;
        this->clearQueue();
    }
    Queue(int t)
    {
        sused = 0;
        lused = 0;
        threshold = t;

        shead = 0;
        stail = 0;
        this->clearQueue();
    }
    void clearQueue()
    {
        lused = 0;
        sused = 0;
        for (int i = 0; i < 6; i++)
        {
            sarr[0][i] = 0;
            sarr[1][i] = 0;
        }
        for (int i = 0; i < 16; i++)
        {
            larr[0][i] = 0;
            larr[1][i] = 0;
        }
    }
    void enqueue(int data, int priority)
    {
        // cout<<float((float(sused) / 6) * 100)<<"        "<< float((float(lused) / 16) * 100)<<endl;
        again:
        if ((((float)sused / 6) * 100) + 30 < (((float)lused / 16) * 100))
        {
            cout << "Please update threshold large Queue used 30 % more than small queue" << endl;
        }
        if (!sfull() && priority >= threshold)
        {
            int i, found = 0;
            sarr[0][sused] = data;
            sarr[1][sused] = priority;
            for (size_t i = 0; i < 6; i++)
            {
                for (size_t j = 0; j < 6 - i; j++)
                {
                    if (sarr[j] > sarr[j + 1])
                        swap(sarr[j], sarr[j + 1]);
                }
            }

            cout << "Data enqueued : " << sarr[0][sused] << endl;
            sused++;
            return;
        }
        else if (priority > threshold)
        {
            updateThreshold(threshold + 1);
            goto again;
        }
        
        else if (!lfull())
        {
            larr[0][lused] = data;
            larr[1][lused] = priority;
            cout << "Data enqueued : " << larr[0][lused] << endl;
            lused++;
        }
    }
    // void print()
    // {
    //     for (size_t i = 0; i < 6; i++)
    //     {
    //         cout << sarr[1][i] << "   ";
    //     }
    // }
    int dequeue()
    {
        if (!sempty())
        {
            // cout << "S" << endl;
            int d = sarr[0][sused - 1];
            sarr[0][sused] = 0;
            sarr[1][sused] = 0;

            sused--;
            return d;
        }
        else if (!lfull())
        {
            int found = 0, foundpriority = 0;
            for (int i = 0; i < 16; i++)
            {
                if (foundpriority < larr[1][i])
                {
                    foundpriority = larr[1][i];
                    found = i;
                }
            }
            // cout<<larr[1][found]<<endl;
            int d = larr[0][found];
            for (int i = found; i < 15; i++)
            {
                larr[0][i] = larr[0][i + 1];
                larr[1][i] = larr[1][i + 1];
            }
            lused--;
            return d;
        }
    }
    void updateThreshold(int t)
    {
        threshold = t;
        int size = lused + sused;
        int arr[2][lused + sused];
        int i, j, k;
        for (j = 0, i = 0; i < sused; i++)
        {
            {
                arr[0][i] = sarr[0][j];
                arr[1][i] = sarr[1][j];
                j++;
            }
        }
        for (k = 0; i < sused + lused; i++)
        {
            {
                cout << "  k :  " << k << endl;
                arr[0][i] = larr[0][k];
                arr[1][i] = larr[1][k];
                // cout << arr[0][i] << "          " << larr[0][k] << endl;
                k++;
            }
        }
        this->clearQueue();
        // cout << "CLEAR QUEUE" << endl;
        for (int i = 0; i < size; i++)
        {
            this->enqueue(arr[0][i], arr[1][i]);
        }
    }
    bool lfull()
    {
        if (lused >= 15)
            return true;
        return false;
    }
    bool sfull()
    {
        if (sused >= 5)
            return true;
        return false;
    }
    bool sempty()
    {
        if (sused <= 0)
            return true;
        return false;
    }
};
int main()
{
    Queue q(7);
    for (int i = 0; i < 18; i++)
    {
        q.enqueue(i, i);
    }
    // q.print();
    // q.updateThreshold(6);
    for (int i = 0; i < 18; i++)
    {
        cout << q.dequeue();
        cout << endl;
    }

    return 0;
}