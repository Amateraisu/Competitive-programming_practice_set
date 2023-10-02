#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxN = 1e5 + 1;
constexpr int maxM = 2e5 + 1;
int n, m , a, b;
int p[maxN];

int find(int node) {
    if (node != p[node]) {
        p[node] = find(p[node]);
    }
    return p[node];
}

void uf(int n1, int n2) {
    int p1 = find(n1);
    int p2 = find(n2);
    if (p1 == p2) return;

    p[p1] = p2;

}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        uf(a, b);
    }
    set<int>s;
    for (int i = 1; i <= n; i++) {
        s.insert(find(p[i]));
    }
    printf("%d\n" ,(int)s.size() - 1);
    vector<int>v(s.begin(), s.end());
    for (int i = 1; i < v.size(); i++) {
        printf("%d %d\n", v[i - 1], v[i]);
    }
    return 0;
}
