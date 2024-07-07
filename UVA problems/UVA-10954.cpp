#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define nl '\n'

int main(void)
{	
	ios_base::sync_with_stdio(0); 
	
	cin.tie(0); 
	
	cout.tie(0);

	int n;
	
	while(cin >> n)
	{
		if(!n)	return 0;
		
		vector <ll> v(n);
		
		for(auto &i : v)	cin >> i;
		
		ll cost = 0;
		
		while(!v.empty())
		{
			sort(v.rbegin(), v.rend());
			
			ll s = v.back();
			
			v.pop_back();
			
			if(!v.empty())
			{
				s += v.back();
				v.pop_back();
				if(!v.empty())	v.push_back(s);
			}
			
			cost += s;
		}
		
		cout << cost << nl;
	}
}	