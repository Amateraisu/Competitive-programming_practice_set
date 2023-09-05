#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;
int n, k;
int main() {
    cin >> n >> k;
    vector<ll>nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    multiset<ll>s1, s2; // smaller, bigger
    int l = 0;
    vector<ll>res;
    for (int r = 0 ; r < n; r++) {
        int t = s1.size() + s2.size() + 1;
        // decide where to push the element in
        if (s2.size() - s1.size() )
        if (t == k) {
            res.push_back(*(s1.rbegin()));
        }

    }



    return 0;
}