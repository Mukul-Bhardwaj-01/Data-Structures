/*Given a length n, Generate all possible pairs of 'T' and 'F' Strings.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateCombinations(int n, string current, vector<string>& result)
{
    if (current.length() == n)
    {
        result.push_back(current);
        return;
    }
    generateCombinations(n, current + "T", result);
    generateCombinations(n, current + "F", result);
}

int main()
{
    int n;
    cout<<"Enter the length of the string (n): ";
    cin>>n;
    vector<string> combinations;
    generateCombinations(n, "", combinations);
    cout << "All possible combinations of 'T' and 'F' strings of length " << n << ":\n";
    for (const string& combination : combinations)
    {
        cout << combination << endl;
    }

    return 0;
}