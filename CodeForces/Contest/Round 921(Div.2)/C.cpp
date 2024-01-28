#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 972663749;
constexpr int A = 911382323;
ll t;
vector<string>candidates;
void generate(int currentIndex, int limit, int endIndex, string&& current, string& given) {
    if (currentIndex == endIndex) {
        candidates.push_back(current);
        return;
    }

    for (int i = 0; i < limit; ++i) {
        char c = 'a' + i;
        generate(currentIndex + 1, limit, endIndex, current + c, given);

    }
    return;

}

void test() {
    int n, k , m;
    std::string s;
    cin >> n >> k >> m;
    cin >> s;
    generate(0, k, n, "", s);
    // at every point in the array, is there a subsequence which cannot be generated ?
}
int main() {
    cin >> t;
    while (t--) test();
}
