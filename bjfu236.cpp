#include <stdio.h>

template<class T>
class ListNode {
public:
    T content;
    ListNode *next;
};

const int HASH = 10000;

int abs(int number) {
    return number > 0 ? number : 0 - number;
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
        int hash_map[HASH];
        for (int i = 0; i < HASH; ++i) {
            hash_map[i] = 0;
        }
        current = head;
        while (current->next != nullptr) {
            if (hash_map[abs(current->next->content)] == 1) {
                current->next = current->next->next;
            } else {
                hash_map[abs(current->next->content)] = 1;
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