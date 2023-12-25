#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t;
constexpr int INF = 0x3f3f3f3f;

int test2(string& c, string& s) {
    int ptr = 0;
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c[ptr]) {
            ++ptr;
            ++res;
        }
        ptr %= 2;
    }
    if (res % 2 != 0) {
        // it is an odd number
        if (c[0] != c[1]) return res - 1;
    }
    return res;
}


vector<string>candidates;

void test() {
    string s;
    cin >> s;
    int ret = INF;
    for (auto& c : candidates) {
        // try this candidate and greedy construct the string
        int res = test2(c, s); // res represents the size of the string formed
        ret = min(ret, (int)s.size() - res);
    }

    cout << ret << '\n';
}

vector<string> get() {
    vector<string> ret;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            string temp = string(2, i + '0');
            temp[1] = j + '0';
            ret.push_back(temp);
        }
    }
    return ret;
}


int main() {
    cin >> t;
    candidates = get();
    while (t--) test();
}