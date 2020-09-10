#include <cstdio>
#include <cstring>

bool is_valid(char *io_string) {
    int sum = 0;
    for (int i = 0; i < strlen(io_string); ++i) {
        if (io_string[i] == 'I') {
            sum++;
        } else if (io_string[i] == 'O') {
            sum--;
        } else {
            return false;
        }
        if (sum < 0) {
            return false;
        }
    }
    return sum==0;
}

int main() {
    while (true) {
        char io_string[300];
        scanf("%s", io_string);
        if (strcmp(io_string, "0") == 0) {
            break;
        }
        printf("%s\n", is_valid(io_string) ? "TRUE" : "FALSE");
    }
    return 0;
}

