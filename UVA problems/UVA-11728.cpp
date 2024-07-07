/// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>

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

const int mx_len = 1e5 + 10;

bitset <mx_len> isPrime;
vector <int> primes;

void sieve(int lim)
{
	isPrime[2] = 1;
	
	for(int i = 3; i <= lim; i += 2)	isPrime[i] = 1;
	
	for(int i = 3; i*i <= lim; i += 2)
	{
		if(!isPrime[i])	continue;
		
		for(int j = i*i; j <= lim; j += (2*i))
			isPrime[j] = 0;
	}
	
	primes.push_back(2);
	
	for(int i = 3; i <= lim; i += 2)
	{
		if(isPrime[i])	primes.push_back(i);
	}
}

map <int, int> factors, sod;

void prime_factor(int n)
{
	factors.clear();
	
	for(auto i : primes)
	{
		if(i*i > n)	break;
		while(!(n%i))
		{
			factors[i]++;
			n /= i;
		}
	}
	
	if(n > 1)	factors[n]++;
}

void solve()
{
	for(int i = 1; i <= 1000; i++)
	{
		prime_factor(i);
		
		ll s = 1;
		
		for(auto i : factors)
		{
			s *= power(i.first, i.second+1) - 1;
		}
		
		for(auto i : factors)
		{
			s /= (i.first - 1);
		}
		
		sod[s] = i;
	}
	
	int t = 1;
	
	while(1)
	{
		int n;
		
		cin >> n;
		
		if(!n)	return;
		
		if(sod[n])	cout << "Case " << t++ << ": " << sod[n] << nl;
		else		cout << "Case " << t++ << ": " << -1 << nl;
	}
}

int main()        
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    sieve(100000);
    
	solve();

    return 0;
    
    ll M; cin >> M;

    while(M--)  {
        solve();
    }

    return 0;
}