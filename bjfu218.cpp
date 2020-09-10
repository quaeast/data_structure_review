#include <stdio.h>

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
    float max = 0;
    int max_length = 0;
    current = head->next;
    while (current != nullptr) {
        if (current->content.price > max) {
            max = current->content.price;
        }
        current = current->next;
    }
    current = head->next;
    while (current!= nullptr){
        if (current->content.price == max) {
            max_length ++;
        }
        current = current->next;
    }
    printf("%d\n", max_length);
    current = head->next;
    while (current != nullptr) {
        if (current->content.price == max) {
            printf("%s %s %.2f\n", current->content.isbn, current->content.title, current->content.price);
        }
        current = current->next;
    }
    return 0;
}