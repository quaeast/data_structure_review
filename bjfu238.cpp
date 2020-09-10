#include <cstdio>

template<class T>
class ListNode {
public:
    T content;
    ListNode *next;
};

int abs(int number) {
    return number > 0 ? number : -number;
}

int main() {
    while (true) {
        int length_a, length_b;
        scanf("%d%d", &length_a, &length_b);
        if (length_a == length_b && length_a == 0) {
            break;
        }
        auto head_a = new ListNode<char>;
        auto head_b = new ListNode<char>;
        getchar();
        auto current = head_a;
        for (int i = 0; i < length_a; ++i) {
            auto buffer = new ListNode<char>;
            scanf("%c", &(buffer->content));
            getchar();
            current->next = buffer;
            current = current->next;
        }
        current = head_b;
        for (int i = 0; i < length_b; ++i) {
            auto buffer = new ListNode<char>;
            scanf("%c", &(buffer->content));
            getchar();
            current->next = buffer;
            current = current->next;
        }
        auto long_string = head_a;
        auto short_string = head_b;
        if (length_a < length_b) {
            long_string = head_b;
            short_string = head_a;
        }
        auto current_long = long_string->next;
        auto current_short = short_string->next;
        for (int i = 0; i < abs(length_a - length_b); ++i) {
            current_long = current_long->next;
        }
        char result = 0;
        while (current_long != nullptr) {
            if (current_short->content == current_long->content) {
                if (result==0){
                    result = current_short->content;
                }
            } else {
                result = 0;
            }
            current_long = current_long->next;
            current_short = current_short->next;
        }
        printf("%c\n", result);
    }
    return 0;
}