#include <bits/stdc++.h>
using namespace std;


void test() {
    int n;
    cin >> n;
    bool f = true;
    string s1;
    string s2;
    for (int i = 0; i < n; ++i) {
        s1 = "";
        s2 = "";

        bool f2 = f;

        for (int j = 0; j < n; ++j) {
            if (f2) {
                s1 += "##";
                s2 += "##";
                f2 = false;
            } else {
                s1 += "..";
                s2 += "..";
                f2 = true;
            }
        }
        f = !f;
        cout << s1 << '\n';
        cout << s2 << '\n';
    }
}






int main() {
    int n;
    cin >> n;
    while (n--) test();
}
