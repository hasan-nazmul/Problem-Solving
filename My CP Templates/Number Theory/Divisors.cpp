// Particular code prints the Divisors from numbers 1 to 1e3

// Time Complexity: O(nln(n))

#include <bits/stdc++.h>

using namespace std;

const int mx_size = 1e3 + 100;

vector <int> nod[mx_size];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int lim = 1e3 + 10;

    for(int i = 1; i <= lim; i++)
    {
        for(int j = i; j <= lim; j += i)
            nod[j].push_back(i);
    }

    for(int i = 1; i <= 20; i++)
    {
        cout << i << " : ";
        for(auto j : nod[i])    cout << j << " ";
        cout << endl;
    }
}