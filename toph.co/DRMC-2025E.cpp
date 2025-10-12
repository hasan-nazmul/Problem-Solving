/// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

// ========== DEBUGGER =========== //
// Credit: Modified from tourist's debugger
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}

template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) {
        cerr << (f++ ? "," : "");
        __print(i);
    }
    cerr << "}";
}

void _print() { cerr << "]\n"; }

template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define debug(x...) cerr << "\n[" << #x << "] = ["; _print(x)
// ========== END DEBUGGER ========== //

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
#define OUT(v, n) for(auto x: v) cout << x << n;
#define PAIR_OUT(v) for(auto x: v) \
        cout << x.first << " " << x.second << nl;
#define fraction(n) cout << setprecision(n) << fixed
#define eps 1000000007

inline void normal(ll &a) { a %= eps; (a < 0) && (a += eps); }
inline ll modMul(ll a, ll b) { a %= eps, b %= eps; normal(a), normal(b); return (a*b)%eps; }
inline ll modAdd(ll a, ll b) { a %= eps, b %= eps; normal(a), normal(b); return (a+b)%eps; }
inline ll modSub(ll a, ll b) { a %= eps, b %= eps; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, eps-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

bool CHECK(ll N,ll pos) { return (bool)(N&(1LL<<pos)); }

unsigned ll SET(ll N,ll pos) { return (N|(1LL<<pos)); }

// returns least significant bit of x
unsigned ll LSB(ll x)   { return x & -x; }

int doublecmp(double a, double b)
{
    if(abs(a - b) <= 1e-5)
      return 0;

    else if(a > b) return 1;

    else return -1;
}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }

ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

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

struct state
{
   int i, j;
   state(){}
   state(int i, int j) : i(i), j(j) {}
};

int dx[] = { +1, -1, 0, 0 };
int dy[] = { 0, 0, +1, -1 };

const int mx = 1e5+10;

void solve()
{
    ll n;
    string s;
    vector <ll> del(26);
    
    deque <ll> first_appr[26];
    
    
    cin >> n >> s;
    ll pre_sum[26][n+5];
    memset(pre_sum, 0, sizeof(pre_sum));
    
    for(auto &i : del)
        cin >> i;

    for(int i=0; i<n; i++)
    {
        first_appr[s[i]-'a'].push_back(i+1);
        for(int j=0; j<26; j++)
        {
            pre_sum[j][i+1] = pre_sum[j][i] + ((s[i]-'a')==j);
        }
    }

    string ans;

    ll pos = 0;

    for(int it=0; it<n; it++)
    {
        bool fl = 0;

        for(char ch = 'z'; ch >= 'a'; ch--)
        {
            if(sz(first_appr[ch-'a'])==0)   continue;

            ll fapp = first_appr[ch-'a'].front();

            bool f = 1;

            for(char c = ch-1; c >= 'a'; c--)
            {
                if(pre_sum[c-'a'][fapp]-pre_sum[c-'a'][pos] > del[c-'a'])
                {
                    f = 0;
                    break;
                }
            }

            if(f)
            {
                for(char c = ch-1; c >= 'a'; c--)
                {
                    del[c-'a'] -= (pre_sum[c-'a'][fapp]-pre_sum[c-'a'][pos]);
                    while(sz(first_appr[c-'a']) and first_appr[c-'a'].front()<fapp)
                    {
                        first_appr[c-'a'].pop_front();
                    }
                }
                first_appr[ch-'a'].pop_front();
                pos = fapp;
                ans.push_back(ch);
                fl = 1;
                break;
            }
        }

        if(!fl) break;
    }

    cout << ans << nl;
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