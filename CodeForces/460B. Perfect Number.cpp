

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int t = n;
    int last = 10;
    while (n) {
        last -= n % 10;
        n/=10;
    }
    // now i have the last number
    int res = last;
    cout << std::to_string(t) + std::to_string(last) << '\n';

}
