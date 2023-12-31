#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t, a, b;

vector<int> p(int n)
{
    vector<int>res;
    while (n % 2 == 0)
    {
        res.push_back(2);
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            res.push_back(i);
            n = n/i;
        }
    }
    if (n > 2)
        res.push_back(n);
    return res;
}

void test() {
    cin >> a >> b;
    if (a == 1) {
        cout << 1LL * b * b << '\n';
        return ;
    }

    vector<int>big = p(b);
    vector<int>sm = p(a);
    map<int, int>mpb;
    map<int, int>mps;
    for (int x: big) ++mpb[x];
    for (int x: sm) ++mps[x];
    for (auto& [c, d]: mps) {
        mps[c] = max(0, d - mpb[c]);
    }
    ll res = b;
    for (auto& [c, d]: mps) {
        if (c > 0) {
            res *= c * d;
        }
    }
    cout << res <<'\n';



}


int main()
{
    cin >> t;
    while (t--) test();
}


