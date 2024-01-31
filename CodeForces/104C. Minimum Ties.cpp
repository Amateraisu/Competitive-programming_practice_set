#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll t;

void test() {
    int n;
    cin >> n;
    bool tie = (n % 2 == 0);
    map<int, int>mp;// a current node's score
    if (n % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (j - i < n / 2) {
                    std::cout << 1 << ' ';
                } else if (j - i == n/2) {
                    std::cout << 0 << ' ';
                } else {
                    std::cout << -1 << ' ';
                }
            }
        }

    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (j - i <= n / 2) {
                    std::cout << 1 << ' ';
                } else {
                    std::cout << -1 << ' ';
                }
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) test(), cout << '\n';
}