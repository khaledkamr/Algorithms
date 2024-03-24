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

int BinarySearch(int arr[], int l, int h, int key)
{
    while(l <= h)
    {
        int m = (l + h)/2;

        if(arr[m] == key)
        {
            return m;
        }
        if(arr[m] > key)
        {
            h = m -1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

int main()
{
    IOS;
    auto start = high_resolution_clock::now();
	int size = 100000;
    int x = 77;
	int data[100000];

	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % 128;
	}

	int result = BinarySearch(data, 0, size - 1, x);

    if(result == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index: " << result;
    }

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "time taken by function: " << duration.count() << " microseconds" << endl;

}