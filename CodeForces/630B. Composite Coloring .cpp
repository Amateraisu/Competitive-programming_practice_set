#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll t;

set<int> find(int x) {
    set<int>ret;
    while (x % 2 == 0) {
        ret.insert(2);
        x /=2;
    }
    for (int i = 3; i * i < x; i += 2) {
        while (x % i == 0) {
            ret.insert(i);
            x /= i;
        }
    }
    if (x > 2) ret.insert(x);

    return ret;
}

void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin>> nums[i];
    map<int, vector<int>>mp;
    for (auto x : nums) {
        set<int>primes = find(x);
        for (auto& y : primes) {
            mp[y].push_back(x);
        }
    }
    map<int, int>mp2;
    for (auto& [a, b]: mp) {
        mp2[b.size()] = a;
    }
    int color = 1;
    // sort them according to their size
    map<int, int>visited;
    for (auto& [a, b]: mp2) {
        for (int x : mp[b]) {
            if (visited[x] == 0) {
                std::cout << color << ' ';
                visited[x] = color;
                ++color;
            } else {
                std::cout << visited[x] << ' ';
            }
        }
    }
    cout << '\n';





}

int main() {
    cin >> t;
    while (t--) test();
}
