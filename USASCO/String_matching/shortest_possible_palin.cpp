class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    string shortestPalindrome(string s) {
        // find the longest prefix that is also a suffix of the string.
        string s2 = s;
        int n = s.size();
        reverse(s2.begin(), s2.end());
        string s3 = s + "#" + s2;
        vector<int>p = prefix_function(s3);
        for (int i = n + 1; i < p.size(); ++i) {
            cout << p[i] << ' ';
        }
        int sz = p[p.size() - 1];

        return s2.substr(0, n - sz) + s; // concat the missing part


    }
};
