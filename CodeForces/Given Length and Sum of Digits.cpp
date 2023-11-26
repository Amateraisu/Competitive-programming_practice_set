#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll m, s;
constexpr ll INF = 0x3f3f3f3f;

int main() {
    cin >> m >> s;
    string num1;//maximum
    string num2; // minimum
    if (s == 0) {
        if (m == 1) {
            cout << "0 0\n";
            return 0;
        } else {
            cout << "-1 -1\n";
            return 0;
        }
    }
    int temp = s;
    for (int i = 0; i < m; ++i) {
        int maxi = min(9, temp);
        temp -= maxi;
        num1 += maxi + '0';
    }
    if (temp > 0) {
        cout << "-1 -1\n";
        return 0;
    }
    num2 = num1;
    reverse(num2.begin(), num2.end());
    if (num2[0] == '0') {

        int ptr1 = 0;
        while (num2[ptr1] == '0') ptr1++;
        num2[ptr1]--;
        num2[0] = '1';

    }
    cout << num2 << ' ' << num1 << '\n';




    return 0;
}
