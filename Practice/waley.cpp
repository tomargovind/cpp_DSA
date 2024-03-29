#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>
#include <numeric>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <deque>
#include <iomanip>
#include <unordered_set>
#include <limits>
#include <list>
#include <bitset>
#include <random>
#include <cstring>
#include <cassert>

using namespace std;
// namespace __gnu_pbds;

/*template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B>
using indexed_map = tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;*/

using ll = long long;
using ld = long double;
//using lll = __int128;
template<typename A, typename B>
using pa = pair<A, B>;
template<typename T>
using v = vector<T>;
template<typename ...T>
using tup = tuple<T...>;

const ll MOD = 1e9 + 7;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dx[]{ 1, 0, -1, 0 };
ll dy[]{ 0, 1, 0, -1 };

template<typename T>
inline pa<T, T> operator+(pa<T, T> a, pa<T, T> b) {
    return { a.first + b.first, a.second + b.second };
}

template<typename T>
inline pa<T, T> operator+=(pa<T, T>& a, pa<T, T> b) {
    return a = a + b;
}

template<typename T>
inline pa<T, T> operator-(pa<T, T> a, pa<T, T> b) {
    return { a.first - b.first, a.second - b.second };
}

template<typename T>
inline pa<T, T> operator-=(pa<T, T>& a, pa<T, T> b) {
    return a = a - b;
}

template<typename T>
inline pa<T, T> operator*(pa<T, T> a, T b) {
    return { a.first * b, a.second * b };
}

template<typename T>
inline pa<T, T> operator*=(pa<T, T>& a, T b) {
    return a = a * b;
}
template<typename T>
inline pa<T, T> operator/(pa<T, T> a, T b) {
    return { a.first / b, a.second / b };
}

template<typename T>
inline pa<T, T> operator/=(pa<T, T>& a, T b) {
    return a = a / b;
}

template<typename T>
inline T cross(pa<T, T> a, pa<T, T> b) {
    return a.first * b.second - a.second * b.first;
}

template<typename T>
inline T dot(pa<T, T> a, pa<T, T> b) {
    return a.first * b.first + a.second * b.second;
}

template<typename T>
inline T operator*(pa<T, T> a, pa<T, T> b) {
    return dot(a, b);
}

template<typename T>
inline T operator^(pa<T, T> a, pa<T, T> b) {
    return cross(a, b);
}

template<typename T>
inline std::istream& operator>>(std::istream& in, pa<T, T>& pa) {
    return in >> pa.first >> pa.second;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, pa<T, T>& pa) {
    return out << pa.first << ' ' << pa.second;
}

ll sign(ll a) {
    if (a > 0) {
        return 1;
    }
    else if (a == 0) {
        return 0;
    }
    else {
        return -1;
    }
}

template<typename T>
inline T sqrLength(pa<T, T> pa) {
    return pa.first * pa.first + pa.second * pa.second;
}

template<typename T>
inline T length(pa<T, T> pa) {
    return sqrt(sqrLength(pa));
}

template<typename T>
inline T manhattanLength(pa<T, T> pa) {
    return abs(pa.first) + abs(pa.second);
}

template<typename T>
inline T manhattanDistance(pa<T, T> a, pa<T, T> b) {
    return manhattanLength(a - b);
}

template<typename T>
inline pa<T, T> normalize(pa<T, T> pa) {
    return pa / length(pa);
}

inline pa<ld, ld> toLd(pa<ll, ll> pa) {
    return { (ld)pa.first, (ld)pa.second };
}

template<typename T>
inline bool intersects(pa<T, T> a1, pa<T, T> b1, pa<T, T> a2, pa<T, T> b2) {
    if (a1 == a2 || a1 == b2 || b1 == a2 || b1 == b2) {
        return true;
    }
    else if (cross(b1 - a1, b2 - a2) == 0) {
        if (cross(a2 - a1, a2 - b1) == 0) {
            return dot(a2 - a1, b2 - a1) < 0 || dot(a2 - b1, b2 - b1) < 0 || dot(a1 - a2, b1 - a2) < 0 || dot(a1 - b2, b1 - b2) < 0;
        }
        else {
            return 0;
        }
    }
    else {
        return sign(cross(a2 - a1, b1 - a1)) != sign(cross(b2 - a1, b1 - a1)) && (sign(cross(a1 - a2, b2 - a2)) != sign(cross(b1 - a2, b2 - a2)));
    }
}

ld distFromPoint(pa<ld, ld> point, pa<ld, ld> a, pa<ld, ld> b) {
    if (dot(point - a, b - a) >= 0 && dot(point - b, a - b) >= 0) {
        return (abs(cross(a - point, b - point))) / (length(b - a));
    }
    else {
        return min(length(point - a), length(point - b));
    }
}

template<typename T>
inline T sign(T n) {
    if (n > 0) {
        return 1;
    }
    else if (n == 0) {
        return 0;
    }
    else {
        return -1;
    }
}

ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    else {
        return gcd(b % a, a);
    }
}

template<typename T>
istream& operator>>(istream& in, v<T>& a) {
    for (T& x : a) {
        in >> x;
    }
    return in;
}

bool point_in_aabb(pa<ll, ll> a, pa<ll, ll> b, pa<ll, ll> x) {
    return x.first >= min(a.first, b.first) && x.first <= max(a.first, b.first) && x.second >= min(a.second, b.second) && x.second <= max(a.second, b.second);
}

bool point_on_segm(pa<ll, ll> a, pa<ll, ll> b, pa<ll, ll> x) {
    if (((b - a) ^ (x - a)) == 0) {
        return point_in_aabb(a, b, x);
    }
    else {
        return false;
    }
}

bool point_in_triangle(pa<ll, ll> a, pa<ll, ll> b, pa<ll, ll> c, pa<ll, ll> p) {
    ll s = abs((b - a) ^ (c - a));
    ll s1 = abs((p - a) ^ (c - a));
    ll s2 = abs((b - a) ^ (p - a));
    ll s3 = abs((b - p) ^ (c - p));
    return s == s1 + s2 + s3;
}

template<typename T>
struct circle {
    pa<T, T> center;
    T radius;
    circle() = default;
    circle(pa<T, T> c, T r) : center(c), radius(r) {

    }
    circle(T x, T y, T r) : circle({ x, y }, r) {

    }
};

circle<ld> toLd(circle<ll> w) {
    return { toLd(w.center), (ld)w.radius };
}

template<typename T>
istream& operator>>(istream& in, circle<T>& c) {
    return in >> c.center >> c.radius;
}

template<typename T>
struct line {
    T a, b, c;
    line() = default;
    line(T a, T b, T c) : a(a), b(b), c(c) {

    }
};

template<typename T>
T sqr(T a) {
    return a * a;
}

line<ld> normalize(line<ld> l) {
    ld x = sqrt(sqr(l.a) + sqr(l.b));
    return { l.a / x, l.b / x, l.c / x };
}

pa<ld, ld> normal(line<ld> l) {
    line<ld> norm = normalize(l);
    return { norm.a, norm.b };
}

pa<ld, ld> directing(line<ld> l) {
    pa<ld, ld> n = normal(l);
    return { -n.second, n.first };
}

ld distance(line<ld> l, pa<ld, ld> a) {
    line<ld> norm = normalize(l);
    return abs(norm.a * a.first + norm.b * a.second + norm.c);
}

ll get_side(line<ld> l, pa<ld, ld> p) {
    ld x = l.a * p.first + l.b * p.second + l.c;
    if (x < 0) {
        return -1;
    }
    else {
        return 1;
    }
}

template<typename T>
line<T> radical_axis(circle<T> a, circle<T> b) {
    return {
        2 * (b.center.first - a.center.first),
        2 * (b.center.second - a.center.second),
        sqr(a.center.first) - sqr(b.center.first) + sqr(a.center.second) - sqr(b.center.second) + sqr(b.radius) - sqr(a.radius)
    };
}

pa<ld, ld> perp_pos(line<ld> l, pa<ld, ld> a) {
    ld dist = distance(l, a);
    pa<ld, ld> n = normal(l);
    pa<ld, ld> op = a + n * dist * (ld)2;
    if (get_side(l, a) == get_side(l, op)) {
        pa<ld, ld> xwfwsef = n * dist;
        return { a - xwfwsef };
    }
    else {
        return { a + n * dist };
    }
}

v<pa<ld, ld>> intersect(line<ld> l, circle<ld> w) {
    ld dist = distance(l, w.center);
    if (abs(dist - w.radius) < 1e-5) {
        return { perp_pos(l, w.center) };
    }
    else if (dist > w.radius) {
        return {};
    }
    else {
        pa<ld, ld> pp = perp_pos(l, w.center);
        ld od = sqrt(sqr(w.radius) - sqr(dist));
        pa<ld, ld> d = directing(l);
        return { pp + d * od, pp - d * od };
    }
}

v<pa<ld, ld>> intersect(circle<ld> a, circle<ld> b) {
    return intersect(radical_axis(a, b), a);
}

v<pa<ld, ld>> tangent_points(circle<ld> w, pa<ld, ld> a) {
    pa<ld, ld> c = (a + w.center) / (ld)2;
    ld r = length(c - a);
    return intersect(w, { c, r });
}

line<ld> l_f_p(pa<ld, ld> a, pa<ld, ld> b) {
    return {
        b.second - a.second,
        a.first - b.first,
        a.second * (b.first - a.first) - a.first * (b.second - a.second)
    };
}

pa<ld, ld> pet(pa<ld, ld> a, pa<ld, ld> b, pa<ld, ld> other) {
    line<ld> l = l_f_p(a, b);
    pa<ld, ld> mid = (a + b) * 0.5l;
    pa<ld, ld> norm = normal(l);
    if (get_side(l, mid + norm) == get_side(l, other)) {
        norm = norm * (-1.0l);
    }
    pa<ld, ld> res = mid + norm * (length(b - a) * sqrtl(3.0l) / 2.0l);
    return res;
}

pa<ld, ld> intersect(const line<ld>& a, const line<ld>& b) {
    ld x = (a.a * b.c - b.a * a.c) / (b.a * a.b - a.a * b.b);
    ld y = (a.b * b.c - b.b * a.c) / (b.b * a.a - a.b * b.a);
    return { y, x };
}

void solve() {
    ll n, m;
    cin >> n >> m;
    v<string> s(n);
    cin >> s;
    ll q;
    cin >> q;
    set<ll> bad;
    for (ll i = 1; i < n; ++i) {
        for (ll j = 1; j < m; ++j) {
            if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X') {
                bad.insert(j);
            }
        }
    }

    for(auto x: bad) {
        cout<<x<<" ";
    }
    cout<<endl;

    for (ll req = 0; req < q; ++req) {
        ll x1, x2;
        cin >> x1 >> x2;
        --x1;
        if (bad.upper_bound(x1) != bad.end() && *bad.upper_bound(x1) < x2) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    //cin >> t;
    for (ll i = 0; i < t; ++i) {
        solve();
    }
}