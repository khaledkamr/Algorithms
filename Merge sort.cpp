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

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1];
	int *R = new int[n2];

	for(i = 0; i < n1; i++)
	{
		L[i] = arr[l + 1];
	}
	for(j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}

	i = j = 0;
	k = l;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
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

	mergeSort(data, 0, size - 1);

	cout << "sorted array in ascending order:\n";
	printArray(data, size);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "time taken by function: " << duration.count() << " microseconds" << endl;
}