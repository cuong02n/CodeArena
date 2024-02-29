#include <bits/stdc++.h>
using namespace std;
vector<int> FENW;
/*START INDEX : 1*/
void point_update(int idx, int value) {
    while (idx < FENW.size()) {
        FENW[idx] += value;
        idx += idx & (-idx);
    }
}
void range_update(int left, int right, int value) {
    point_update(left, value);
    point_update(right + 1, -value);
}
int point_query(int idx) {
    int res = 0;
    while (idx > 0) {
        res += FENW[idx];
        idx -= idx & (-idx);
    }
    return res;
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    FENW.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        range_update(i + 1, i + 1, x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << point_query(x + 1) << endl;
    }
    return 0;
}