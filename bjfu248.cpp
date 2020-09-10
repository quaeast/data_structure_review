#include <cstdio>
#include <cstring>

template<class T>
class Queue {
private:
    static const int QUEUE_MAX_LENGTH = 300;
    T content[QUEUE_MAX_LENGTH];
    int begin = 0;
    int end = 0;
public:
    int size() {
        return end - begin;
    }

    int is_empty() {
        return end == begin;
    }

    int is_full() {
        return (end + 1) % QUEUE_MAX_LENGTH == begin;
    }

    bool push(T &item) {
        if (is_full()) {
            return false;
        }
        content[end] = item;
        end = (end + 1) % QUEUE_MAX_LENGTH;
        return true;
    }

    bool push_rev(T &item) {
        if (is_full()) {
            return false;
        }
        begin = (begin - 1 + QUEUE_MAX_LENGTH) % QUEUE_MAX_LENGTH;
        content[begin] = item;
        return true;
    }

    // not remove
    T peak() {
        return content[begin];
    }

    T peak_rev() {
        return content[(end - 1 + QUEUE_MAX_LENGTH) % QUEUE_MAX_LENGTH];
    }

    // remove
    bool pop() {
        if (is_empty()) {
            return false;
        } else {
            begin = (begin + 1) % QUEUE_MAX_LENGTH;
        }
    }

    bool pop_rev() {
        if (is_empty()) {
            return false;
        } else {
            end = (end-1+QUEUE_MAX_LENGTH)%QUEUE_MAX_LENGTH;
        }
    }


};

int main() {
    while (true) {
        int length;
        scanf("%d", &length);
        if (length == 0) {
            break;
        }
        auto queue = new Queue<int>;
        for (int i = 0; i < length; ++i) {
            int buffer;
            scanf("%d", &buffer);
            queue->push_rev(buffer);
        }
        while (!queue->is_empty()) {
            printf("%d", queue->peak_rev());
            queue->pop_rev();
            if (!queue->is_empty()) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}

