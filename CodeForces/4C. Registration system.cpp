#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    string s;
    map<string ,int>mp;
    while (n--) {
        cin >> s;
        if (mp[s] == 0) {
            std::cout << "OK\n";
            ++mp[s];
        } else {
            std::cout << s +  std::to_string(mp[s]) << '\n';
            ++mp[s];
        }
    }
}