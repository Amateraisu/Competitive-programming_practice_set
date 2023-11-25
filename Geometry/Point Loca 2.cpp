#include <bits/stdc++.h>
using ll = long long;
int t;
ll x_1, y_1, x_2, y_2, x_3, y_3;

ll prod() {
    return x_2 * y_3 - y_2*x_3;
}



ll find() {

    x_2 -= x_1;
    x_3 -= x_1;
    y_2 -= y_1;
    y_3 -= y_1;
    return prod();
}


int main() {
    scanf("%d", &t);
    for (int i = 0; i < t ; i++) {
        std::cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
        ll res = find();
        if (res < 0) {
            printf("RIGHT\n");
        } else if (res > 0) {
            printf("LEFT\n");
        } else {
            printf("TOUCH\n");
        }
    }

    return 0;
}