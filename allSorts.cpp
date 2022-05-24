/* Program to demonstrate time taken by function fun() */
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int *arr, int n)
{
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void insertionSort(int *arr, int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void ShellSort(int *arr, int n)
{
    int key, j;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            key = arr[i];
            for (j = i; j >= gap && key < arr[j - gap]; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
        }
    }
}

void SelectionSort(int *arr, int n)
{
    int indexofmin;
    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[indexofmin] > arr[j])
            {
                indexofmin = j;
            }
        }
        swap(arr[indexofmin], arr[i]);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low], i = low + 1, j = high;
    do
    {
        while (pivot >= arr[i])
            i++;

        while (pivot < arr[j])
            j--;

        if (i < j)
            swap(arr[i], arr[j]);

    } while (i < j);
    swap(arr[low], arr[j]);
    return j;
}
void QuuickSort(int *arr, int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        QuuickSort(arr, low, partitionindex - 1);
        QuuickSort(arr, partitionindex + 1, high);
    }
}

void merge(int *arr, int low, int mid, int high)
{
    int i, j, k, temparr[high];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temparr[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temparr[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temparr[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temparr[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        arr[i] = temparr[i];
    }
}

void mergeSort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void countSort(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    int *count = new int[max + 1]{};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int i = 0, j = 0;
    while (i < max + 1)
    {
        if (count[i] > 0)
        {
            arr[j++] = i;
            count[i]--;
        }
        else
            i++;
    }
}

void CSort(int *arr, int n, int exp)
{
    int count[10] = {0}, output[n], i;
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int *arr, int n)
{
    int i, max = 0;
    for (i = 0; i < n; i++)
        if (max < arr[i])
            max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
        CSort(arr, n, exp);
}
int parent(int i) { return (i + 1) / 2; }
int Leftchild(int i) { return (i * 2) + 1; }
int Rightchild(int i) { return (i * 2) + 2; }

void Heapify(int *arr, int n, int i)
{
    int largest = i, l = Leftchild(i), r = Rightchild(i);
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
    }
}
void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

void GenerateRandom(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void print(int *arr, int n)
{
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    clock_t t;
    double time_taken;
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << endl
         << endl;
    int arr[n];

    GenerateRandom(arr, n);
    t = clock();
    BubbleSort(arr, n);
    print(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken(Bubble Sort) : " << time_taken;

    GenerateRandom(arr, n);
    t = clock();
    insertionSort(arr, n);
    print(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken(Insertion Sort) : " << time_taken;

    GenerateRandom(arr, n);
    t = clock();
    SelectionSort(arr, n);
    print(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken(Selection Sort) : " << time_taken;

    GenerateRandom(arr, n);
    t = clock();
    ShellSort(arr, n);
    print(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken(Shell Sort) : " << time_taken;

    GenerateRandom(arr, n);
    t = clock();
    QuuickSort(arr, 0, n - 1);
    print(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken(Quick Sort) : " << time_taken;

    GenerateRandom(arr, n);
    t = clock();
    mergeSort(arr, 0, n - 1);
    print(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken(Merge Sort) : " << time_taken;

    GenerateRandom(arr, n);
    t = clock();
    countSort(arr, n);
    print(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken(Count Sort) : " << time_taken;

    GenerateRandom(arr, n);
    t = clock();
    radixSort(arr, n);
    print(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken(Radix Sort) : " << time_taken;

    GenerateRandom(arr, n);
    t = clock();
    heapSort(arr, n);
    print(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken(heap Sort) : " << time_taken;

    return 0;
}
