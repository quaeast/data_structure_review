#include <cstdio>
#include <cstring>

template<class T>
class ListNode {
public:
    T content;
    ListNode *next;
};


int main() {
    while (true){
        int length, out_length;
        scanf("%d%d", &length, &out_length);
        if (length == 0 && out_length == 0) {
            break;
        }
        auto head = new ListNode<int>;
        auto current = head;
        auto tail = current->next;
        for (int i = 0; i < length; ++i) {
            auto buffer = new ListNode<int>;
            scanf("%d", &(buffer->content));
            current->next = buffer;
            tail = buffer;
            buffer->next = head->next;
            current = current->next;
        }
        for (int i = 0; i < out_length; ++i) {
           printf("%d ", head->next->content);
           if (head->next==tail){
               head->next = nullptr;
               tail = nullptr;
               break;
           }
           tail->next = head->next;
           head->next = head->next->next;
        }
        printf("%d\n", head->next== nullptr?0:1);
    }
    return 0;
}

