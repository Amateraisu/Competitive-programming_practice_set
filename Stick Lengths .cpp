#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> sticks(n, 0);
    for (int i = 0; i < n; i++) cin >> sticks[i];
    sort(sticks.begin(), sticks.end());
    int median = sticks[(n - 1)/2];
    ll  res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(sticks[i] - median);
    }
    cout << res << '\n';
    return 0;
}