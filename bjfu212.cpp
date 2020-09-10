#include <cstdio>

struct Book {
    char isbn[100];
    char title[100];
    float price;
};


int main() {
    int length;
    scanf("%d", &length);
    Book book_list[length];
    for (int i = 0; i < length; ++i) {
        Book* current_book = &book_list[i];
        scanf("%s%s%f", current_book->isbn, current_book->title, &(current_book->price));
    }
    int delete_position;
    scanf("%d", &delete_position);
    delete_position--;
    if (delete_position<0||delete_position>=length){
        printf("Sorry，the position to be deleted is invalid!\n");
        return 0;
    }
    length--;
    for (int i = delete_position; i <length; ++i) {
        book_list[i] = book_list[i+1];
    }
    for (int i = 0; i < length; ++i) {
        Book current_book = book_list[i];
        printf("%s %s %.2f\n", current_book.isbn, current_book.title, current_book.price);
    }
}