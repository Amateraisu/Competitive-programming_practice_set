#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

int N, a, b, last, dp1[maxN], dp2[maxN];
vector<int> G[maxN];

void dfs(int u, int p) {
    int s1 = 0;
    int s2 = 0;


    for (int v : G[u]) {
        if (v != p) {
            dfs(v, u);
            s2 += max(dp1[v], dp2[v]); // s2 computes the sum excluding this node
        }
    }

    for (int v : G[u]) {
        if (v != p) {
            // dfs(v, u);
            // try to take this edge,
            s1 = max(s1, dp2[v] + 1 + s2 - max(dp1[v] , dp2[v]));
        }
    }

    dp1[u] = s1;
    dp2[u] = s2;
}




int main(){
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1);
    cout << max(dp1[1], dp2[1]) << '\n';

}