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
        current = head->next;
        int max = current->content;
        while (current!= nullptr){
            if (current->content>max){
                max = current->content;
            }
            current = current->next;
        }
        printf("%d\n", max);
    }
    return 0;
}