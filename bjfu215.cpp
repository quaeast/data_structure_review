#include <cstdio>

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

    ListNode<Book> *max_pre = nullptr;
    ListNode<Book> *new_list_head = new ListNode<Book>;
    ListNode<Book> *new_list_tail = new_list_head;

    while (head->next != nullptr) {
        ListNode<Book> *current_pre = head;
        max_pre = head;
        while (current_pre->next != nullptr) {
            if (max_pre->next->content.price < current_pre->next->content.price) {
                max_pre = current_pre;
            }
            if (current_pre->next != nullptr) {
                current_pre = current_pre->next;
            } else {
                break;
            }
        }
        new_list_tail->next = max_pre->next;
        new_list_tail = max_pre->next;
        max_pre->next = max_pre->next->next;
        new_list_tail->next = nullptr;
    }
    head = new_list_head->next;
    current = head;
    while (current != nullptr) {
        printf("%s %s %.2f\n", (*current).content.isbn, (*current).content.name, (*current).content.price);
        current = current->next;
    }
    return 0;
}