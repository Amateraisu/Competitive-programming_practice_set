#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const ll N = 2e5 + 1;

ll arr[N];


ll find(ll a, ll b) {
    if (b == 0) return a;
    return find(b, a % b);
}

int main() {
    int n, x;
    cin >> n;

    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    int res = find(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        res = find(res, arr[i]);
    }
    cout << res << '\n';





    return 0;
}
