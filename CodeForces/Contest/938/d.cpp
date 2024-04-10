#include <bits/stdc++.h>

using namespace std;


void test() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int>A(a, 0);
    for (int i = 0; i < a; ++i) cin >> A[i];
    vector<int>B(b, 0);
    std::unordered_map<int, int>req, cur;
    for (int i = 0; i < b; ++i) cin >> B[i];
    for (int x : B) {
        req[x]++;
    }
    int have = 0;
    int l = 0;
    int res = 0;
    for (int r = 0; r < a; ++r) {
        cur[A[r]]++;
        if (cur[A[r]] <= req[A[r]]) ++have;
        if (r - l + 1 > b) {
            --cur[A[l]];
            if (cur[A[l]] < req[A[l]]) --have;
            ++l;
        }
        if (have >= k && r - l + 1 == b) {
            // cout << "CAN AT " << r << '\n';
            ++res;
        }
        // cout << r << ' ' << have << '\n';
    }
    cout << res << '\n';

}
int main() {
    int n;
    cin >> n;
    while (n--) test();
}
