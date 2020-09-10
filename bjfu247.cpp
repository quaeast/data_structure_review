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
        return end==begin;
    }

    int is_full(){
        return (end+1)%QUEUE_MAX_LENGTH==begin;
    }

    bool push(T &item) {
        if (is_full()) {
            return false;
        }
        content[end] = item;
        end++;
        return true;
    }

    // not remove
    T peak(){
        return content[begin];
    }

    // remove
    bool pop(){
        if (is_empty()){
            return false;
        } else{
            begin = (begin+1)%QUEUE_MAX_LENGTH;
        }
    }
};

int main() {
    while (true) {
        int length;
        scanf("%d", &length);
        if (length==0){
            break;
        }
        auto queue = new Queue<int>;
        for (int i = 0; i < length; ++i) {
            int buffer;
            scanf("%d", &buffer);
            queue->push(buffer);
        }
        while (!queue->is_empty()){
            printf("%d", queue->peak());
            queue->pop();
            if (!queue->is_empty()){
                printf(" ");
            } else{
                printf("\n");
            }
        }
    }
    return 0;
}

