#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

int linearSearch(int *arr, int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key)
		{
			cout << endl
				 << "FOUND at index : " << i;
			return i;
		}
	}
	cout << endl
		 << "NOT FOUND";
	return -1;
}
int binarySearch(int *arr, int low, int high, int key)
{
	int mid = (low + high) / 2;
	if (low < high)
	{
		if (arr[mid] == key)
		{
			cout << endl
				 << "FOUND at index  : " << mid;
			return mid;
		}
		if (key > arr[mid])
			binarySearch(arr, mid + 1, high, key);
		if (key < arr[mid])
			binarySearch(arr, low, mid - 1, key);
	}
	// cout << "NOT FOUND" << endl;
	return -1;
}
int TernarySearch(int *arr, int low, int high, int key)
{
	int mid1 = low + (high - low) / 3;
	int mid2 = high - (high - low) / 3;
	if (low < high)
	{
		if (key == arr[mid1])
		{
			cout << endl
				 << "FOUND at index  : " << mid1;
			return mid1;
		}
		if (key == arr[mid2])
		{
			cout << endl
				 << "FOUND at index  : " << mid2;
			return mid2;
		}
		if (key < arr[mid1])
			TernarySearch(arr, low, mid1 - 1, key);
		if (key > arr[mid1] && key < arr[mid2])
			TernarySearch(arr, mid1 + 1, mid2 - 1, key);
		if (key > arr[mid2])
			TernarySearch(arr, mid2 + 1, high, key);
	}
	return -1;
}
void GenerateRandom(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
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
int JumpSearch(int *arr, int n, int key)
{
	int start, end = sqrt(n);
	while (end < n && key > arr[end])
	{
		start = end;
		end += sqrt(n);
		if (end > n - 1)
			break;
	}
	for (int i = start; i < end; i++)
	{
		if (arr[i] == key)
		{
			cout << endl
				 << "FOUND at index : " << i;
			return i;
		}
	}
	cout << endl
		 << "NOT FOUND";
	return -1;
}
int InterplotationSearch(int *arr, int n, int key)
{
	int low = 0, high = n - 1, pos;
	while (low <= high && key >= arr[low] && key <= arr[high])
	{
		if (low == high && arr[low] == key)
			return low;
		return -1;

		pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));
		if (arr[pos] == key)
		{
			cout << endl
				 << "FOUND at index : " << pos;
			return pos;
		}
		if (arr[pos] > key)
			high = pos;
		else
			low = pos;
	}
	cout << endl
		 << "NOT FOUND";
	return -1;
}
int exponentialSearch(int *arr, int n, int key)
{
	if (arr[0] == key)
	{
		cout << endl
			 << "FOUND at index : 0";
		return 0;
	}
	int i = 1;
	while (i < n && arr[i] <= key)
	{
		i *= 2;
	}
	return binarySearch(arr, i / 2, min(i, n - 1), key);
}
void print(int *arr, int n)
{
	cout
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
	int n, key;
	cout << "Enter n : ";
	cin >> n;
	int arr[n];
	cout << endl
		 << "Enter key to search : ";
	cin >> key;

	GenerateRandom(arr, n);
	t = clock();
	linearSearch(arr, n, key);
	print(arr, n);
	t = clock() - t;
	time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	cout << "Time taken(Linear Search) : " << time_taken << endl;

	GenerateRandom(arr, n);
	t = clock();
	BubbleSort(arr, n);
	if (binarySearch(arr, 0, n - 1, key) == -1)
		cout << endl
			 << "NOT FOUND";
	print(arr, n);
	t = clock() - t;
	time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	cout << "Time taken(Binary Search) : " << time_taken << endl;

	GenerateRandom(arr, n);
	t = clock();
	BubbleSort(arr, n);
	if (TernarySearch(arr, 0, n - 1, key) == -1)
		cout << endl
			 << "NOT FOUND";
	print(arr, n);
	t = clock() - t;
	time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	cout << "Time taken(Ternary Search) : " << time_taken << endl;

	GenerateRandom(arr, n);
	t = clock();
	BubbleSort(arr, n);
	JumpSearch(arr, n, key);
	print(arr, n);
	t = clock() - t;
	time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	cout << "Time taken(Jump Search) : " << time_taken << endl;

	GenerateRandom(arr, n);
	t = clock();
	BubbleSort(arr, n);
	InterplotationSearch(arr, n, key);
	print(arr, n);
	t = clock() - t;
	time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	cout << "Time taken(Interplotation Search) : " << time_taken << endl;

	GenerateRandom(arr, n);
	t = clock();
	BubbleSort(arr, n);
	exponentialSearch(arr, n, key);
	print(arr, n);
	t = clock() - t;
	time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	cout << "Time taken(Exponential Search) : " << time_taken << endl;
	return 0;
}