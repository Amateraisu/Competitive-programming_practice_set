#include <bits/stdc++.h>
using namespace std;


int main() {
    std::string s;
    cin >> s;
    if (s[0] != '-') {
        cout << s << '\n';
    } else {
        if (s.size() == 2) {
            cout << 0 << '\n';
            return 0;
        }
        int prev1 = (int)(s[s.size() - 1]);
        int prev2 = (int)(s[s.size() - 2]);
        int num = stoi(s);
        // take the bigger number
        if (prev2 > prev1) {
            num /= 10;
            num += num % 10;
            cout << num << '\n';
        } else {
            s = s.substr(0, s.size() - 1);
            cout << s << '\n';
        }


    }
    return 0;
}
