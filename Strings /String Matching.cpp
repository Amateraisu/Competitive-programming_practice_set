#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string pattern, s, z;
ll c;

int main() {
    cin >> s;
    cin >> pattern;
    z = pattern + "#" + s;
    vector<int>dp(z.length(), 0);
    int l = 0, r = 0;
    dp[0] = 0;
    for (int k = 1; k < dp.size(); k++) {
        if (k > r) {
            l = r = k;
            while (r < dp.size() && z[r] == z[r - l]) r++;
            dp[k] = r - l;
            r--;
        } else {
            int k1 = k - l;
            if (dp[k1] < r- k + 1) {
                dp[k] = dp[k1];
            } else {
                l = k;
                while (r < dp.size() && z[r] == z[r - l]) r++;
                dp[k] = r - l;
                r--;
            }
        }
    }
    for (int i = 0; i < dp.size(); i ++) {
        if (dp[i] == pattern.size()) c++;
    }
    printf("%lld\n", c);




    return 0;
}

