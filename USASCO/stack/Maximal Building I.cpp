#include <bits/stdc++.h>
using namespace std;






int main() {
    int n, m;
    cin >> n >> m;
    vector<string>A;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        A.push_back(s);
    }
    int n2 = n;
    int m2 = m;
    vector<vector<int>>A2(n, vector<int>(m, 0));
    for (int i = 0; i < m; ++i) {
        A2[0][i] = A[0][i] == '.' ? 1 : 0;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            A2[i][j] = A[i][j] == '.' ? A2[i - 1][j] + 1 : 0;
        }
    }
    int res = 0;
    auto get = [](vector<int>& arr) -> int {
        int ret = 0;
        using T = pair<int, int>; // height, index
        stack<T> s;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (!s.empty() && s.top().first > arr[i]) {
                ret = max(ret, (i - s.top().second) * s.top().first);
                j = s.top().second;
                s.pop();
            }
            s.push(make_pair(arr[i], j));
        }
        while (!s.empty()) {
            ret = max(ret,  (int)(arr.size() - s.top().second) * s.top().first);
            s.pop();
        }
        return ret;

    };



    for (auto& a : A2) {
        res = max(res, get(a));
    }
    cout << res << '\n';


}
