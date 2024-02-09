#include <bits/stdc++.h>
using namespace std;
void test() {
    int n;
    cin >> n;
    vector<string> w;
    int t = 0;
    string s;
    map<char, int>mp;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        t += s.size();
        w.push_back(std::move(s));
    }
    int res = 0;
    // I can try with every single candidate
    auto ok = [&](char c) -> int {
        int ret = 0;
        // if I have to make the current char the highest, which word do I have to remove ?
        // the current char has to be greater than all other characters added together
        int remain = t - mp[c];
        // goal : mp[c] > remain
        if (mp[c] > remain) return w.size();
        // i just need to remove a word

        for (auto& word: w) {
            int other = 0;
            for (auto& ch : word) {
                if (ch != c) ++other;
            }
            int have = word.size() - other;
            if (other > have) return w.size() - 1;
        }

        return 0;

    };
    for (int i = 0; i < 5; ++i) {
        res = max(res, ok('a' + i));
    }


}


int main() {
    int t;
    cin >> t;
    while (t--) test();
}
