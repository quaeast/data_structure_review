#include <cstdio>
#include <cmath>

template<class T>
class ListNode {
public:
    T content;
    ListNode *next = nullptr;
};

template<class T>
class HashList {
public:
    ListNode<T> **list_array;
    int array_length;

    HashList(int array_length) {
        this->array_length = array_length;
        list_array = new ListNode<T> *[array_length];
        for (int i = 0; i < array_length; ++i) {
            //带空头结点
            list_array[i] = new ListNode<T>;
        }
    }

    void add(T content) {
        int position = content % 13;
        auto temp = list_array[position];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        auto new_node = new ListNode<T>;
        new_node->content = content;
        temp->next = new_node;
    }
};


int main() {
    while (true) {
        int length;
        scanf("%d", &length);
        if (length == 0) {
            break;
        }
        auto *hashList = new HashList<int>(13);
        for (int i = 0; i < length + 1; ++i) {
            int buffer;
            scanf("%d", &buffer);
            hashList->add(buffer);
        }
        for (int i = 0; i < 13; ++i) {
            auto temp = hashList->list_array[i]->next;
            printf("%d", i);
            while (temp != nullptr) {
                printf(" %d", temp->content);
                temp = temp->next;
            }
            printf("\n");
        }
    }
    return 0;
}