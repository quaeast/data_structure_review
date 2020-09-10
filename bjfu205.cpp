#include <cstdio>
#include <cstring>

const int N = 500;

struct Book {
    char isbn[100];
    char title[100];
    float price;
};


int main() {
    int length = 0;
    Book *book_list = new Book[N];
    while (true) {
        scanf("%s%s%f", book_list[length].isbn, book_list[length].title, &(book_list[length].price));
        if (book_list[length].isbn[0] == '0' && book_list[length].title[0] == '0' && book_list[length].price <= 1e-6) {
            break;
        }
        length++;
    }

    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (book_list[j].price < book_list[j + 1].price) {
                Book temp = book_list[j];
                book_list[j] = book_list[j + 1];
                book_list[j + 1] = temp;
            }
        }
    }
//    printf("%d\n", length);
    for (int i = 0; i < length; ++i) {
        printf("%s %s %.2f\n", book_list[i].isbn, book_list[i].title, book_list[i].price);
    }
    return 0;
}