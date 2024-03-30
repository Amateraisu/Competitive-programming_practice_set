#include <bits/stdc++.h>
using ll = long long;
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int>A(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> A[i];

    stack<pair<int, int>>s;
    for (int i = 1; i <= n; ++i) {
        if (s.empty()) {
            cout << 0 << ' ';
            s.push(make_pair(i, A[i]));

        } else if (s.top().second < A[i]) {
            cout << s.top().first << ' ';
            s.push(make_pair(i, A[i]));
        } else {
            while (!s.empty() && s.top().second >= A[i]) {
                s.pop();

            }
            if (!s.empty()) {
                cout << s.top().first << ' ';
            } else {
                cout << 0 << ' ';
            }
            s.push(make_pair(i, A[i]));
        }
    }
    return 0;
}