
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    long long n;
    int a, b;
    cin >> n;
    map<int, int>mp;
    for (int i = 0; i < n; i++) {
        cin >> a  >> b;
        mp[a]++;
        mp[b]--;

    }
    int res = 0;
    int cur = 0;
    for (auto& [a, b] : mp) {
        cur += b;
        res = max(res, cur);

    }
    cout << res << '\n';


    return 0;
}
