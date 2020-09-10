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
        Book *current_book = &book_list[i];
        scanf("%s%s%f", current_book->isbn, current_book->title, &(current_book->price));
    }
    int find_length;
    scanf("%d", &find_length);
    for (int i = 0; i < find_length; ++i) {
        int current_pos;
        scanf("%d", &current_pos);
        if (current_pos < 1 || current_pos > length) {
            printf("Sorry，the book on the best position doesn't exist!\n");
        } else {
            printf("%s %s %.2f\n", book_list[current_pos - 1].isbn, book_list[current_pos - 1].title,
                   book_list[current_pos - 1].price);

        }
    }
}
