// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

constexpr int maxN = 1e5 + 1;
constexpr int maxM = 2e5 + 1;

int isVisiting[maxN];
int isVisited[maxN];


bool dfs(int u, map<int, vector<int>>& g, vector<int>& st) {
    if (isVisited[u] == 1) {

        if (isVisiting[u] == 1) {
            vector<int>temp;
            // retrieve the current runtime
            while (!st.empty() && st.back() != u) {
                temp.push_back(st.back());
                st.pop_back();
            }
            temp.push_back(u);
            reverse(temp.begin(), temp.end());
            temp.push_back(u);
            cout << temp.size() << '\n';
            for (int x : temp) {
                cout << x << ' ';
            }
            cout << '\n';

            return true;
        }
        return false;
    }
    isVisiting[u] = 1;
    isVisited[u] = 1;
    st.push_back(u);
    for (int v : g[u]) {
        if (dfs(v, g, st)) return true;
    }
    st.pop_back();
    isVisiting[u] = 0;
    return false;

}


int main() {
    int n, m;
    cin >> n >> m;

    map<int, vector<int>>g;
    for (int i = 0; i < m ;++i) {
        // here is the prerequisites
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int>res;
    // it must start with an opening and a closing.

    for (int i = 1; i <= n; ++i) {
        if (!isVisited[i]) {
            if (dfs(i, g, res)) {
                return 0;
            }

        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}

