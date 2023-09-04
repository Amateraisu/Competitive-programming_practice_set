#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int n, total;
set<int>rooms;
set<int>unavail;
vector<vector<int>>ints;
vector<int>res;
int a, b;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) rooms.insert(i);
    for (int i = 0; i < n ; i++) {
        cin >> a >> b;
        ints.push_back({a, 1});
        ints.push_back({b, -1});
    }
//    cout << ints.size() << '\n';
    auto c = [&](vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    };
    sort(ints.begin(), ints.end(), c);
    for (int i = 0; i < ints.size(); i++) {
        if (ints[i][1] == 1) {
            // use a room
            auto it = rooms.begin();
            int room = *(it);
            // cout << *(it) << '\n';
            unavail.insert(room);
            rooms.erase(room);

            res.push_back(room);
        } else {
            auto it = unavail.begin();
            int room = *(it);
            unavail.erase(room);
            rooms.insert(room);
        }
        total = max(total, int(unavail.size()));
    }
    cout << total << '\n';
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }



    return 0;
}