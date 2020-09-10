#include <iostream>
#include <cstring>

using namespace std;

const int N = 500;

struct Book {
    char isbn[100];
    char title[100];
    float price;
};

struct ListNode {
    ListNode *next;
    Book item;
};


int main() {
    int length = 0;
    Book* book_list = new Book[N];
    while (true) {
        scanf("%s%s%f", book_list[length].isbn, book_list[length].title, &(book_list[length].price));
        if (book_list[length].isbn[0] == '0' && book_list[length].title[0] == '0' && book_list[length].price - 0 < 1e-6) {
            break;
        }
        length++;
    }
    cout<<length<<'\n';
    for (int i = 0; i < length; ++i) {
        printf("%s %s %.2f\n", book_list[i].isbn, book_list[i].title, book_list[i].price);
    }
    return 0;
}