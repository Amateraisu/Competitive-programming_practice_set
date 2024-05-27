using ll = long long;

static constexpr long long max_h = 1LL << 44;
struct trie {
    trie * n[2] = {};
    void insert(long long val, long long h = max_h) {
        if (h) {
            bool b = (val & h);
            if (n[b] == nullptr)
                n[b] = new trie();
            // if, b is set, then val - b.
            n[b]->insert(val - (b ? h : 0), h >> 1);
        }
    }
    long long maxXor(long long val, long long h = max_h) {
        if (h == 0 || n[0] == nullptr &&  n[1] == nullptr)
            return 0;
        bool b = (val & h);
        if (n[!b] != nullptr)
            return h + n[!b]->maxXor(val - (b ? h : 0), h >> 1);
        return n[b]->maxXor(val - (b ? h : 0), h >> 1);
    }
};

class Solution {
public:
    void getSum(int cur, int p, vector<ll>& sums, map<int, vector<int>>& mp) {
        for (int x : mp[cur]) {
            if (x != p) {
                getSum(x, cur, sums, mp);
                sums[cur] += sums[x];
            }
        }
    }

    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& A) {
        ll res = 0;
        vector<ll> sums(A.begin(), A.end());
        map<int, vector<int>> g;
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        getSum(0, -1, sums, g);
        trie t;
        std::function<void(int, int)> dfs = [&](int cur, int p) {
            res = max(res, t.maxXor(sums[cur]));
            for (int x : g[cur]) {
                if (x != p) dfs(x, cur);
            }
            t.insert(sums[cur]);
        };

        dfs(0, -1);
        return res;
    }
};