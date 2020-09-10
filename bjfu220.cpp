#include <stdio.h>
#include <cstring>

using namespace std;

struct Book {
    char isbn[100];
    char title[100];
    float price;
};

template<class T>
class ListNode {
public:
    T content;
    ListNode<T> *next = nullptr;
};

int main() {
    auto head = new ListNode<Book>;
    auto current = head;
    int length;
    scanf("%d", &length);
    for (int i = 0; i < length; ++i) {
        auto buffer = new ListNode<Book>;
        scanf("%s%s%f", buffer->content.isbn, buffer->content.title, &(buffer->content.price));
        current->next = buffer;
        current = current->next;
    }
    int find_length;
    scanf("%d", &find_length);
    for (int i = 0; i < find_length; ++i) {
        int location;
        scanf("%d", &location);
        if (location >= 1 && location <= length) {
            auto current = head->next;
            for (int j = 1; j < location; ++j) {
                current = current->next;
            }
            printf("%s %s %.2f\n", current->content.isbn, current->content.title, current->content.price);
        } else {
            printf("Sorry，the book on the best position doesn't exist!\n");
        }
    }
    return 0;
}