/*
    author : cuong2905say
    created : 17-09-2022  21:52:50  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
vector<pair<int, int> > A;

int check(int S) {
    for (auto i : A) {
        if (S <= i.first) {
            return 0;
        }
        S += i.second;
    }
    return 1;
}
int find(int left, int right) {
    if (check(left)) {
        return left;
    }
    int mid = (left + right) / 2;
    if (check(mid)) {
        return find(left, mid);
    }
    return find(mid + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    // A: first : maximum armor of monsters, second : plus damage after kill them;

    while (t--) {
        A.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            int _max = INT_MIN;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                x -= j;
                _max = max(_max, x);
            }
            A.push_back({_max, k});
        }
        sort(A.begin(), A.end(), [](pair<int, int> i1, pair<int, int> i2) {
            return i1.first < i2.first;
        });
        int S = find(0, INT_MAX >> 1);
        cout << S << endl;
    }
    system("pause");
    return 0;
}
