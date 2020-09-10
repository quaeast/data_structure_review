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

    bool push(T insertion){
        top++;
        content[top] = insertion;
    }
};

int main() {
    while (true){
        char buffer_string[100];
        scanf("%s", buffer_string);
        if (strcmp(buffer_string, "0")==0){
            break;
        }
        auto stack = new Stack<char>;
        for (int i = 0; i < strlen(buffer_string); ++i) {
            stack->push(buffer_string[i]);
        }
        bool is_tenet = true;
        for (int i = 0; i < strlen(buffer_string); ++i) {
            char buffer;
            stack->pop(buffer);
            if (buffer!=buffer_string[i]){
                is_tenet = false;
            }
        }
        printf("%s\n",  is_tenet?"YES":"NO");
    }
    return 0;
}

