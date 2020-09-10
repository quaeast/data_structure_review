#include <cstdio>
#include <cstring>

const int MAX_LENGTH = 500;

// s -> be insert
// t -> insertion
void insert(char *s, char *t, int pos) {
    int length_s = strlen(s);
    int length_t = strlen(t);
    for (int i = length_s - 1; i >= pos; --i) {
        s[length_t + i] = s[i];
    }
    for (int i = 0; i < length_t; ++i) {
        s[i+pos] = t[i];
    }
    s[length_s+length_t] = 0;
}

int main() {
    while (true) {
        int pos;
        scanf("%d", &pos);
        if (pos == 0) {
            break;
        }
        char string_a[MAX_LENGTH], string_b[MAX_LENGTH];
        scanf("%s%s", string_a, string_b);
        insert(string_a, string_b, pos-1);
        printf("%s\n", string_a);
    }
    return 0;
}
