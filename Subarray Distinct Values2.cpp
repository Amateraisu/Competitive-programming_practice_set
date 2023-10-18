#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
constexpr int maxN = 2e5 + 1;
int arr[maxN];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    map<int, int>mp;
    ll res = 0;
    int l = 1;
    int c = 0;
    for (int r = 1; r <= n; r++) {
        mp[arr[r]]++;
        if (mp[arr[r]] == 1) c++;
        while (c > k) {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0) c--;
            l++;
        }
        res += r - l + 1;
    }
    printf("%lld" ,res);

    return 0;
}