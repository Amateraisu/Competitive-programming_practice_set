#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n;


int main() {
    cin >> n;
    vector<int>A(n, 0);

    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    long long cur = 1;
    for (int i = 0; i < n ; i++) {
        if (cur <A[i]) {
            cout << cur << '\n';
            return 0;
        }
        cur += A[i];
    }
    cout << cur << '\n';
    return 0;
}
