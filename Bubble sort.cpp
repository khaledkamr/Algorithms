#include<iostream>
#include<cstdlib>
#include<string>
#include<numeric> 
#include<algorithm>
#include<math.h>
#include<cmath>
#include<iomanip>
#include<vector>
#include<iterator>
#include<utility>
#include<unordered_set>
#include<climits>
#include<chrono>
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	IOS;
	auto start = high_resolution_clock::now();
	int size = 100;
	int data[100];

	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % 128;
	}

	bubbleSort(data, size);

	cout << "sorted array in ascending order:\n";
	printArray(data, size);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "time taken by function: " << duration.count() << " microseconds" << endl;
}