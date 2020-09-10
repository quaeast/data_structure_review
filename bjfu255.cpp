#include <cstdio>


// begin=1
bool can_go_out(int matrix[][3], int begin, int target) {
    if (begin == target) {
        return true;
    } else if (begin == 0) {
        return false;
    } else {
        return can_go_out(matrix, matrix[begin - 1][0], target) ||
               can_go_out(matrix, matrix[begin - 1][1], target) ||
               can_go_out(matrix, matrix[begin - 1][2], target);
    }
}

int main() {
    while (true) {
        int length;
        scanf("%d", &length);
        if (length == 0) {
            break;
        }
        int matrix[length][3];
        for (int i = 0; i < length; ++i) {
            scanf("%d%d%d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
        }
        int target;
        scanf("%d", &target);
        printf("%s\n", can_go_out(matrix, 1, target) ? "YES" : "NO");
    }
    return 0;
}
