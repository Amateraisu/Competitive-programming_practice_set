#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>nums;
    set<int>s;
    int x;
    while (cin >> x) {
        s.insert(x);
    }
    cout << s.size() << '\n';
    return 0;
}
