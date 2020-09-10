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
        int position;
        scanf("%d", &position);
        auto post_current = head->next;
        for (int i = 0; i < position; ++i) {
            post_current = post_current->next;
        }
        auto pre_current = head->next;
        while (post_current!= nullptr){
            post_current = post_current->next;
            pre_current = pre_current->next;
        }
        printf("%d\n", pre_current->content);
    }
    return 0;
}