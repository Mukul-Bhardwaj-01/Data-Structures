/*Write a program that measures the time taken to perform a Linear Search on arrays of increasing sizes.*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace chrono;

int linearSearch(const vector<int>& A, int target)
{
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> sizes = {50, 500, 5000, 50000, 500000};
    int target = -1;
    cout << "Array Size\tTime Taken (micro-sec)" <<endl;

    for (int size : sizes)
    {
        vector<int> A(size);
        for (int i = 0; i < size; i++)
        {
            A[i] = rand();
        }

        auto start = high_resolution_clock::now();
        linearSearch(A, target);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout<<size<<"\t\t" << duration.count()<<" micro-sec"<<endl;
    }
    return 0;
}