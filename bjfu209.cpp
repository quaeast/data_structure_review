#include <cstdio>
#include <cstring>

struct Book {
    char isbn[100];
    char title[100];
    float price;
};

int main() {
    int length;
    scanf("%d", &length);
    Book* book_list = new Book[length];
    for (int i = 0; i < length; ++i) {
        Book* current_book = &book_list[i];
        scanf("%s%s%f", current_book->isbn, current_book->title, &(current_book->price));
    }
    int favourite_length;
    scanf("%d", &favourite_length);
    for (int i = 0; i < favourite_length; ++i) {
        char current_favourite_title[100];
        int favourite_num = 0;
        int favourite_position[length];
        scanf("%s", current_favourite_title);
        for (int j = 0; j < length; ++j) {
            Book* current_book = &book_list[j];
            if (strcmp(current_favourite_title, current_book->title)==0){
                favourite_position[favourite_num] = j;
                favourite_num++;
            }
        }
        if (favourite_num==0){
            printf("Sorry，there is no your favourite!\n");
            continue;
        }
        printf("%d\n", favourite_num);
        for (int k = 0; k < favourite_num; ++k) {
            Book current_book = book_list[favourite_position[k]];
            printf("%s %s %.2f\n", current_book.isbn, current_book.title, current_book.price);
        }
    }
    return 0;
}