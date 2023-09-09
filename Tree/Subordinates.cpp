#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
int n;


int dfs(vector<int>& res, int cur, vector<vector<int>>&subs) {
    if (res[cur] != 0) return res[cur];
    int e = 0 ;

    for (auto x : subs[cur]) {
        e += dfs(res, x, subs);
    }
    res[cur] = e;
    return e + 1;
}
int main() {
    cin >> n;
    vector<int>A(n + 1, 0); // 0 means no direct boss
    for (int i = 2; i <=n; i++) {
        cin >> A[i];
    }
    vector<vector<int>>subs(n + 1);
    for (int i = 1; i <= n; i++) {
        subs[A[i]].push_back(i);
    }
    vector<int>res(n + 1, 0);
    dfs(res, 1, subs);
    for (int i = 1 ; i <= n ; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}
