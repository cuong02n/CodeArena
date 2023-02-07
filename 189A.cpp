/*
    author : cuong2905say
    created : 10-09-2022  18:17:27    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, c;
    int _max = INT_MIN;
    cin >> n >> a >> b >> c;
    for (int i = 0; i <= n / a; i++) {
        int sum = 0;
        sum += a * i;
        for (int j = 0; j <= (n - sum) / b; j++) {
            sum += b * j;
            if ((n - sum) % c) {
            } else {
                _max = max(_max, (i + j + (n - sum) / c));
            }
            sum -= b * j;
        }
    }
    cout << _max << endl;
    system("pause");
    return 0;
}