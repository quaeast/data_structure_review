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
    int current_length = length;
    for (int i = 0; i < length; ++i) {
        auto buffer = new ListNode<Book>;
        scanf("%s%s%f", buffer->content.isbn, buffer->content.title, &(buffer->content.price));
        bool is_found_the_same = false;
        auto distinct_current = head->next;
        while (distinct_current != nullptr) {
            if (strcmp(distinct_current->content.isbn, buffer->content.isbn) == 0) {
                current_length--;
                is_found_the_same = true;
                break;
            }
            distinct_current = distinct_current->next;
        }
        if (!is_found_the_same) {
            current->next = buffer;
            current = current->next;
        }
    }
    printf("%d\n", current_length);
    current = head->next;
    while (current != nullptr) {
        printf("%s %s %.2f\n", current->content.isbn, current->content.title, current->content.price);
        current = current->next;
    }
    return 0;
}