

#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m ,k;
    cin >> n >> m >> k ;
    vector<int>applicants(n, 0);
    vector<int>houses(m, 0);
    for (int i = 0; i < n;i++) cin >>  applicants[i];
    for (int j = 0; j < m; j++) cin >> houses[j];
    int i = 0, j = 0, res = 0;
    sort(applicants.begin(), applicants.end());
    sort(houses.begin(), houses.end());
    while (i < n && j < m) {
        int app = applicants[i];
        int h = houses[j];
        if (abs(app - h) <= k) {
            // found a matching house.
            i++;
            j++;
            res++;
        } else if (app < h) {
            i++;
        } else {
            j++;
        }

    }

    cout << res;





    return 0;
}
