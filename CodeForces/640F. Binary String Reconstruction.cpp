#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;



void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    string res;
    // why dont I just use it all at the start ?
    string zeros(a + 1, '0');
    bool done = false;
    // if this is an odd number. meaning there is actually a number here
    if (b % 2 != 0) {
        res += zeros;
        done = true;
        --b;
        res += "1";
    }
    // if there is an even number of 01s, then just use this loop to fill it up
    for (int i = b; i > 0; i-=2) {
        if (!done) {

            res += zeros;
            res += "1";
            done = true;
        } else {
            res += "01";
        }

    }
    if (!done && a > 0) res += zeros;
    if (res[res.size() - 1] != '1' && c > 0) {
        res += "1";
    }
    for (int i = 0 ; i < c; ++i) {
        res += "1";
    }
    // find any present 0s and just append to it..
    cout << res << '\n';

}


int main() {
    cin >> t;
    while (t--) solve();


    return 0;
}
