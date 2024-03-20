#include <bits/stdc++.h>
using namespace std;
using ll = long long;




int main() {
    int n;
    cin >> n;
    while (n--) {
        ll t;
        cin >> t;
        vector<ll>arr;
        for (int i = 1; i <= t; ++i) {
            ll x;
            cin >> x;
            arr.push_back(abs(i - x));

        }
        ll num = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            num = __gcd(num, arr[i]);
        }
        cout << num << '\n';
    }
}
