/*
    author : cuong2905say
    created : 17-09-2022  13:59:12  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int P[2][100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;  // test case ;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        int top = 0;
        int bot = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                cin >> P[i][j];
            }
        }
        for (int i = 1; i < m; i++) {
            top += P[0][i];
        }
        int _max = top;
        for (int i = 1; i < m; i++) {
            top -= P[0][i];
            bot += P[1][i - 1];
            _max = min(_max, max(bot, top));
        }
        cout << _max << endl;
    }
    system("pause");
    return 0;
}
