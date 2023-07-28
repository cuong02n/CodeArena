/*
    author : cuong2905say
    created : 15-09-2022  21:42:35  UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int tt = 0;  // test case
int n, m;
int fit[200001];
int find(int min, int max) {
    if (max == min) {
        return max;
    }
    int mid = (min + max) / 2;
    // time is mid
    // check
    // task =m;
    int total_task = 0;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        for (int i = 0; i < n + 1; i++) {
            fit[x] = 0;
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            fit[x]++;
        }

        // done input
        cout << find(1, 400005) << endl;
    }
    system("pause");
    return 0;
}