//
// Created by admin on 2/9/2023.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int x;

int main() {
    cin >> x;
    vector<int>A(x,0);
    for (int i = 0 ;i < x ; i++) cin >> A[i];
    long long res = -1e9;
    long long cur = 0;
    for (int i = 0; i < x; i++) {
        cur+= A[i];
        res = max(res, cur);
        if (cur < 0) cur = 0;
    }
    cout << res << '\n';
    return 0;
}