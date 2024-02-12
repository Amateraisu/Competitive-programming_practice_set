import math

def v(x, l, r):
        return l <= x <= r

def v2(x, l, r):
        return r - l >= x

def test():
        l, r, m = map(int, input().split())
        for q in range(l, r + 1):
                ns = m // q
                remainder1 = m - ns * q
                nb = math.ceil(m / q)
                remainder2 = m - nb * q
                if v2(abs(remainder1), l, r) and ns != 0:
                        # print("smaller")
                        print(q, l + remainder1, l)
                        return
                if v2(abs(remainder2), l, r):
                        print(q, r + remainder2, r)
                        return

def main():
        t = int(input())
        for _ in range(t):
                test()

if __name__ == "__main__":
        main()