#include <stdio.h>


int main() {
    while (true) {
        int length;
        scanf("%d", &length);
        if (length == 0) {
            break;
        }
        int array_a[length];
        int array_b[length];
        for (int i = 0; i < length; ++i) {
            scanf("%d", &array_a[i]);
        }
        for (int i = 0; i < length; ++i) {
            scanf("%d", &array_b[i]);
        }
        int pointer_a = 0;
        int pointer_b = 0;
        int result;
        for (int i = 0; i < length; ++i) {
            if (array_a[pointer_a] < array_b[pointer_b]) {
                result = array_a[pointer_a];
                pointer_a++;
            } else{
                result = array_b[pointer_b];
                pointer_b++;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}