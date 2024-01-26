#include <bits/stdc++.h>
using namespace std;

int find(int a, vector<int>& p) {
    if (a != p[a]) {
        p[a] = find(p[a], p);
    }
    return p[a];
}

void uf (int a, int b, vector<int>& p, vector<int>& r) {
    int p1 = find(a,p);
    int p2 = find(b,p);
    if (p1 == p2) {
        ++p1;
        return;
    }

}


int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    map<int, int>mp;
    map<int ,int>mp2;
    vector<int>p(n + 1, 0);
    for (int i = 1; i <= n; ++i) p[i] = i;
    vector<int>rank(n + 1, 1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        uf(a, b, p, rank);
    }
    for (int i = 1; i <= n; ++i) {
        mp[p[i]] = max(mp[p[i]], rank[i]);
        ++mp2[p[i]];
    }
    // a is the current group
    // b is the number of edges inside that group

    for (auto& [c, d]: mp) {
        if (d != mp2[c] * (mp2[c] - 1)/2) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    // for each group, count its rank
    return 0;

}