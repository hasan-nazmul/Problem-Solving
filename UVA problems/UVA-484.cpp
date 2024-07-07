#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define nl '\n'

int main()
{	
	ll n;
	
	map <ll, ll> mp;
	
	vector <ll> v;
	
	while(cin >> n)
	{
		mp[n]++;
		v.push_back(n);
	}
	
	for(auto i : v)
	{
		if(mp[i])	cout << i << " " << mp[i] << nl;
		mp[i] = 0;
	}
}	