#include <stdio.h>
#include <cstring>

struct Book {
    char isbn[100];
    char title[100];
    float price;
};


int main() {
    float max_price = 0;
    int length;
    scanf("%d", &length);
    Book *book_list = new Book[length];
    for (int i = 0; i < length; ++i) {
        Book *current_book = &book_list[i];
        scanf("%s%s%f", current_book->isbn, current_book->title, &(current_book->price));
        max_price = max_price >= current_book->price ? max_price : current_book->price;
    }
    int max_num=0;
    for (int i = 0; i < length; ++i) {
        Book *current_book = &book_list[i];
        if (max_price-current_book->price<=1e-6){
            max_num++;
        }
    }
    printf("%d\n", max_num);
    for (int i = 0; i < length; ++i) {
        Book *current_book = &book_list[i];
        if (max_price-current_book->price<=1e-6){
            printf("%s %s %.2f\n", current_book->isbn, current_book->title, current_book->price);
        }
    }
}

