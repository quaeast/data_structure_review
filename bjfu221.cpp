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
    int insert_position;
    scanf("%d", &insert_position);
    if (insert_position>=1&&insert_position<=length){
        insert_position--;
        current = head;
        for (int i = 0; i < insert_position; ++i) {
            current = current->next;
        }
        auto *buffer = new ListNode<Book>;
        scanf("%s%s%f", buffer->content.isbn, buffer->content.title, &(buffer->content.price));
        buffer->next = current->next;
        current->next = buffer;
        current = head->next;
        while (current!= nullptr){
            printf("%s %s %.2f\n", current->content.isbn, current->content.title, current->content.price);
            current = current->next;
        }
    } else{
        printf("Sorry，the position to be inserted is invalid!\n");
    }
    return 0;
}