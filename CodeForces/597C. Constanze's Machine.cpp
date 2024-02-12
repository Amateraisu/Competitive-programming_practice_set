#include <bits/stdc++.h>

using namespace std;
int main() {
    std::string s;
    cin >> s;

    // if i see a double u
    // find all occurrences of uu and nn
    vector<int>o;
    int c = 0;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s.substr(i - 1, 2) == "uu" || s.substr(i - 1, 2) == "nn") {
            ++c;
        }
    }

}
