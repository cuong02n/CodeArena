/*
    author : cuong2905say
    created : 09-10-2023  21:50:35  UTC: +7
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()
#define sc scan_single()

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> A) {
    os << "{ " << A.first << ", " << A.second << " }";
    return os;
}
template <class T1, class T2, class T3>
ostream& operator<<(ostream& os, tuple<T1, T2, T3> A) {
    os << "{ " << get<0>(A) << ", " << get<1>(A) << ", " << get<2>(A) << " }";
    return os;
}

template <class it>
void _print(it begin, it end) {
    for (it i = begin; i != end; i++) {
        cout << *i << " ";
    }
}
inline int scan_single() {
    int x;
    cin >> x;
    return x;
}

void _verbose() {
}

inline long double distance(int x1, int y1, int x2, int y2) {
    return 1.0 * (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
void precalc() {
}

using p = pair<double, double>;

double distance_s(p p1, p p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
p d, a, b;
p o;
double oa;
double da;
double ob;
double db;
double ab;
bool check(double radius) {
    if (radius >= ab / 2) {
        return (oa <= radius || ob <= radius) && (da <= radius || db <= radius);
    }
    return (oa <= radius && da <= radius) || (ob <= radius && db <= radius);
}
void solve(bool v = false, int all_case = -1) {
    o.first = 0.0;
    o.second = 0.0;
    cin >> d.first >> d.second >> a.first >> a.second >> b.first >> b.second;
    oa = distance_s(o, a);
    da = distance_s(d, a);
    ob = distance_s(o, b);
    db = distance_s(d, b);
    ab = distance_s(a, b);
    set<double> x;
    x.insert(oa);
    x.insert(da);
    x.insert(ob);
    x.insert(db);
    x.insert(ab / 2);
    for (double i : x) {
        if (check(i)) {
            cout << setprecision(10) << i << endl;
            return;
        }
    }
    if (!v && all_case == all_cases) {
        return;
    }
    if (v && all_case == all_cases) {
        _verbose();
    }
}

void reset() {
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    precalc();
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
#ifndef ONLINE_JUDGE
        cout << "case " << i + 1 << ": ";
#endif
        if (verbose == i + 1) {
            solve(true, t);
        } else {
            solve(false, t);
        }
        reset();
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
#ifndef ONLINE_JUDGE
    chrono::duration<double> time_span = chrono::duration_cast<std::chrono::duration<double>>(end - start);
    cout << "time use: " << time_span.count() << endl;
#endif

    return 0;
}
