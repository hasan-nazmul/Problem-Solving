/// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pr pair <ll, ll>
#define sp ' '
#define PI acos(-1.0)
#define mod(a, b) (((a) % (b)) + (b)) % (b)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define max_heap(t) priority_queue <t, vector <t>>
#define min_heap(t) priority_queue <t, vector <t>, greater <t>>
#define YES cout << "YES" << nl
#define NO cout << "NO" << nl
#define Yes cout << "Yes" << nl
#define No cout << "No" << nl
#define yes cout << "yes" << nl
#define no cout << "no" << nl
#define neg cout << -1 << nl
#define OUT(v, n) for(auto x: v)    cout << x << n;
#define PAIR_OUT(v) for(auto x: v) \
        cout << x.first << " " << x.second << nl;
#define eps 1000000007

bool CHECK(ll N,ll pos) { return (bool)(N&(1<<pos)); }

unsigned ll SET(ll N,ll pos) { return (N|(1<<pos)); }

int doublecmp(double a, double b)
{
    if(abs(a - b) <= 1e-5)
      return 0;

    else if(a > b) return 1;

    else return -1;
}

ll __gcd(ll x, ll y)
{
    if(y == 0) return x;
    return __gcd(y, x%y);
}

ll __lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

string binaryfy(ll num)
{
    if(!num) return "0";

    string a;

    while(num) {
       if(num % 2) a += '1';
       else a += '0';

       num /= 2;
    }

    reverse(a.begin(), a.end());

    return a;
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

ll power(ll a, ll b, ll m)
{
    ll val = 1;

    while(b > 0) {
       if(b & 1) val = mod((mod(val, m) * mod(a, m)), m);

       b >>= 1;
       a = mod((mod(a, m) * mod(a, m)), m);
    }

    return val;
}

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // solve();

    ll M; cin >> M;

    while(M--) {
       solve();
    }

    return 0;
}