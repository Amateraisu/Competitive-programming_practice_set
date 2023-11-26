#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll n, m;


int main() {
    cin >> n >> m;
    int res = 0;
    while (m != n) {
        if (m > n && m % 2 == 0) {
            m /= 2;
        } else {
            ++m;
        }
        ++res;
    }
    cout << res <<'\n';
    return 0;
}
// using edge = tuple<int, int>; // cost, num
// // MLE
// int main() {


//     scanf("%lld %lld", &n, &m);
//     queue<edge>q;
//     q.push({0, n});
//     while (!q.empty()) {
//         auto f = q.front(); q.pop();
//         int cost = get<0>(f);
//         int cur = get<1>(f);
//         if (cur == m) {
//             printf("%d", cost);
//             return 0;
//         }
//         // bfs first
//         int newCost = cost + 1;
//         int num1 = cur - 1;
//         int num2 = cur * 2;
//         q.push({newCost, num1});
//         q.push({newCost, num2});

//     }

//     return 0;
// }
