#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct Book {
    char isbn[100];
    char name[100];
    float price;
};

template<class T>
class ListNode {
public:
    T content;
    ListNode<T> *next = 0;
};

int main() {
    auto *head = new ListNode<Book>;
    ListNode<Book> *current = head;
    int length = 0;
    while (true) {
        auto *buffer = new ListNode<Book>;
        scanf("%s%s%f", (*buffer).content.isbn, (*buffer).content.name, &((*buffer).content.price));
        if ((*buffer).content.price <= 1e-6) {
            break;
        }
        length++;
        current->next = buffer;
        current = current->next;
    }
    head = head->next;
    printf("%d\n", length);
    current = head;
    while (current != nullptr) {
        printf("%s %s %.2f\n", (*current).content.isbn, (*current).content.name, (*current).content.price);
        current = current->next;
    }
    return 0;
}