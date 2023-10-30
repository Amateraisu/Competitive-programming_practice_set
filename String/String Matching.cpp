#include <bits/stdc++.h>
using namespace std;
string n, m;
int c;
void build(vector<int>& dp, const string& s) {
    int i = 1;
    int j = 0;
    int n =s.size();
    while (i < n) {
        if (s[i] == s[j]) {
            dp[i] = j + 1;
            j++;
            i++;
        } else {

            if (j > 0) {
                j = dp[j - 1];
            } else {
                dp[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> m;

    // build my KMP array
    string newS = m + "#" + n;
    vector<int>dp(m.size() + n.size() + 1, 0);
    build(dp, newS);
    int target = m.size();
    c = 0;
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i] == target) c++;
    }
    cout << c << '\n';




    return 0;
}
