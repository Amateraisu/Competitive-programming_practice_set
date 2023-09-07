#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
using ll = long long;
int n, k;

class MedianFinder {
public:
    priority_queue<ll, vector<ll>, less<ll>>smaller; // max heap
    priority_queue<ll, vector<ll>, greater<ll>>greater; // minheap
    MedianFinder() {

    }
    void balance() {

        if (!greater.empty() && smaller.top() > greater.top()) {
            int d = smaller.top();
            smaller.pop();
            greater.push(d);

        }

        while (smaller.size() > greater.size() + 1) {
            int t = smaller.top();
            smaller.pop();
            greater.push(t);
        }
        while (smaller.size() + 1 < greater.size()) {
            int t = greater.top();
            greater.pop();
            smaller.push(t);
        }
    }

    void addNum(ll num) {
        smaller.push((double)num);
        balance();
    }

    ll findMedian() {
        if (smaller.size() == greater.size()) return smaller.top();
        if (smaller.size() < greater.size()) {
            return greater.top();
        }
        return smaller.top();
    }
};

int main() {
    cin >> n >> k;
    vector<ll>nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<ll>res;
    MedianFinder q;
    for (int r = 0 ; r < n; r++) {
        q.addNum(nums[r]);
        if (r - k + 1 >= 0) {
            ll re = q.findMedian();
            res.push_back(re);
        }
    }
    for (int i = 0; i < res.size(); i++) {

    }



    return 0;
}