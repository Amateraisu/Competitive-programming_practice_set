#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

struct node {
    struct node* child[26]{};
    bool isEnd;
    node() {
        isEnd = false;
        fill(begin(child), end(child), nullptr);
    }
};

node* root;

void insert(const string& c) {
    node* ptr = root;
    for (char ch : c) {
        int idx = ch - 'a';
        if (ptr->child[idx] == nullptr) {
            ptr->child[idx] = new node();
        }
        ptr = ptr->child[idx];
    }
    ptr->isEnd = true;
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    root = new node();
    for (int i = 0; i < k; i++) {
        string c;
        cin >> c;
        insert(c);
    }

    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        node* t = root;
        for (int j = i; j < n; j++) {
            int idx = s[j] - 'a';
            if (t->child[idx] == nullptr)
                break;
            t = t->child[idx];
            if (t->isEnd) {
                dp[i] = (dp[i] + dp[j + 1]) % mod;
            }
        }
    }

    cout << dp[0] << endl;
    return 0;
}