#include <cstdio>
#include <cstring>

const int MAX_LENGTH = 500;

int main() {
    while (true) {
        char string_a[MAX_LENGTH], string_b[MAX_LENGTH];
        scanf("%s%s", string_a, string_b);
        if (strcmp(string_a, "0") == 0 && strcmp(string_b, "0") == 0) {
            break;
        }
        int length_a = strlen(string_a);
        int length_b = strlen(string_b);
        char circle[length_a][MAX_LENGTH];
        for (int i = 0; i < length_a; ++i) {
            for (int j = 0; j < length_a; ++j) {
                circle[i][j] = string_a[(i + j) % length_a];
            }
        }
        bool is_found = false;
        for (int i = 0; i <= length_b - length_a; ++i) {
            for (int k = 0; k < length_a; ++k) {
                bool is_match = true;
                for (int j = i; j < i + length_a; ++j) {
                    if (circle[k][j - i] != string_b[j]) {
                        is_match = false;
                        break;
                    }
                }
                if (is_match) {
                    is_found = true;
                    break;
                }
            }
            if (is_found) {
                break;
            }
        }
        printf("%s\n", is_found ? "YES" : "NO");
    }
    return 0;
}
