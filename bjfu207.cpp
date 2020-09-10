#include <cstdio>
#include <cstring>

const int N = 500;

struct Book {
    char isbn[100];
    char title[100];
    float price;
};


int main() {
    int length;
    Book book_list[N];
    scanf("%d", &length);
    for (int i = 0; i < length; ++i) {
        Book* current_book = &book_list[length-1-i];
        scanf("%s%s%f", current_book->isbn, current_book->title, &(current_book->price));
    }
    for (int i = 0; i < length; ++i) {
        Book current_book = book_list[i];
        printf("%s %s %.2f\n", current_book.isbn, current_book.title, current_book.price);
    }

}

