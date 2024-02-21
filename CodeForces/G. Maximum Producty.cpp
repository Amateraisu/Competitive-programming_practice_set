#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dp[100][2];


ll build(string& s, int i, bool v) {
    if (dp[i][v] != -1) return dp[i][v];
    if (i == s.size()) return 1;
    if (v) {

    } else {

    }


}


int main() {
    ll a, b;
    cin >> a >> b;
    string res;
    for (int i = 0; i < to_string(b).size(); ++i) res += "0";

    build(res, 0, false);


}