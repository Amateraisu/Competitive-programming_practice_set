#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;
int n , k;

void test_case() {
    cin >> n >> k;
    set<int>s;
    vector<int>nums(n,0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    for (int i = 0; i < n; ++i) s.insert(nums[i]);
    if (s.size() > k) {
        cout << -1 << '\n';
        return;
    }
    vector<int>res;
    cout << n * k << '\n';
    for (int i = 0; i< n; ++i) {
        for (int x : s) {
            cout << x << ' ';
        }
        for (int j = 0; j < k - s.size() ; ++j) {
            cout << 1 << ' ';
        }
    }
    cout << '\n';

}
int main() {
    cin >> t;
    while (t--) test_case();


}
