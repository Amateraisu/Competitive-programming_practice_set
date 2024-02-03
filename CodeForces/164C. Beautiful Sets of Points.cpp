#include <bits/stdc++.h>

using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    int res;
    int size = min(n , m) + 1;
    // for the points
        for (int x = n, y = 0; y <= m && x >= 0; ++y, --x) {
            std::cout << x << ' ' << y << '\n';
        }


}