/// Bismillahir Rahmanir Rahim
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll  long long
 
#define PI  acos(-1.0)
 
#define mod(a, b)   (((a) % (b)) + (b)) % (b)
 
#define sz(v)   (ll) v.size()
 
#define MAX(a, b)   ((a) >= (b)) ? (a) : (b)
 
#define MIN(a, b)   ((a) <= (b)) ? (a) : (b)
 
#define all(v)  v.begin(), v.end()
 
#define rall(v)  v.rbegin(), v.rend()
 
#define YES cout << "YES" << endl;
 
#define NO cout << "NO" << endl;
 
#define Yes cout << "Yes" << endl;
 
#define No cout << "No" << endl;
 
#define yes cout << "yes" << endl;
 
#define no cout << "no" << endl;
 
#define dq_IN(v, N)     for(i = 0; i < (N); i++)                    \
                        {                                           \
                            ll num;                                 \
                            cin >> num;                             \
                            v.push_back(num);                       \
                        }
 
#define set_IN(s, N)    for(i = 0; i < (N); i++)                    \
                        {                                           \
                            ll num;                                 \
                            cin >> num;                             \
                            s.insert(num);                          \
                        }
 
#define OUT(v)  for(auto x: v)                                      \
                    cout << x << " ";
 
#define PAIR_OUT(v)  for(auto x: v)                                 \
                    cout << x.first << " " << x.second << endl;
 
#define dq_2D_IN(dq, M, N)   for(i = 0; i < (M); i++)               \
                             {                                      \
                                deque <ll> v;                       \
                                for(j = 0; j < (N); j++)            \
                                {                                   \
                                    cin >> num;                     \
                                    v.push_back(num);               \
                                }                                   \
                                dq.push_back(v);                    \
                             }
 
#define vec_2D_OUT(vec, M, N)    for(i = 0; i < (M); i++)           \
                                 {                                  \
                                    for(j = 0; j < (N); j++)        \
                                        cout << vec[i][j] << " ";   \
                                    cout << endl;                   \
                                 }
 
#define PRE_SUM(vec)    for(i = 0; i < sz(vec); i++)    \
                        {                               \
                            sum += vec[i];              \
                            vec[i] = sum;               \
                        }
 
int doublecmp(double a, double b)
{
    if(fabs(a - b) <= 1e-6)
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
 
bool isVowel(char ch)   {
    string vowel = "aeiouAEIOU";
 
    for(int i = 0; vowel[i]; i++)   {
        if(vowel[i] == ch)  return true;
    }
 
    return false;
}
 
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    string str = "";
 
    int n1 = str1.length(), n2 = str2.length();
 
    reverse(str1.begin(), str1.end());
 
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
 
        str.push_back(sum % 10 + '0');
 
        carry = sum / 10;
    }
 
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
 
        str.push_back(sum % 10 + '0');
 
        carry = sum/10;
    }
 
    if(carry)  str.push_back(carry + '0');
 
    reverse(str.begin(), str.end());
 
    return str;
}
 
string multiply(string a, string b)
{
    string r, t = "0", U;
 
    int num1, num2, val, carry = 0, k;
 
    reverse(a.begin(), a.end());
 
    reverse(b.begin(), b.end());
 
    for(int i = 0; a[i]; i++)
    {
        num1 = a[i] - '0';
 
        for(int j = 0; b[j]; j++)
        {
            num2 = b[j] - '0';
 
            carry += num1 * num2;
 
            r += (carry % 10) + '0';
 
            carry /= 10;
        }
 
        if(carry)
        {
            r += (carry % 10) + '0';
 
            carry /= 10;
        }
 
        reverse(r.begin(), r.end());
 
        t = findSum(t, r);
 
        U += t.back();
 
        t.pop_back();
 
        r = "";
    }
 
    reverse(t.begin(), t.end());
 
    U += t;
 
    reverse(U.begin(), U.end());
 
    return U;
}
 
bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)    return true;
 
    if (n2 < n1)    return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 
string findDiff(string str1, string str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    string str = "";
 
    int n1 = str1.length(), n2 = str2.length();
 
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    for (int i = 0; i < n2; i++) {
 
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    while(str.back() == '0')    {
        str.pop_back();
    }
 
    reverse(str.begin(), str.end());
 
    if(!sz(str))    return "0";
 
    return str;
}
 
string binaryfy(ll num)    {
 
    string a;
 
    while(num)    {
 
        if(num % 2)   a += '1';
        else    a += '0';
 
        num /= 2;
    }
 
    reverse(a.begin(), a.end());
 
    return a;
}
 
ll power(ll a, ll b, ll m)   {
 
    ll val = 1;
 
    while(b > 0)    {
 
        if(b & 1)   val = mod((mod(val, m) * mod(a, m)), m);
 
        b >>= 1;
 
        a = mod((mod(a, m) * mod(a, m)), m);
    }
 
    return val;
}
 
ll power(ll a, ll b)   {
 
    ll val = 1;
 
    while(b > 0)    {
 
        if(b & 1)   val *= a;
 
        b >>= 1;
 
        a *= a;
    }
 
    return val;
}
 
pair <ll, ll> intersect(pair <ll, ll> a, pair <ll, ll> b) {
 
    pair <ll, ll> c;
 
    if(a.second < b.first || b.second < a.first)  {
        c.first = -1, c.second = -1;
        return c;
    }
 
    vector <ll> vec;
 
    vec.push_back(a.first);
    vec.push_back(a.second);
    vec.push_back(b.first);
    vec.push_back(b.second);
 
    sort(vec.begin(), vec.end());
 
    c.first = vec[1], c.second = vec[2];
 
    return c;
}
 
double toRad(double X)  {
    return (PI * X) / 180.0;
}
 
double toDeg(double X)  {
    if(X < 0)   X += 2 * PI;
    return (180.0 * X) / PI;
}
 
double fixAngle(double A)   {
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}
 
bool coprime(long long a, long long b)
{
    if(__gcd(a, b) == 1)    return true;
 
    else    return false;
}
 
map <ll, ll> factors;
 
void primeFactors(ll n)
{
    factors.clear();
 
	while(!(n % 2))
	{
		factors[2]++;
		n /= 2;
	}
 
	for(ll i = 3; i * i <= n; i += 2)
	{
		while(!(n % i))
		{
			factors[i]++;
			n /= i;
		}
	}
 
	if(n > 2)   factors[n]++;
}
 
bool comp(pair <ll, pair <ll, ll>> a, pair <ll, pair <ll, ll>> b)
{
    return a.first < b.first;
}
 
ll prime_len = 0;
 
deque <bool> primes(prime_len);
 
void sieve()
{
    primes[0] = primes[1] = 1;
 
    for(ll i = 2; i < prime_len; i++)
    {
        if(primes[i])
        {
            for(ll j = i * i; j < prime_len; j += i)
                primes[j] = 1;
        }
    }
}
 
bool ok(ll k)
{
    return 0;
}
 
void solve()    {
 
    ll l, l1, l2, r1, r2, M, N, O, P, m = 0, val = 0, num = 0, n = 0, o = 0, p = 0, q = 0, r, s, i, j, k, count = 0, sum = 0, min = LLONG_MAX, max = LLONG_MIN, index = 0, diff;
 
    static int t = 1;
 
    long double x = 0, y = 0, z = 0;
 
    bool f = false, flag = true;
 
    char ch;
 
    deque <ll> dq(10), iq, eq, odd, even, cnt(0, 0), chk, ans;
 
    deque <pair <ll, ll>> pdq, qdq, cpy;
 
    deque <string> dqs, grid;
 
    deque <deque <ll>> ddq;
 
    string a, b, c, d, e, T;
 
    set <ll> st, st1;
 
    pair <ll, ll> pr, qr, sr, ss, ee;
 
    map <ll, ll> mp, emp;
 
    cin >> N;
 
    while(N)
    {
        M = N;
        max = 0;
 
        while(M)
        {
            max = MAX(max, M % 10);
            M /= 10;
        }
 
        N -= max;
        count++;
    }
 
    cout << count << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    solve();
 
    return 0;
 
    ll M; cin >> M;
 
    while(M--)  {
        solve();
    }
 
    return 0;
}