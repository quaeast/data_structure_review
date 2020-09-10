#include <cstdio>

template<class T>
class ListNode{
public:
    T content;
    ListNode *next;
};

template<class T>
T max(T a, T b){
    return a>b?a:b;
}

template<class T>
T find_list_max(ListNode<T> *head){
    if (head== nullptr){
        return 0;
    }
    if (head->next== nullptr){
        return head->content;
    }
    return max(head->content, find_list_max(head->next));
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
        printf("%d\n", find_list_max<int>(head->next));
    }
    return 0;
}
