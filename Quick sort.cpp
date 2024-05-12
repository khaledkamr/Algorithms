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

int partition(int arr[], int l, int h)
{
	int p = arr[l];
	int i = l;
	int j = h;

	while(i < j)
	{
		do
		{
			i++;
		} while (arr[i] <= p);
		do
		{
			j--;
		} while (arr[i] > p);	

		if(i < j)
		{
			swap(arr[i], arr[j]);
		}			
	}
	swap(arr[l], arr[j]);
	return j;
}

void quickSort(int arr[], int l, int h)
{
	if(l < h)
	{
		int piv = partition(arr, l ,h);
	    quickSort(arr, l, piv);
	    quickSort(arr, piv + 1, h);
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

	quickSort(data, 0, size - 1);

	cout << "sorted array in ascending order:\n";
	printArray(data, size);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "time taken by function: " << duration.count() << " microseconds" << endl;
}