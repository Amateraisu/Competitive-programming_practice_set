#include <bits/stdc++.h>
using namespace std;

int n;
vector<char>res;
unordered_set<string>vis;



void dfs(string u, int k, string& A) {

    for (int i = 0; i < k ; i++) {
        string cur = u;
        cur += A[i];
        if (vis.find(cur) == vis.end()) {
            vis.insert(cur);
            dfs(cur.substr(1), k, A);
            res.push_back(A[i]);
        }
    }
}

int main() {
    scanf("%d", &n);

    string A = "01";
    string start = string(n - 1, A[0]);
    dfs(start, 2, A);
    int l = pow(2, n);
    string ret = "";

    for (int i = 0; i < l; i++) {
        ret += res[i];
    }

    ret += start;
    for (int i = 0; i < ret.size() ;i++) {
        printf("%c", ret[i]);
    }
    return 0;
}
