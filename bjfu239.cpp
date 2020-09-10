#include <cstdio>

template<class T>
class ListNode {
public:
    T content;
    ListNode *next;
};

int main() {
    while (true) {
        int number, step;
        scanf("%d%d", &number, &step);
        if (number == 0 || step == 0) {
            break;
        }
        auto head = new ListNode<int>;
        auto current = head;
        for (int i = 1; i <= number; ++i) {
            auto buffer = new ListNode<int>;
            buffer->content = i;
            current->next = buffer;
            current = current->next;
        }
        current->next = head->next;
        while (current != current->next) {
            for (int i = 0; i < step - 1; ++i) {
                current = current->next;
            }
            printf("%d ", current->next->content);
            current->next = current->next->next;
        }
        printf("%d\n", current->content);
    }
    return 0;
}