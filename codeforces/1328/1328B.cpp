/*
    author : cuong2905say
    created : 17-09-2022  22:13:16  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int check(ll k, ll res) {
    if (k > res * (res - 1) / 2) {
        return 0;
    }
    if (k <= (res - 2) * (res - 1) / 2) {
        return 0;
    }
    return 1;
};
ll find(ll k, ll left, ll right) {
    if (check(k, left)) {
        return left;
    }
    if (check(k, right)) {
        return right;
    }
    ll mid = (left + right) / 2;
    if (check(k, mid)) {
        return mid;
    }
    if ((mid - 2) * (mid - 1) / 2 >= k) {
        return find(k, left, mid - 1);
    }
    return find(k, mid + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);            

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        // represented by 3 integer : n: length of string ,a1 ,a2 :position of b;
        ll high_bit = find(k, 1, n);
        ll low_bit = k - (high_bit - 1) * (high_bit - 2) / 2;
        string c = "";
        c.append(n, 'a');
        c[n - low_bit] = 'b';
        c[n - high_bit] = 'b';
        cout << c << endl;
    }
    system("pause");
    return 0;
}
