#include <cstdio>
#include <cstring>


int main() {
    while (true) {
        char my_string[500];
        int hush_map[300];
        scanf("%s", my_string);
        if (strcmp(my_string, "0") == 0) {
            break;
        }
        for (int i = 0; i < 300; ++i) {
            hush_map[i]=0;
        }
        for (int i = 0; i < strlen(my_string); ++i) {
            hush_map[my_string[i]]++;
        }
        for (int i = 0; i < 300; ++i) {
            if (hush_map[i]!=0){
                printf("%c:%d\n", i, hush_map[i]);
            }
        }
    }
    return 0;
}
