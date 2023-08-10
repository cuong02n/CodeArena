/*
    author : cuong2905say
    created : 13-09-2022  19:00:19    UTC: +7
*/
#include <bits/stdc++.h>

using namespace std;
int t = 0;  // test case
void solve() {
    string s;
    cin >> s;
    int up_to_low = 0, low_to_up = 0;
    string c1 = "";
    for (char c : s) {
        c1.append(1, c);

        up_to_low = min(up_to_low, low_to_up);  //?
        if (c >= 'a' && c <= 'z') {
            low_to_up++;
        } else {
            up_to_low++;
        }
        cout << "str : " << c1 << endl;
        // cout << "Upper to lower : " << up_to_low << " Lower to upper : " << low_to_up << endl;
    }
    cout << min(up_to_low, low_to_up) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    system("pause");
    return 0;
}