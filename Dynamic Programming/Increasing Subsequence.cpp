#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int main() {
    scanf("%d", &n);
    vector<int>arr(n, 0);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    // for every value, always try to replace a value in our sorted set
    set<int>s;
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(arr[i]);
        if (it == s.end()) {
            s.insert(arr[i]);
        } else {
            s.erase(it);
            s.insert(arr[i]);
        }

    }
    printf("%d\n", (int)s.size());


    return 0;
}
