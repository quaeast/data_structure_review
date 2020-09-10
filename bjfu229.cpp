#include <stdio.h>

template<class T>
class ListNode {
public:
    T content;
    ListNode *next;
};

int main() {
    while (true) {
        int length;
        scanf("%d", &length);
        if (length == 0) {
            break;
        }
        auto head = new ListNode<int>;
        auto head_a = new ListNode<int>;
        auto head_b = new ListNode<int>;
        auto current_a = head_a;
        auto current_b = head_b;
        for (int i = 0; i < length; ++i) {
            auto buffer = new ListNode<int>;
            scanf("%d", &(buffer->content));
            if (buffer->content < 0) {
                current_a->next = buffer;
                current_a = current_a->next;
            } else {
                current_b->next = buffer;
                current_b = current_b->next;
            }
        }
        current_a = head_a->next;
        current_b = head_b->next;
        while (current_a != nullptr) {
            printf("%d", current_a->content);
            if (current_a->next != nullptr) {
                printf(" ");
            }
            current_a = current_a->next;
        }
        printf("\n");
        while (current_b != nullptr) {
            printf("%d", current_b->content);
            if (current_b->next!= nullptr){
                printf(" ");
            }
            current_b = current_b->next;
        }
        printf("\n");
    }
    return 0;
}