#include <bits/stdc++.h>

using namespace std;

void test() {
    int n;
    cin >> n;
    using T = pair<int, int>;
    vector<T>A;
    vector<T>B;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < 0) {
            B.push_back({x, i});
        } else {
            A.push_back({x, i});
        }
    }
    vector<int>res(n, -1);
    int p1 = 0;
    int p2 = n - 1;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), [](auto& a, auto& b) {
        return a.first > b.first;
    });
    for (auto& a : A) {
        res[a.second] = p1;
        ++p1;
    }
    for (auto& b : B) {
        res[b.second ] = p2;
        --p2;
    }
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
