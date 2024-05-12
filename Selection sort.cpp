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

void selectionSort(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		int min = i;

		for(int j = i + 1; j < size; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}

		swap(arr[min], arr[i]);
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
	int size = 100000;
	int data[100000];

	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % 128;
	}

	selectionSort(data, size);

	cout << "sorted array in ascending order:\n";
	printArray(data, size);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "time taken by function: " << duration.count() << " microseconds" << endl;
}