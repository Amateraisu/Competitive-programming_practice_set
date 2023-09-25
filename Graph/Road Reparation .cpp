#include <bits/stdc++.h>
using namespace std;

using edge = tuple<int, int , int>;
constexpr int maxN = 1e5 + 1;
constexpr int manM = 2e5 + 1;
using ll =long long;
vector<edge>g;
int n, m;
int parents[maxN];
int a, b, c;
ll res = 0;


int find(int node) {
    if (node != parents[node]) {
        parents[node] = find(parents[node]);
    }
    return parents[node];
}



bool uf(int n1, int n2) {
    int p1 = find(n1);
    int p2 = find(n2);
    if (p1 == p2) return false;
    parents[p1] = p2;
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m ;i++) {
        scanf("%d %d %d", &a, &b, &c);
        g.push_back({c, a, b});
    }
    for (int i = 1 ; i<= n; i++) {
        parents[i] = i;
    }
    sort(g.begin(), g.end());
    for (edge e: g) {
        c = get<0>(e);
        a = get<1>(e);
        b = get<2>(e);
        if (uf(a, b)) res+= c;
    }
    unordered_set<int>s;
    for (int i = 1 ; i <= n; i++) {
        s.insert(find(parents[i]));

    }
    if (s.size() > 1)  {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << res <<'\n';



    return 0;
}