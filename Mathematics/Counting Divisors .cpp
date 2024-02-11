#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;


ll x;

vector<int> getPrimes(int n) {
    vector<int>ret;
    for(int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ret.push_back(i);
            n/= i;
        }
    }

    if (n > 1) ret.push_back(n);
    return ret;
}

void test() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res += i * i == n ? 1 : 2;
        }
    }
    std::cout << res << '\n';



}
int main() {
    int n;
    cin >> n;
    while (n--) test();
}