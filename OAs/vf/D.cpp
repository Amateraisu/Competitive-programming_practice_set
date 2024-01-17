int countLetters(string S, int res = 0) {
    for (auto i = 1, j = 0; i <= S.size(); ++i) {
        if (i == S.size() || S[i] != S[j]) {
            res += (i - j + 1) * (i - j) / 2;
            j = i;
        }
    }
    return res;
}
