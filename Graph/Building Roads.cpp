#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll n = 2e5;
ll m;
vector<int>home(n + 1, 0);
int a, b;

int find(int node) {
    if (home[node] != node) home[node] = find(home[node]);
    return home[node];
}

void uf(int c, int d) {
    int p1 = find(c), p2 = find(d);
    if (p1 == p2) return;
    home[p1] = home[p2];
    return;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) home[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        uf(a , b);
    }
    unordered_set<int>s;
    for (int i = 1; i <= n; i++) s.insert(find(home[i]));
//    for (auto x : s) {
//        cout << x << '\n';
//    }
    vector<int>res(s.begin(), s.end());
    int prev = res[0];
    cout << s.size() - 1 << '\n';
    for (int i = 1; i < res.size(); i++) {
        cout << prev << ' ' << res[i] << '\n';
        prev = res[i];
    }

    return 0;
}
