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
        auto current = head;
        for (int i = 0; i < length; ++i) {
            auto buffer = new ListNode<int>;
            scanf("%d", &(buffer->content));
            current->next = buffer;
            current = current->next;
        }
        auto new_head = new ListNode<int>;
        current = head->next;
        while (current != nullptr) {
            auto new_head_next_temp = new_head->next;
            new_head->next = current;
            current = current->next;
            new_head->next->next = new_head_next_temp;
        }
        current = new_head->next;
        while (current != nullptr) {
            printf("%d", current->content);
            if (current->next != nullptr) {
                printf(" ");
            }
            current = current->next;
        }
        printf("\n");
    }
    return 0;
}