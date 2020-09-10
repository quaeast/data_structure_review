#include <cstdio>
#include <cstring>

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    while (true) {
        int m, n;
        scanf("%d%d", &m, &n);
        if (n == m && m == 0) {
            break;
        }
        printf("%d\n", ackermann(m, n));
    }
    return 0;
}

