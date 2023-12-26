#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;


int find(std::string& s, int left, int right, char target) {
    if (right - left + 1 == 1) {
        return s[right] == target;
    }
    // split into 2 halfs
    int mid = (right - left)/2 + left;
    int c1 = 0, c2 = 0;

    for (int i = 0; i < mid; ++i) {
        if (s[i] == target) ++c1;
    }
    for (int i = mid ; i < right; ++i) {
        if (s[i] == target) ++c2;
    }
    int res = 0;
    int length = mid + 1;
    if (c1 > c2) {
        res = length - c1;
        res += find(s, mid, right, target + 1);
    } else {
        res = length - c2;
        res += find(s, left, mid, target + 1);
    }
    return res;


}

void test() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    // target = 'a';
    int res = find(s, 0, s.size(), 'a');

    cout<< res << '\n';
}



int main() {
    cin >> t;
    while (t--) test();
}