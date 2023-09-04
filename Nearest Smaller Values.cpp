#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
using namespace std;
int n;

int main() {
    cin >> n;
    vector<int>nums(n, 0);
    vector<int> res(n , 0);
    for (int i = 0; i < n; i++) cin  >> nums[i];
    stack<pair<int, int>>s;
    for (int i = 0; i < n ; i++) {
        while (!s.empty() && s.top().first >= nums[i]) {

            s.pop();
        }
        if (!s.empty()) {
            res[i] = s.top().second;
        }
        s.push({nums[i], i + 1});
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }



    return 0;
}