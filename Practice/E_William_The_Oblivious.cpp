/* Program By govindtomariiit */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
template<typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(),(x).end()
#define fr first
#define sc second
#define vi vector<int> 
#define mii map<int, int> 
#define mci map<char, int> 
#define pii pair<int,int>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define rep1(i, a, b) for(int i=a; i>=b; i--)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout<<#x<<" "<<x<<endl;
#define debugg(x, y) cout<<#x" "<<x<<" "<<#y<<" "<<y<<endl;

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
long long binpow(long long a, long long b) { long long res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3:
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
void pyn(bool flag) {cout << (flag ? "YES" : "NO") << endl;}
void pyn2(bool flag) {cout << (flag ? "Yes" : "No") << endl;}
/*--------------------------------------------------------------------------------------------------------------------------*/

// #define int ll
const ll modc = 1000000007;
const ll inf = 1e18;
const int N = (1*(1e5)) + 5;

int check(o_set<int> &aa, o_set<int> &bb, o_set<int> &cc) {
    if(min({aa.size(), bb.size(), cc.size()}) == 0) return 0;

    int ans1 = 0;
    auto last_c = *(--cc.end());
    auto itr = bb.lower_bound(last_c);
    if(itr == bb.begin()) return 0;
    else {
        itr--;
        // debug(*itr);
        // for(auto x: aa) cout<<x<<" "; cout<<endl;
        ans1 = aa.order_of_key(*itr);
    }
    // debug(ans1);

    int ans2 = 0;
    auto first_a = *aa.begin();
    if(first_a > last_c) return 0;
    else {
        ans2 = bb.order_of_key(last_c) - bb.order_of_key(first_a);
    }
    // debug(ans2);

    int ans3 = 0;
    auto first_b = bb.lower_bound(first_a);
    if(first_b == bb.end()) return 0;
    else {
        ans3 = cc.size() - cc.order_of_key(*first_b);
    }
    // debug(ans3);

    return min({ans1, ans2, ans3});
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    // cin>>tc;
    rep(test_case, 1, tc+1) {
        int n, q;
        cin>>n>>q;
        string s;
        cin>>s;

        o_set<int> aa, bb, cc;
        rep(i, 0, n) {
            if(s[i] == 'a') aa.insert(i);
            else if(s[i] == 'b') bb.insert(i);
            else cc.insert(i);
        }

        // debug(aa.size());
        // debug(bb.size());
        // debug(cc.size());
        int ans = check(aa, bb, cc);
        // cout<<ans<<endl;
        while(q--) {
            int x; char c;
            cin>>x>>c;

            if(aa.find(x-1) != aa.end()) aa.erase(x-1);
            else if(bb.find(x-1) != bb.end()) bb.erase(x-1);
            else if(cc.find(x-1) != cc.end()) cc.erase(x-1);

            if(c == 'a') aa.insert(x-1);
            else if(c == 'b') bb.insert(x-1);
            else cc.insert(x-1);

            cout<<check(aa, bb, cc)<<endl;
        }
    }
}