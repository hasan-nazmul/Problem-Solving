#include <bits/stdc++.h>

using namespace std;

#define ll  long long

#define FastIO  ios_base::sync_with_stdio(false)

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
    if(fabs(a - b) <= 1e-10)
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

bool comp(pair <ll, ll> a, pair <ll, ll> b) {

    return a.second > b.second;
}

bool ok()    {

}

void solve()    {

    ll l, l1, l2, r1, r2, M, N, O, P, m = 0, val = 0, num = 0, n = 0, o = 0, p = 0, r, i, j, k = 1, count = 0, sum = 0, min = LONG_MAX, max = LONG_MIN, index = 0;

    static int t = 1;

    double x, y, z;

    bool f = true, flag = false;

    char ch;

    deque <ll> dq, iq, odd, even, cnt(30, 0);

    deque <pair <ll, ll>> pdq;

    string a, b, c, d, e;

    set <ll> st;

    map <ll, ll> mp, emp;

    pair <ll, ll> pr, qr, sr, ss, ee;

    while(1)    {

        cin >> m >> n; count = 0;

        if(!m && !n)    break;

        set <ll> jack;

        set_IN(jack, m);

        for(i = 0; i < n; i++)  {
            cin >> num;
            if(jack.find(num) != jack.end()) count++;
        }

        cout << count << endl;
    }
}

int main()
{
    FastIO;

    ll M, N, O, P, m = 1, val = 0, num = 0, n = 0, o, p = 0, q = 0, r, i, j, k, pos, count = 0, sum = 0, min = INT_MAX, max = INT_MIN, index = 0;

    bool f = true;

    string a, b, c, d;

    solve();

    /*cin >> M;

    while(M--)  {
        solve();
    }*/
}
