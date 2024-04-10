#include <bits/stdc++.h>
using namespace std;

void test() {
    int n, c, d;
    cin >> n >> c >> d;
    map<int, int>cnt;
    for (int i = 0; i < n * n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int start = cnt.begin()->first;
    int col = 0;
    int row = 0;
    int ptr = 0;
    int cur = start;
    for (int i = 0; i < n; ++i) {
        int t = cur;

        for (int j = 0; j < n; ++j) {
            if (cnt[t] == 0) {
                cout << "NO\n";
                return;
            }
            --cnt[t];
            t += d;

        }
        cur += c;
    }
    cout << "YES\n";
    return ;
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
