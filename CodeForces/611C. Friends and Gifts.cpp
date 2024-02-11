#include <bits/stdc++.h>
using namespace std;

constexpr int maxN = 2e5 + 1;
vector<int> v(maxN, 0);

void dfs(int currentNode, vector<int>& noOut, vector<int>& visited, set<pair<int, int>>& avail) {
    if (visited[currentNode]) return; // Prevent infinite recursion
    visited[currentNode] = 1;
    // cout << "current Node " << currentNode << '\n';

    if (noOut[currentNode] == 0 && !avail.empty()) {
        for (auto it = avail.rbegin(); it != avail.rend(); ++it) { // Iterate in reverse to find a suitable node
            if (it->second != currentNode) { // Ensure we do not assign the node to itself
                noOut[currentNode] = it->second;
                // cout << "Assigned " << currentNode << " to " << it->second << "\n";
                avail.erase(next(it).base()); // Correctly erases the element using base() to convert reverse iterator
                break; // Break after assigning to avoid unnecessary iterations
            }
        }
    }

    if (noOut[currentNode] != 0 && noOut[currentNode] != currentNode) { // Proceed if there's a valid, non-self node to go to
        dfs(noOut[currentNode], noOut, visited, avail);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> noOut(n + 1, 0), noIn(n + 1, 0), visited(n + 1, 0);
    set<pair<int, int>> avail;

    for (int i = 1; i <= n; ++i) {
        cin >> noOut[i];
        if (noOut[i] != 0) noIn[noOut[i]] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        if (noIn[i] == 0) {
            avail.insert({noOut[i] == 0 ? 2 : 1, i});
        }
    }

    // Debugging: Print available nodes
    // for (auto& x : avail) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs(i, noOut, visited, avail);
    }

    for (int i = 1; i <= n; ++i) {
        cout << noOut[i] << ' ';
    }
    cout << '\n';
}