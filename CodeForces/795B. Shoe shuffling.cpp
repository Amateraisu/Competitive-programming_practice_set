#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void test() {
    int n;
    std::cin >> n;
    std::vector<ll>A(n, 0);
    for (int i = 0 ;i  < n; ++i) cin >> A[i];
    std::map<ll, vector<int>>mp;
    for (int i = 0; i < n; ++i) {
        mp[A[i]].push_back(i + 1);
    }
    for (auto const& [a, b]: mp) {
        if (b.size() == 1) {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto const& [a, b] : mp) {
        // cout << "DEBUGGING\n";
        // for (int x : b) {
        //     cout << x << ' ';
        // }
        // cout << "DONE\n";
        std::cout << b[b.size() - 1] << ' ';
        for (int i = 0 ; i < b.size() - 1; ++i) {
            cout << b[i] << ' ';
        }
    }
    cout << '\n';




}


int main() {
    int n;
    std::cin >> n;
    while (n--) test();
}