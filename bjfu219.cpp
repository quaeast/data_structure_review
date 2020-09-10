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
    int favourite_length;
    scanf("%d", &favourite_length);
    for (int i = 0; i < favourite_length; ++i) {
        char buffer[100];
        scanf("%s", buffer);
        int equal_length = 0;
        current = head->next;
        while (current != nullptr) {
            if (strcmp(buffer, current->content.title) == 0) {
                equal_length++;
            }
            current = current->next;
        }
        if (equal_length==0) {
            printf("Sorry，there is no your favourite!\n");
        } else{
            printf("%d\n", equal_length);
            current = head->next;
            while (current != nullptr) {
                if (strcmp(buffer, current->content.title) == 0) {
                    printf("%s %s %.2f\n", current->content.isbn, current->content.title, current->content.price);
                }
                current = current->next;
            }
        }
    }
    return 0;
}