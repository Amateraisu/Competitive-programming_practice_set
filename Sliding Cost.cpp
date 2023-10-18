#include <bits/stdc++.h>

using namespace std;
constexpr int maxN = 2e5 + 1;
int n, k;
set<pair<int, int>>maxi; // the lower half
set<pair<int, int>>mini; // the upper half
int arr[maxN];

int getMedian() {
    if (maxi.size() + mini.size() == 0) return 0;

    return maxi.rbegin()->first;
}

void balance() {
    // always make sure maxi.size() is greater than or equals to mini
    while (mini.size() > 0 && maxi.size() > 0 && mini.begin()->first < maxi.rbegin()->first) {
        auto ele = mini.begin();
        maxi.insert({ele->first, ele->second});
        mini.erase({ele->first, ele->second});

    }
    while (maxi.size() < mini.size()) {
        auto ele = mini.begin();
        maxi.insert({ele->first, ele->second});
        mini.erase({ele->first, ele->second});

    }
    while (maxi.size() > mini.size() + 1) {
        auto ele = maxi.rbegin();
        mini.insert({ele->first, ele->second});
        maxi.erase({ele->first, ele->second});

    }
    return;

}

void insert(int num, int index) {
    mini.insert({num, index});
    balance();
    return;
}

void remove(int num, int index) {
    if (maxi.find({num, index}) != maxi.end()) {
        maxi.erase({num, index});
    } else if (mini.find({num, index}) != mini.end()) {
        mini.erase({num, index});
    }
    balance();
    return;
}


int cur = 0;
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        // cout << "INDEX2 " << i << '\n';
        insert(arr[i], i);
        cur += arr[i];
        if (maxi.size() + mini.size() > k) {
            remove(arr[i - k], i - k);
            cur -= arr[i - k];
        }
        if (maxi.size() + mini.size() == k) {
            int med = getMedian();
            int ret = cur - med * k;
            printf("%d \n" ,ret);
        }

    }

    return 0;
}