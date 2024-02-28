#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    ll tot = 0 ;
    for (int x : nums) tot += abs(x);
    cout << tot << '\n';
    return;

}
int main() {
    cin >> t;
    while (t--) test();
}