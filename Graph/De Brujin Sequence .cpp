class Solution {
public:
    unordered_set<string> seen;
    vector<int> edges;

    void dfs(string u, int k, string& A) {
        for (int i = 0; i < k; i++) {
            string newStr = u + A[i];
            if (seen.find(newStr) == seen.end()) {
                seen.insert(newStr);
                dfs(newStr.substr(1), k, A);
                edges.push_back(i);
            }
        }
    }
    string crackSafe(int n, int k) {
        string A = "";
        for (int i = 0 ; i < k ;i++) {
            A += to_string(i);
        }
        string res = "";
        string start = string(n - 1, A[0]);
        dfs(start, k, A);
        int l = pow(k, n);
        for (int i = 0; i < l ;i++) {
            res += A[edges[i]];
        }
        res += start;
        return res;
    }
};