#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int n;
    cin >> n;
    map<int, int>cnt;
    int res =0 ;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
        if (cnt[x] == 2) ++res;
    }
    cout << res << '\n';

}

int main() {
    int n;
    cin >> n;
    while (n--) test() ;

    return 0;
}
