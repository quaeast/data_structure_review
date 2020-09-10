#include <stdio.h>

//22

struct Book{
    char isbn[100];
    char title[100];
    float price;
};


int main(){
    int length;
    scanf("%d", &length);
    Book book_list[length+1];
    for (int i = 0; i < length; ++i) {
        Book* current_book = &book_list[i];
        scanf("%s%s%f", current_book->isbn, current_book->title, &(current_book->price));
    }
    int insert_position;
    scanf("%d", &insert_position);
    insert_position--;
    if (insert_position<0||insert_position>length){
        printf("Sorry，the position to be inserted is invalid!");
    } else{
        for (int i = length; i > insert_position; --i) {
            book_list[i] = book_list[i-1];
        }
        Book *insert_book = &book_list[insert_position];
        scanf("%s%s%f", insert_book->isbn, insert_book->title, &(insert_book->price));
        length++;
        for (int i = 0; i < length; ++i) {
            Book current_book = book_list[i];
            printf("%s %s %.2f\n", current_book.isbn, current_book.title, current_book.price);
        }
    }
    return 0;
}