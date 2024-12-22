/*Calculate the value of a function given by: f(x)=A[0] + A[1].(x) + A[2].(x^2) + ... + A[n].(x^n), Where A is an array and x and n are integers. Using Horner's Rule.*/

#include <iostream>
#include <vector>
using namespace std;

double evaluatePolynomial(const vector<double>& A, int n, double x)
{
    double result = A[n];
    for (int i = n - 1; i >= 0; i--)
    {
        result = result * x + A[i];
    }
    return result;
}

int main()
{
    int n;
    double x;
    cout << "Enter the degree of the polynomial (n): ";
    cin >> n;
    vector<double> A(n + 1);
    cout << "Enter the coefficients A[0] to A[" << n << "]:" << endl;
    for (int i = 0; i <= n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the value of x: ";
    cin >> x;
    double result = evaluatePolynomial(A, n, x);
    cout << "The value of f(x) is: " << result << endl;
    return 0;
}