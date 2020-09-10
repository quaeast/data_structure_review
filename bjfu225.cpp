#include <stdio.h>

template<class T>
class ListNode {
public:
    T content;
    ListNode *next;
};

int main() {
    while (true){
        int length_a, length_b;
        scanf("%d%d", &length_a, &length_b);
        if (length_a==0&&length_b==0){
            return 0;
        }
        auto head_a = new ListNode<int>;
        auto head_b = new ListNode<int>;
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
        auto head_c = new ListNode<int>;
        auto current_a = head_a->next;
        auto current_b = head_b->next;
        auto current_c = head_c;
        while (current_a != nullptr || current_b != nullptr) {
            if (current_a == nullptr) {
                current_c->next = current_b;
                current_b = current_b->next;
                current_c = current_c->next;
                current_c->next = nullptr;
                continue;
            }
            if (current_b == nullptr) {
                current_c->next = current_a;
                current_a = current_a->next;
                current_c = current_c->next;
                current_c->next = nullptr;
                continue;
            }
            if (current_a->content == current_b->content) {
                current_c->next = current_a;
                current_a = current_a->next;
                current_c = current_c->next;
                current_c->next = nullptr;
                current_b = current_b->next;
                continue;
            }
            if (current_a->content < current_b->content) {
                current_c->next = current_a;
                current_a = current_a->next;
                current_c = current_c->next;
                current_c->next = nullptr;
                continue;
            }
            if (current_a->content > current_b->content) {
                current_c->next = current_b;
                current_b = current_b->next;
                current_c = current_c->next;
                current_c->next = nullptr;
                continue;
            }
        }
        current_c = head_c->next;
        // pay attention: there is no space at the ent of the line.
        while (current_c!= nullptr){
            printf("%d" , current_c->content);
            if (current_c->next!= nullptr){
                printf(" ");
            }
            current_c = current_c->next;
        }
        printf("\n");
    }
    return 0;
}