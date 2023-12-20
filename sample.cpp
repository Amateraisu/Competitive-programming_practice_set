#include <bits/stdc++.h>

using namespace std;


struct node {
    node* child[26];
    bool isEnd;
    string word;
    node() {
        isEnd = false;
        for (auto& c: child) c= nullptr;
        word = "";
    }
};

struct Trie {
    node* root;
public:
    Trie(): root(new node()) {}
    void insert(string s) {
        node* start = root;
        for (auto& c: s) {
            int index = c - 'a';
            if (start->child[index] == nullptr) {
                start->child[index] = new node();
            }
            start = start->child[index];
        }
        start->isEnd = true;
        start->word = s;
    }
    void dfs(vector<string>& res, node* ptr) {
        if (ptr->isEnd) res.push_back(ptr->word);
        if (res.size() > 3) return;
        for (int i = 0; i < 26; ++i) {
            if (ptr->child[i] != nullptr) {
                dfs(res, ptr->child[i]);
            }
        }
    }
    vector<string> query(std::string q) {
        // only consider the lexicographically smallest 3 products
        node* ptr = root;
        for (auto& c : q) {
            int index = c - 'a';
            if (ptr->child[index] == nullptr) {
                return {};
            }
            ptr = ptr->child[index];
        }
        // now then start checking how many total possible words there are with a dfs
        vector<string>res;

        dfs(res, ptr);


        return res;
    }
};

int main() {
    Trie* t = new Trie();
    vector<string> words = {"carpet", "cart", "car", "camera", "crate"};
    for (auto& w: words) t->insert(w);
    vector<string>res = t->query("ca");
    for (auto& w : res) {
        cout << w << '\n';
    }

}