/*Write a program that measures the time taken
to perform a BINARY SEARCH on arrays of increasing sizes.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

bool binarySearch(const vector<int>& arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        } else
        {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> sizes = {50, 500, 5000, 50000, 500000};
    int target = -1;
    cout << "Binary Search Time Analysis:\n";
    cout << "Array Size\tTime Taken (microseconds)\n";

    for (int size : sizes)
    {
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
        {
            arr[i] = i;
        }

        auto start = high_resolution_clock::now();
        binarySearch(arr, target);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << size << "\t\t" << duration << " µs\n";
    }
    return 0;
}