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
 
bool CHECK(ll N,ll pos) { return (bool)(N&(1<<pos)); }
 
unsigned ll SET(ll N,ll pos) { return (N|(1<<pos)); }
 
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
 
const int mx_len = 1010;
 
ll n, m;
 
ll a[mx_len], b[mx_len];
 
ll dp[mx_len][mx_len]; 
 
state dr[mx_len][mx_len];
 
int lcs(int i, int j)
{
    if(i == n or j == m)      return 0;
    else if(dp[i][j] != -1) return dp[i][j];
 
    if(a[i]==b[j])  
    {
        dr[i][j] = state(i+1, j+1);
        return dp[i][j] = 1+lcs(i+1, j+1);
    }
    else            
    {
        ll ret1 = lcs(i+1, j), ret2 = lcs(i, j+1), ret;
 
        if(ret1 > ret2)
        {
            ret = ret1;
            dr[i][j] = state(i+1, j);
        }
        else
        {
            ret = ret2;
            dr[i][j] = state(i, j+1);
        }
 
        return dp[i][j] = ret;
    }
}
 
void print(int i, int j)
{
    if(i>=n or j>=m)        return;
    else if(a[i]==b[j])     cout << a[i] << sp;
    print(dr[i][j].i, dr[i][j].j);
}
 
void solve()
{
    cin >> n >> m;
 
    for(int i = 0; i < n; i++)
        cin >> a[i];
 
    for(int i = 0; i < m; i++)
        cin >> b[i];
 
    memset(dp, -1, sizeof(dp));
 
    cout << lcs(0, 0) << nl;
 
    print(0, 0);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    solve();
 
    // ll M; cin >> M;
 
    // while(M--) {
    //    solve();
    // }
 
    return 0;
}