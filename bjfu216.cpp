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
    int num = 0;
    float sum = 0;
    while (true) {
        ListNode<Book> *buffer = new ListNode<Book>;
        scanf("%s%s%f", buffer->content.isbn, buffer->content.title, &(buffer->content.price));
        if (buffer->content.price <= 1e-6) {
            break;
        }
        num++;
        sum+=buffer->content.price;
        current->next = buffer;
        current = current->next;
    }
    current = head->next;
    printf("%.2f\n", sum/num);
    while (current!= nullptr){
        current->content.price = current->content.price<sum/num?current->content.price*1.2:current->content.price*1.1;
        printf("%s %s %.2f\n", current->content.isbn, current->content.title, current->content.price);
        current = current->next;
    }
    return 0;
}