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
    ListNode<Book> *head = new ListNode<Book>;
    ListNode<Book> *current = head;
    int length;
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        ListNode<Book> *buffer = new ListNode<Book>;
        scanf("%s%s%f", buffer->content.isbn, buffer->content.title, &(buffer->content.price));
        if (buffer->content.price <= 1e-6) {
            break;
        }
        current->next = buffer;
        current = current->next;
    }

    ListNode<Book> *new_head = new ListNode<Book>;
    current = head->next;
    while (current!= nullptr){
        auto temp_current_next = current->next;
        current->next = new_head->next;
        new_head->next = current;
        current = temp_current_next;
    }

    current = new_head->next;
    while (current != nullptr) {
        printf("%s %s %.2f\n", current->content.isbn, current->content.title, current->content.price);
        current = current->next;
    }
    return 0;
}