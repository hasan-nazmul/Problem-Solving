// Particular code prints the Sum of Divisors from numbers 1 to 1e7

// Time Complexity: O(nln(n))

#include <bits/stdc++.h>

using namespace std;

const int mx_size = 1e7 + 100;

long long sod[mx_size];

int main()
{
    int lim = 1e7 + 10;

    for(int i = 1; i <= lim; i++)
    {
        for(int j = i; j <= lim; j += i)
            sod[j] += i;
    }

    for(int i = 1; i <= 20; i++)
    {
        cout << i << " : " << sod[i] << endl;
    }
}