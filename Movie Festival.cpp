#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


int n, a, b;
int main() {
    cin >> n;
    vector<vector<int>>movies(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        movies[i] = vector({a, b});
    }
    auto c = [&](vector<int> a, vector<int> b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    };
    sort(movies.begin(), movies.end(), c);
    int res = 0;
`
    int end = -1;
    for (int i = 0; i < n ; i++) {
        auto cur = movies[i];
        if (cur[0] < end) continue;
        end = cur[1];
        res += 1;
    }
    cout << res << '\n';

    return 0;
}