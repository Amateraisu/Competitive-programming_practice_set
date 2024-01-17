#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;


void test() {
    ll n, a, b, c;

    cin >> n >> a >> b >> c; // n elements, start with a, b per unit time and c is the cost of on and off
    vector<ll>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    ll prev = 0;
    for (int i = 0; i < n; prev = nums[i], ++i) {
        ll cost = (nums[i] - prev) * b;
        ll cost2 = c * 2;
        ll cost3 = min(cost, cost2);
        if (a - cost3 <= 0) {
            cout << "NO\n";
            return;
        }
        a -= cost3;


    }
    cout << "Yes\n";
}

int main() {
    cin >> t;
    while (t--)test();
}
