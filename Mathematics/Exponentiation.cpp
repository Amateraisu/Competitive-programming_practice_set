//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <set>
//#include <map>
//#include <queue>
//using ll = long long;
//using namespace std;
//ll mod = 1e9 + 7;
//
//
//
//ll find(ll a, ll b, ll mod) {
//    if (a == 1 || a == 0) return 1 % mod;
//    ll u = find(a, b/2, mod);
//    u = (u * u) % mod;
//    if (b % 2 != 0) u = (u * a) % mod;
//    return u;
//}
//
//int main() {
//    ll n;
//    ll a, b;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> a >> b;
//        cout << find(a, b, mod) << '\n';
//    }
//
//
//
//    return 0;
//}
#include <iostream>
using ll = long long;
using namespace std;
const ll mod = 1e9 + 7;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        cout << mod_pow(a, b, mod) << '\n';
    }
    return 0;
}

