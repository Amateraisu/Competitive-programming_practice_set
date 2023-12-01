#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
string s;
int main() {
    cin >> n;
    cin >> s;
    vector<int>nums;
    for (int i = 0; i < n; ++i) {
        if (s[i] - '0' == 4) {
            nums.push_back(3);
            nums.push_back(2);
            nums.push_back(2);
        } else if (s[i] - '0' == 8) {
            nums.push_back(7);
            nums.push_back(2);
            nums.push_back(2);
            nums.push_back(2);
        } else if (s[i] - '0' == 9) {
            nums.push_back(7);
            nums.push_back(3);
            nums.push_back(3);
            nums.push_back(2);
        } else if (s[i] - '0' == 6) {
            nums.push_back(5);
            nums.push_back(3);
        } else if (s[i] != '1' && s[i] != '0') {
            nums.push_back(s[i] - '0');
        }
    }
    auto c = [&](int a, int b) {
        return a > b;
    };
    sort(nums.begin(), nums.end(), c);
    for (int i = 0 ; i < nums.size(); ++i) {
        cout << nums[i];
    }
    cout << '\n';


    return 0;
}
