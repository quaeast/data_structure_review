#include <cstdio>


int main() {
    while (true) {
        int length;
        scanf("%d", &length);
        if (length == 0) {
            break;
        }
        int array[length];
        int result[length];
        int negative[length];
        for (int i = 0; i < length; ++i) {
            scanf("%d", &array[i]);
        }
        int negative_pointer = -1;
        int result_pointer = -1;
        for (int i = 0; i < length; ++i) {
            if (array[i] < 0) {
                negative[++negative_pointer] = array[i];
            } else {
                result[++result_pointer] = array[i];
            }
        }
        for (int j = 0; j <= negative_pointer; ++j) {
            result[j + result_pointer+1] = negative[j];
        }
        for (int i = 0; i < length-1; ++i) {
            printf("%d ", result[i]);
        }
        printf("%d\n", result[length-1]);
    }
    return 0;
}
