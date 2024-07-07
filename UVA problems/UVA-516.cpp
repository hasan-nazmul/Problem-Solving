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

vector <int> factors(40000);

void prime_factor(int n)
{
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
	while(1)
	{
		string s;
		
		getline(cin, s);
		
		s += " ";
		
		ll nm = 0;
		
		vector <ll> v;
		
		for(auto i : s)
		{
			if(i == ' ')
			{
				if(nm)	v.push_back(nm);
				nm = 0;
			}
			else
			{
				nm *= 10;
				nm += i - '0';
			}
		}
		
		if(v.empty())	return;
		
		nm = 1;
		
		for(int i = 0; i < sz(v); i += 2)
			nm *= power(v[i], v[i+1]);
			
		nm--;
		
		prime_factor(nm);
		
		bool f = 0;
		
		int i;
		
		for(i = sz(primes) - 1; i != -1; --i)
		{
			if(factors[primes[i]])
			{
				cout << primes[i] << sp << factors[primes[i]];
				factors[primes[i]] = 0;
				--i;
				break;
			}
		}
		
		for(; i != -1; --i)
		{
			if(factors[primes[i]])
			{
				cout << sp << primes[i] << sp << factors[primes[i]];
				factors[primes[i]] = 0;
			}
		}
		
		cout << nl;
	}
}

int main()        
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    sieve(32770);
    
	solve();

    return 0;
    
    ll M; cin >> M;

    while(M--)  {
        solve();
    }

    return 0;
}