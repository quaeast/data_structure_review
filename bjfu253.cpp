#include <cstdio>

template<class T>
class ListNode {
public:
    T content;
    ListNode *next;
};


template<class T>
int list_size(ListNode<T> *head) {
    if (head == nullptr) {
        return 0;
    } else {
        return list_size(head->next) + 1;
    }
}

template<class T>
float list_average(ListNode<T> *head, int length) {
    if (length == 0) {
        return 0;
    } else {
        return (head->content + (length - 1) * list_average(head->next, length - 1)) / length;
    }
}

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
        printf("%.2f\n", list_average<int>(head->next, length));
    }
    return 0;
}
