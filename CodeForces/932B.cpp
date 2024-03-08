#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 0x3f3f3f3f;
vector<int>coins = {1, 3, 6, 10, 15};
void test() {
    int n;
    cin >> n;
    vector<int>A(n, 0);
    map<int, int>mp;
    int mini = INF;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        mp[A[i]] = 1;
    }
    int goal = INF;
    for (int i = 0; i < 1e6 ; ++i) {
        if (mp[i] == 0) {
            goal = i;
            break;
        }
    }
    ll c = 0;
    set<int>s;
    vector<pair<int, int>>res;
    int prev = 0;
    // cout << "GOAL " << goal << '\n';
    for (int i = 0; i < n; ++i) {
        if (A[i] < goal) {
            s.insert(A[i]);
        }
        if (s.size() == goal) {
            res.push_back(make_pair(prev + 1, i + 1));
            prev = i + 1;
            s.clear();
            ++c;
        }
    }
    if (prev != n) {
        res.back().second = n;
    }
    if (c == 1) {
        cout << -1 << '\n';
    } else {
        cout << res.size() << '\n';
        for (auto& p : res) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }






}

int main() {
    ll t;
    cin >> t;
    while (t--) test();
}
