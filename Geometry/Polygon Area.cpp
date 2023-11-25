#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n ;
struct P {
    ll x;
    ll y;
    P():x(0), y(0) {}
    void read() {
        scanf("%lld %lld", &x, &y);
    }
    ll operator * (const P& other) const {
        return x * other.y - y*other.x;
    }
};
m

int main() {
    scanf("%d" , &n);
    ll area = 0;
    vector<P>points(n);
    for (int i = 0; i < n; i++) points[i].read();


    for (int i = 0; i < n; i++) {
        area += points[i] * points[i + 1 == n ? 0 : i + 1];
    }
    cout << abs(area) << '\n';





    return 0;
}
