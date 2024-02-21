#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n;
    cin >> n;
    if (n % 3 == 0) {
        std::cout << "Second\n";
    } else {
        std::cout << "First\n";
    }
}


int main() {
    int n;
    cin >> n;
    while (n--) test();
}