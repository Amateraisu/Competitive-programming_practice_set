#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;

//vector<int> primeFactors(ll n)
//{
//    vector<int>res;
//    while (n % 2 == 0)
//    {
//        res.push_back(2);
//        n = n/2;
//    }
//
//    for (int i = 3; i <= sqrt(n); i = i + 2)
//    {
//        // While i divides n, print i and divide n
//        while (n % i == 0)
//        {
//            res.push_back(i);
//            n = n/i;
//        }
//    }
//    if (n > 2)
//        res.push_back(n);
//
//    return res;
//}

void test() {
    ll n, k;
    cin >> n >> k;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    ll cur = 1;
    for (int x:nums) cur *= x;
    if (cur > 2023 || ((2023/cur != (int)(2023/cur)))) {
        cout << "NO\n";
        return;
    }
    cout << 2023 / cur << " ";
    for (int i = 1; i < k ; ++i) cout << 1 << ' ';



}

int main() {
    cin >> t;
    while (t--) test();
}
