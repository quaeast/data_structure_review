#include <cstdio>
#include <cstring>

struct Book {
    char isbn[100];
    char name[100];
    float price;
};

int main() {
    int n;
    scanf("%d", &n);
    Book book_list[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s%s%f", book_list[i].isbn, book_list[i].name, &(book_list[i].price));
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(book_list[i].isbn, book_list[j].isbn) == 0) {
                n--;
                for (int k = j; k < n; ++k) {
                    book_list[k]=book_list[k+1];
                }
            }
        }
    }
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%s %s %.2f\n", book_list[i].isbn, book_list[i].name, book_list[i].price);
    }
}   