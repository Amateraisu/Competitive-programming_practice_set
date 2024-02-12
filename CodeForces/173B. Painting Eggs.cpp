#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a, b;

    int l = 0;
    int r = 0;
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (tot + a> 500) {
            tot -= b;
            cout <<"G";
        } else {
            tot += a;
            cout << "A";
        }
    }
    cout << "\n";



}
