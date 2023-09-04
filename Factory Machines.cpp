#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long n , t;

int main() {
    cin >> n >> t;
    vector<int>times(n, 0);
    for (int i = 0; i < n; i++) cin >> times[i];
    long long l = 0;
    long long r = 1e18;
    long long res = 1e18;
    auto valid = [&](long long time) {
        long long cur = 0;
        for (int i = 0; i < n ; i++) {
            cur += min(times[i]/time, (long long)1e9);

        }
        return cur >= t;
    };
    while (l <= r) {
        long long m = l + (r - l)/2;
        if (valid(m)) {
            res = min(res, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << res << '\n';


    return 0;
}