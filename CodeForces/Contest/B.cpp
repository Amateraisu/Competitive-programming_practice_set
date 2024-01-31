#include <bits/stdc++.h>
using namespace std;


void test() {
    int n;
    cin >> n;
    vector<int>num1(n, 0);
    vector<int>num2(n, 0);
    for (int i = 0; i < n; ++i) cin >> num1[i];
    for (int i = 0; i < n; ++i) cin >> num2[i];
    vector<pair<int, int>>scores;
    for (int i = 0; i < n; ++i) {
        scores.push_back(make_pair(2 * n - num1[i] - num2[i], i));
    }

    sort(scores.begin(), scores.end());
    for (int i = n-  1; i >= 0; --i) {
        std::cout << num1[scores[i].second] << ' ';
    }
    cout << '\n';
    for (int i = n-  1; i >= 0; --i) {
        std::cout << num2[scores[i].second] << ' ';
    }
    cout << '\n';



}


int main() {
    int t;
    cin >> t;
    while (t--) test();
}
