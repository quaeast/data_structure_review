#include <stdio.h>

const int N = 500;

struct Book {
    char isbn[100];
    char title[100];
    float price;
};

int main() {
    Book book_list[N];
    int length = 0;
    float sum = 0;
    float average = 0;
    while (true) {
        scanf("%s%s%f", book_list[length].isbn, book_list[length].title, &book_list[length].price);
        sum+=book_list[length].price;
        if (book_list[length].isbn[0] == '0' && book_list[length].title[0] == '0' && book_list[length].price < 1e-6) {
            break;
        }
        length++;
    }
    average = sum/length;
    printf("%.2f\n", average);
    for (int i = 0; i < length; ++i) {
        if (book_list[i].price<average){
            book_list[i].price*=1.2;
        } else{
            book_list[i].price*=1.1;
        }

        printf("%s %s %.2f\n", book_list[i].isbn, book_list[i].title, book_list[i].price);
    }

}

