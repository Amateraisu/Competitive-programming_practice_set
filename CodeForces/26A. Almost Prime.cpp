#include <bits/stdc++.h>
using namespace std;
int n;

vector<int> get(int i, int maxi) {
    vector<int>ret;

    while (i % 2 == 0) {
        ret.push_back(2);
        i/=2;
    }
    for (int j = 3; j * j <= maxi; j += 2) {
        while (i % j == 0) {
            ret.push_back(j);
            i /= j;
        }
    }
    if (i > 2) {
        ret.push_back(i);
    }



    return vector<int>(ret.begin(), ret.end());
}
int main() {
    cin >> n;
    long long res = 0;

    for (int i = 2; i <= n; ++i) {
        vector<int>c = get(i, n);
        if (c.size() == 2) ++res;
    }
    cout << res << '\n';
}
