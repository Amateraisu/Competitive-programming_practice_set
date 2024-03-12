def dfs(n, m, throwNum, currentPlayer, throws, dp):
    if dp[currentPlayer][throwNum] != -1:
        # already visited here before
        return 0
    if throwNum == m:
        dp[currentPlayer][m] = 1  # mark down who has the ball at the end
        return 1
    res = 0
    distance = int(throws[throwNum][0])  # Convert char to int
    first = (currentPlayer + distance) % n
    second = (currentPlayer - distance + n) % n

    if throws[throwNum][1] == '0':
        # it goes clockwise
        res += dfs(n, m, throwNum + 1, first, throws, dp)
    elif throws[throwNum][1] == '1':
        # it goes anti clockwise
        res += dfs(n, m, throwNum + 1, second, throws, dp)
    else:
        res += dfs(n, m, throwNum + 1, first, throws, dp)
        res += dfs(n, m, throwNum + 1, second, throws, dp)

    dp[currentPlayer][throwNum] = res
    return res


def test():
    n, m, s = map(int, input().split())
    throws = []
    s -= 1
    for _ in range(m):
        a, b = input().split()
        throws.append((a, b))
    dp = [[-1 for _ in range(m + 1)] for _ in range(n + 1)]
    res = dfs(n, m, 0, s, throws, dp)
    print(res)
    for i in range(n):
        if dp[i][m] != -1:
            print(i + 1, end=' ')
    print()


def main():
    t = int(input())
    for _ in range(t):
        test()


if __name__ == "__main__":
    main()