#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll a, b;
    cin >> a >> b;
    ll evens = a/2;
    ll odds = a - evens;
    if (b <= odds) {
        cout << b * 2LL - 1;
    } else {
        cout << (b - odds) * 2LL;
    }

}