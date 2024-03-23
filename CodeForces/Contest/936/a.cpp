#include <bits/stdc++.h>
using namespace std;

void test() {
    int n;
    cin >> n;
    vector<int>A(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    int med = A[(A.size() + 2 - 1)/2];
    map<int, int>mp;
    for (int x : A) {
        mp[x]++;
    }
    cout << mp[med] << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
