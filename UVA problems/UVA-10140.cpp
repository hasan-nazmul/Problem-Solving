/// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>

#include <cstdint>

using namespace std;

#define ll	long long

#define nl	'\n'

#define sp	' '

#define PI	acos(-1.0)

#define mod(a, b)	(((a) % (b)) + (b)) % (b)

#define sz(v)	(int) v.size()

#define all(v)	v.begin(), v.end()

#define rall(v)	v.rbegin(), v.rend()

#define max_heap(t)	priority_queue <t, vector <t>>

#define min_heap(t)	priority_queue <t, vector <t>, greater <t>>

#define YES	cout << "YES" << endl

#define NO	cout << "NO" << endl

#define Yes	cout << "Yes" << endl

#define No	cout << "No" << endl

#define yes	cout << "yes" << endl

#define no	cout << "no" << endl

#define neg	cout << -1 << nl

#define OUT(v)	for(auto x: v)                                      \
                    cout << x << " ";

#define PAIR_OUT(v)	for(auto x: v)                                 \
                        cout << x.first << " " << x.second << endl;

#define eps	1000000007

int doublecmp(double a, double b)
{
    if(abs(a - b) <= 1e-5)
        return 0;

    else if(a > b)  return 1;

    else    return -1;
}

ll __gcd(ll x, ll y)
{
    if (y == 0) return x;
    return __gcd(y, x%y);
}

ll __lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

string binaryfy(ll num)    
{
    if(!num)    return "0";

    string a;

    while(num)    {

        if(num % 2)   a += '1';
        else    a += '0';

        num /= 2;
    }

    reverse(a.begin(), a.end());

    return a;
}

ll power(ll a, ll b, ll m)   
{
    ll val = 1;

    while(b > 0)    {

        if(b & 1)   val = mod((mod(val, m) * mod(a, m)), m);

        b >>= 1;

        a = mod((mod(a, m) * mod(a, m)), m);
    }

    return val;
}

ll power(ll a, ll b)   
{
    ll val = 1;

    while(b > 0)    {

        if(b & 1)   val *= a;

        b >>= 1;

        a *= a;
    }

    return val;
}

bool comp(pair <ll, ll> a, pair <ll, ll> b)
{
    if(a.first == b.first)	return a.second > b.second;
    else	return a.first < b.first;
}

const int mx_len = 1e7 + 10;

bitset <mx_len> isPrime;
vector <ll> primes, segmented_primes;

void sieve(ll len)
{	
	isPrime[2] = 1;
	
	for(ll i = 3; i <= len; i += 2)	isPrime[i] = 1;
	
	for(ll i = 3; i <= len; i += 2)
	{
		if(!isPrime[i])	continue;
		
		for(ll j = i*i; j <= len; j += (2 * i))
			isPrime[j] = 0;
	}
	
	primes.push_back(2);
	
	for(ll i = 3; i <= len; i += 2)
	{
		if(isPrime[i])	primes.push_back(i);
	}
}

ll calc(ll n, ll l)
{
	return n - l;
}

void segmented_sieve(ll l, ll r)
{	
	if(r < l)	swap(l, r);
	
	segmented_primes.clear();
	
	const int lim = 1e6 + 10;
	
	bitset <lim> isPrime;
	
	ll start;
	
	if(mod(l, 2) == 0)	start = l + 1;
	else	start = l;
	
	for(ll i = start; i <= r; i += 2)	
	{
		if(i == 1 or i == -1)	continue;
		isPrime[calc(i, l)] = 1;
	}
	
	if(l <= -2 and r >= -2)	isPrime[calc(-2, l)] = 1;
	if(l <= 2 and r >= 2)	isPrime[calc(2, l)] = 1;
	
	for(auto i : primes)
	{
		if(i*i > max(abs(l), abs(r)))	break;
		
		if(i == 2)	continue;
		
		start = l + i - 1 - mod(l + i - 1, i);
		
		if(mod(start, 2) == 0)	start += i;
		
		if(abs(start) == i)	start += 2*i;
		
		for(ll j = start; j <= r; j += (2 * i))
		{
			if(abs(j) == i)	continue;
			isPrime[calc(j, l)] = 0;
		}
	}
	
	for(int i = l; i <= r; i++)
	{
		if(isPrime[calc(i, l)])	segmented_primes.push_back(i);
	}
}

void solve()
{	
	ll l, r;
	
	while(cin >> l >> r)
	{	
		segmented_sieve(l, r);
		
		if(sz(segmented_primes) < 2)
		{
			cout << "There are no adjacent primes." << nl;
			continue;
		}
		
		pair <ll, ll> most_distant, most_close;
		
		most_distant = most_close = {segmented_primes[0], segmented_primes[1]};
		
		ll mx, mn;
		
		mx = mn = abs(segmented_primes[0] - segmented_primes[1]);
		
		for(int i = 1; i < sz(segmented_primes); i++)
		{
			ll d = abs(segmented_primes[i-1] - segmented_primes[i]);
			if(mx < d)
			{
				mx = d;
				most_distant = {segmented_primes[i-1], segmented_primes[i]};
			}
			if(mn > d)
			{
				mn = d;
				most_close = {segmented_primes[i-1], segmented_primes[i]};
			}
		}
		
		cout << most_close.first << "," << most_close.second << " are closest, ";
		
		cout << most_distant.first << "," << most_distant.second << " are most distant." << nl;
	}
}

int main()        
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    sieve(1e6);
    
	solve();

    return 0;
    
    ll M; cin >> M;

    while(M--)  {
        solve();
    }

    return 0;
}