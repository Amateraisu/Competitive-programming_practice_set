
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x ;
    vector<int>weights(n, 0);
    for (int i = 0; i < n ; i++)  cin>> weights[i];
    int l = 0;
    int r = n - 1;
    sort(weights.begin(), weights.end());
    // maximum weight is x,
    // if the current pair doesnt match or exceed, give the gondola to the maximum one
    int res= 0;
    while (l <= r) {
        int left = weights[l], right = weights[r];
        if (l == r) right = 0;
        if (left + right <= x) {
            r--;
            l++;
        } else {
            r--;
        }
        res++;

    }
    cout << res;


    return 0;
}