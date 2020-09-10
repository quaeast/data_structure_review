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
        
        while (current_a != nullptr || current_b != nullptr) {
            if (current_a == nullptr) {
                auto head_next_temp = head_c->next;
                head_c->next = current_b;
                current_b = current_b->next;
                head_c->next->next = head_next_temp;
                continue;
            }
            if (current_b == nullptr) {
                auto head_next_temp = head_c->next;
                head_c->next = current_a;
                current_a = current_a->next;
                head_c->next->next = head_next_temp;
                continue;
            }
            if (current_a->content <= current_b->content) {
                auto head_next_temp = head_c->next;
                head_c->next = current_a;
                current_a = current_a->next;
                head_c->next->next = head_next_temp;
                continue;
            }
            if (current_a->content > current_b->content) {
                auto head_next_temp = head_c->next;
                head_c->next = current_b;
                current_b = current_b->next;
                head_c->next->next = head_next_temp;
                continue;
            }
        }
        head_c = head_c->next;
        // pay attention: there is no space at the ent of the line.
        while (head_c!= nullptr){
            printf("%d" , head_c->content);
            if (head_c->next!= nullptr){
                printf(" ");
            }
            head_c = head_c->next;
        }
        printf("\n");
    }
    return 0;
}