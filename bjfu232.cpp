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
        int begin, end;
        scanf("%d%d", &begin, &end);
        current = head;
        ListNode<int> *begin_pre = nullptr;
        ListNode<int> *end_itself = nullptr;
        while (current->next != nullptr) {
            if (begin_pre== nullptr && current->next->content>=begin){
                begin_pre = current;
            }
            if (current->next->content<=end){
                end_itself = current->next;
            }
            current = current->next;
        }
        begin_pre->next = end_itself->next;
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