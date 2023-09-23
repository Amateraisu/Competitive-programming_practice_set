//#include <bits/stdc++.h>
//
//using ll = long long;
//
//using namespace std;
//using node = tuple<ll , int>;
//ll n, m;
//int a, b;
//constexpr ll maxN = 1e5 + 1;
//constexpr ll manM = 2e5 + 1;
//vector<int> g[maxN];
//int p[maxN];
//ll c[maxN];
//
//priority_queue<node, vector<node>, greater<node>>q;
//
//int main() {
//    cin >> n >> m;
//    for (int i = 0; i < m ;i++) {
//        cin >> a >> b;
//        g[a].push_back(b);
//
//    }
//    for (int i = 1; i <= n; i++) {
//        p[i] = -1;
//        c[i] = 0;
//    }
//    p[1] = -1;
//    q.push({0, 1});
//    while (!q.empty()) {
//        node t = q.top();
//        q.pop();
//        int cost = get<0>(t);
//        int v = get<1>(t);
//        if (c[v] < cost) continue;
//        for (auto u : g[v]) {
//            if (cost - 1 < c[u]) {
//                c[u] = cost - 1;
//                p[u] = v;
//                q.push({c[u], u});
//            }
//
//        }
//    }
//    if (p[n] == -1) {
//        cout << "IMPOSSIBLE\n";
//        return 0;
//    }
//    vector<int>res;
//    int ptr = n;
//    while (p[ptr] != -1) {
//        res.push_back(ptr);
//        ptr = p[ptr];
//    }
//    res.push_back(1);
//    reverse(res.begin(), res.end());
//    cout << 1 + c[n] * -1 << '\n';
//    for (auto x : res) {
//        cout << x << ' ';
//    }
//
//    return 0;
//}
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

bool vis[maxN];
int N, M, K, a, b, in[maxN], p[maxN], l[maxN], ans[maxN];
vector<int> G[maxN];
queue<int> Q;

void dfs(int u, int par = 0){
    vis[u] = true;
    for(int v : G[u])
        if(v != par && !vis[v])
            dfs(v, u);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        in[b]++;
    }

    dfs(1);
    if(!vis[N]){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    fill(l+2, l+maxN, -1);
    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            Q.push(i);

    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v : G[u]){
            if(l[u] != -1 && l[v] < l[u]+1){
                l[v] = l[u] + 1;
                p[v] = u;
            }
            in[v]--;
            if(in[v] == 0)
                Q.push(v);
        }
    }

    K = l[N] - l[1];
    printf("%d\n", K+1);
    for(int i = K, u = N; i >= 0; i--){
        ans[i] = u;
        u = p[u];
    }
    for(int i = 0; i <= K; i++)
        printf("%d%c", ans[i], (" \n")[i==K]);
}