#include <bits/stdc++.h>
using namespace std;

void test() {
    int n;
    cin>>n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int>w(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        w[nums[i]] = i;
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }
    int have = 0;
    int p1, p2;
    p1 = (n + 1)/2;
    p2 = (n + 2)/2;
    // p1 and p2 are the starting numbers.
    int maxi = (n + 1)/2;

    while (p1 >= 1 && (p1 == p2 || w[p1] < w[p1 + 1] && w[p2 - 1] < w[p2])) {
        --maxi;
        --p1;
        ++p2;
    }
    std::cout << maxi << '\n';


}



int main() {
    int t;
    cin >> t;
    while (t--) test();
}
