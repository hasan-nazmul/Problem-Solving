#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
 
    cin >> n;
 
    vector <int> arr(200010);
 
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    vector <int> lis(200010, INT_MAX);
 
    lis[0] = INT_MIN;
 
    for(int i = 1; i <= n; i++)
    {
        int idx = upper_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        if(arr[i] > lis[idx-1]) lis[idx] = arr[i];
    }
 
    int ans = 1;
 
    for(int i = 0; i <= n; i++)
        if(lis[i] != INT_MAX)   ans = i;
 
    cout << ans << endl;
}
