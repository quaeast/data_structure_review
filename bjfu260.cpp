#include <cstdio>
#include <cstring>


int main() {
    while (true) {
        int m, n;
        scanf("%d%d", &m, &n);
        if (m == 0 && n == 0) {
            break;
        }
        int matrix[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &(matrix[i][j]));
            }
        }
        int added[m * n];
        int pointer = 0;
        bool is_repeat = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < pointer; ++k) {
                    if (matrix[i][j] == added[k]) {
                        is_repeat = true;
                        break;
                    }
                }
                if (is_repeat) {
                    break;
                }
                added[pointer++] = matrix[i][j];
            }
            if (is_repeat) {
                break;
            }
        }
        printf("%s\n", is_repeat ? "YES" : "NO");
    }
    return 0;
}
