#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int k, q;
    cin >> k >> q;
    vector<int>A(k, 0);
    for (int i = 0; i < k; ++i) cin >> A[i];
    int mini = *min_element(A.begin(), A.end());
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << min(x, mini - 1) << ' ';
    }
    cout << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test() ;

    return 0;
}
