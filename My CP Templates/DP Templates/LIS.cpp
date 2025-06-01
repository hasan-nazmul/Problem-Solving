#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector <int> arr(n+1);

    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    vector <int> lis(n+1, INT_MAX);
    vector <int> idx(n+1, -1);
    vector <int> prev(n, -1);

    lis[0] = INT_MIN;

    for(int i = 1; i <= n; i++)
    {
        int index = upper_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        if(arr[i] > lis[index-1]) 
        {
            lis[index] = arr[i];
            idx[index] = i;
            prev[index] = idx[index-1];
        }
    }

    int ans = 1;

    for(int i = 0; i <= n; i++)
        if(lis[i] != INT_MAX)   ans = i;

    cout << ans << endl;

    vector <int> subsq(1, lis[ans]);

    while(prev[ans] != -1)  
        subsq.push_back(arr[prev[ans]]), ans--;

    reverse(subsq.begin(), subsq.end());

    for(auto i : subsq) cout << i << " ";

    cout << endl;
}