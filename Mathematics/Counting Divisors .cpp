#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll n = 1e6 + 1;


ll x;

vector<int> getPrimes(int n) {
    int p = 3;
    vector<int> sieve(n + 1, 1);

    while (p * p <= n) {
        if (sieve[p]) {
            for (int x = p * p; x <= n; x += 2 * p) {
                sieve[x] = 0;
            }
        }
        p += 2;
    }

    vector<int> primes;
    primes.push_back(2);

    for (int i = 3; i <= n; i += 2) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

ll find(ll num, vector<int>& primes) {
    int res = 1;
    for (int i = 0 ; i < primes.size() && primes[i] <= num; i++) {
        int ct = 0;
        while (num % primes[i] == 0) {
            num /= primes[i];
            ct++;
        }
        if (ct > 0) res *= ct + 1;
    }
    return res;
}
int main() {
    vector<int>primes = getPrimes(n + 1);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << find(x, primes) << '\n';
    }
}