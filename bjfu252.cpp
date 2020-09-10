#include <cstdio>

template<class T>
class ListNode{
public:
    T content;
    ListNode *next;
};


template<class T>
int list_size(ListNode<T> *head){
    if (head== nullptr){
        return 0;
    } else{
        return list_size(head->next)+1;
    }
}

int main() {
    while (true){
        int length;
        scanf("%d", &length);
        if (length==0){
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
        printf("%d\n", list_size<int>(head->next));
    }
    return 0;
}
