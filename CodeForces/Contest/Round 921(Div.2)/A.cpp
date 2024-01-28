#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;


void test() {
    int a, b;
    cin >> a >> b;
    string s;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            s += j + 'a';
        }
    }
    std::cout << s << '\n';

}
int main() {
    cin >> t;
    while (t--) test();
}