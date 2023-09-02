#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, k, res, l;
map<int, int>mp;
int main() {

    scanf("%d", &n);
    l = 1;
    for (int r = 1; r <= n; r++) {
        scanf("%d", &k);
        if (mp[k]) {
            res = max(res, r-l);
            l = max(l, mp[k]+1);
            mp[k] = r;
        } else {
            res = max(res, r-l+1);
            mp[k] = r;
        }
    }
    res = max(res, n-l+1);
    printf("%d\n", res);
//    return 0;
}
