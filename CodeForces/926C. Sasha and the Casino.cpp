#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    ll multiplier , rounds, coins;

    cin >> multiplier >> rounds >> coins;
    ++rounds;
    ll p = 1;
    for (int i = 1; i <= rounds; ++i) {
        ll currentBet =ceil((float)p/(multiplier - 1));
        p += currentBet;
        if (currentBet > coins) {
            cout << "NO\n";
            return;
        }
    }
    if (p <= coins) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}



int main() {
    int t;
    cin >> t;
    while (t--) test();
}