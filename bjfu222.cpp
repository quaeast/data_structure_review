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
    int delete_position;
    scanf("%d", &delete_position);
    if (delete_position >= 1 && delete_position <= length){
        delete_position--;
        current = head;
        for (int i = 0; i < delete_position; ++i) {
            current = current->next;
        }
        current->next = current->next->next;
        while (current!= nullptr){
            printf("%s %s %.2f\n", current->content.isbn, current->content.title, current->content.price);
            current = current->next;
        }
    } else{
        printf("Sorry，the position to be deleted is invalid!\n");
    }
    return 0;
}