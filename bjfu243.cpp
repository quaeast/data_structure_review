#include <cstdio>
#include <cstring>

const int STACK_MAX_SIZE = 300;

template<class T>
class Stack {
    T content[STACK_MAX_SIZE];
    int top = -1;
public:
    bool is_empty(){
        return top==-1;
    }

    bool pop(T &result){
        if (is_empty()){
            return false;
        }
        result = content[top];
        top--;
        return true;
    }

    void push(T insertion){
        top++;
        content[top] = insertion;
    }
};

int main() {
    while (true){
        int length;
        scanf("%d", &length);
        if (length==0){
            break;
        }
        auto stack = new Stack<int>;
        bool pop_error = false;
        for (int i = 0; i < length; ++i) {
            int buffer;
            scanf("%d", &buffer);
            if (pop_error){
                continue;
            }
            if (buffer==-1){
                if (stack->pop(buffer)){
                    printf("%d\n", buffer);
                } else{
                    printf("POP ERROR\n");
                    pop_error = true;

                }
            } else{
                stack->push(buffer);
            }
        }
    }
    return 0;
}

