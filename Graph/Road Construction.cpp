#include <bits/stdc++.h>
using namespace std;

using edge = tuple<int , int>;
constexpr int maxN = 1e5 + 1;
constexpr int manM = 2e5 + 1;
using ll =long long;
vector<edge>g;
int n, m;
int parents[maxN];
ll ranks[maxN];
int a, b, c;
ll res = 0;
ll sz = 0;

int find(int node) {
    while (node != parents[node]) {
        parents[node] = parents[parents[node]];
        node = parents[node];

    }
    return parents[node];
}



long long uf(int n1, int n2) {
    int p1 = find(n1);
    int p2 = find(n2);
    if (p1 == p2) return 0;
    parents[p1] = p2;
    int res= 0;
    if (ranks[p1] > ranks[p2]) {
        parents[p2] = p1;
        ranks[p1] += ranks[p2];
        ranks[p2] = ranks[p1];
        res = ranks[p1];
    } else {
        parents[p1] = parents[p2];
        ranks[p2] += ranks[p1];
        ranks[p1] = ranks[p2];
        res = ranks[p2];
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m ;i++) {
        scanf("%d %d", &a, &b);
        g.push_back({a, b});
    }
    res = n;
    sz = 1;

    for (int i = 1 ; i<= n; i++) {
        parents[i] = i;
        ranks[i] = 1;
    }
    for (edge e: g) {

        a = get<0>(e);
        b = get<1>(e);
        ll r = uf(a, b);
        if (r) {
            res--;
            sz = max(sz, r);
        }
        printf("%lld %lld\n", res, sz);
    }




    return 0;
}
