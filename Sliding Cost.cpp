#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;
int n, k;


int main () {

    cin >> n >> k;
    vector<ll>nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int l = 0;
    ll cur = 0;
    for (int r = 0 ; r < n ; r++) {
       cur += nums[r];
       if (l )
    }
    return 0;
}