#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;
ll x;
ll n;
void test() {
    cin >> n;
    vector<int>res(n, 0);
    vector<pair<int, int>>nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums[i] = make_pair(x, i);
    }
    sort(nums.begin(), nums.end());
    vector<pair<int, int>>temp;
    ll cur = 0;
    for (int i = 0; i < n - 1; ++i) {
        cur += nums[i].first;
        if(cur >= nums[i + 1].first) {
            temp.push_back(nums[i]);
        } else {

            res[nums[i].second] = i;
            while (!temp.empty()) {
                auto p = temp.back();
                res[p.second] = i;
                temp.pop_back();
            }
        }
    }
    temp.push_back(nums[n - 1]);
    while (!temp.empty()) {
        auto p = temp.back();
        res[p.second] = n - 1;
        temp.pop_back();
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';


}


int main() {
    cin >> t;
    while (t--) test();
}
