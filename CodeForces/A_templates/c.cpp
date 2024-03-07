#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>>p;
    for (int i = 0 ; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        p.push_back(make_pair(a, b));
    }
    auto c = [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    };
    sort(p.begin(), p.end());
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>>temp;
        for (int j = 0; j <= i; ++j) {
            temp.push_back(p[i]);
        }
        sort(temp.begin(), temp.end(), c);
        int total = 0;
        for (auto& t : temp) {
            total += t.first;
        }
        for (int k = temp.size() - 1; k >= 1; --k) {
            // if this is valid, then just take it
            total += (temp[k].second - temp[k - 1].second);
        }
        if (total <=l) res = i + 1;



    }
    cout << res << '\n';




}
int main() {
    cin >> t;
    while (t--) test();
}