// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    int l;
    cin >> n >> l;
    vector<pair<int, int>>pairs;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        pairs.push_back(make_pair(a, b));
    }
    sort(pairs.begin(), pairs.end(), [](auto& a, auto& b){return a.second < b.second;});
    int res = 0;
    for (int i = 0; i < n; ++i) {
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        // get the minimum values within this ranges
        // but when I pop them out, I need to add them back in
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int, int>>>pq;
        ll tot = 0;
        // so I need to... store the ones I pop out into some temporary container
        for (int j = i; j < n; ++j) {
            pq.push(pairs[j]);
            tot += pairs[j].first;
            // at this here, try as much as possible to pop things out;

            ll limit = l - (pairs[j].second - pairs[i].second);
            // cout << i << ' ' << j << ' ' << res << '\n';
            while (!pq.empty() && tot > limit) {
                tot -= pq.top().first;
                pq.pop();

            }
            res = max(res, (int)pq.size());


        }
    }
    cout << res << '\n';

}

int main() {
    ll t;
    cin >> t;
    while (t--) test();

}
