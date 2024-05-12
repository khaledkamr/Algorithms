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

void insertionSort(int arr[], int size)
{
	for(int i = 1; i < size; i++)
	{
		int k = arr[i];
		int j = i - 1;

		while(k < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = k;
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

	insertionSort(data, size);

	cout << "sorted array in ascending order:\n";
	printArray(data, size);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	cout << "time taken by function: " << duration.count() << " seconds" << endl;
}