#include <stdio.h>

template<class T>
class ListNode {
public:
    T content;
    ListNode *next;
};

int main() {
    while (true) {
        int length_a, length_b;
        scanf("%d%d", &length_a, &length_b);
        if (length_a == length_b && length_a == 0) {
            return 0;
        }
        auto head_a = new ListNode<int>;
        auto head_b = new ListNode<int>;
        auto head_c = new ListNode<int>;
        auto current = head_a;
        for (int i = 0; i < length_a; ++i) {
            auto buffer = new ListNode<int>;
            scanf("%d", &(buffer->content));
            current->next = buffer;
            current = current->next;
        }
        current = head_b;
        for (int i = 0; i < length_b; ++i) {
            auto buffer = new ListNode<int>;
            scanf("%d", &(buffer->content));
            current->next = buffer;
            current = current->next;
        }
        auto current_a = head_a->next;
        auto current_b = head_b->next;
        auto current_c = head_c;
        while (current_a != nullptr && current_b != nullptr) {
            if (current_a->content == current_b->content) {
                current_c->next = current_a;
                current_c= current_c->next;
                current_a = current_a->next;
                current_b = current_b->next;
                current_c->next = nullptr;
            } else if (current_a->content<current_b->content){
                current_a = current_a->next;
            } else{
                current_b = current_b->next;
            }
        }
        current = head_c->next;
        while (current!= nullptr){
            printf("%d", current->content);
            if (current->next!= nullptr){
                printf(" ");
            }
            current = current->next;
        }
        printf("\n");
    }
    return 0;
}