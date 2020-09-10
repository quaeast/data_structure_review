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
        int target;
        scanf("%d", &target);
        current = head;
        while (current->next!= nullptr){
            if (current->next->content == target){
                current->next = current->next->next;
            } else{
                current = current->next;
            }
        }
        current = head->next;
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