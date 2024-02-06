#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;
struct p {
    int ele;
    int left;
    int right;
};

void test() {
    int n;
    cin >> n;
    vector<int>a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int q;
    cin >> q;
    // preprocess here
    int last = 0;
    map<int, int>mp;
    vector<p>pre;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[last]) {
            pre.push_back(p{a[last], last, i - 1});
            last = i;
        } else {
            mp[i] = pre.size();
        }
    }
    pre.push_back(p{a[n - 1], last, n - 1});
    int c, d;
    for (auto& i : pre) {
        cout << i.ele << ' ' << i.left << ' ' << i.right << '\n';
    }
//    for (int i = 0; i < q; ++i) {
//        cin >> c >> d;
//        --c;
//        --d;
//        if (mp[c] == mp[d]) {
//            std::cout << -1 << ' ' << -1 << '\n';
//        } else {
//            std::cout << pre[mp[c]].right << ' ' << pre[mp[c] + 1].left << '\n';
//        }
//    }

    cout << '\n';

}
int main() {
    cin >> t;
    while (t--) test();
}
