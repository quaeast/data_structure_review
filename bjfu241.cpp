#include <cstdio>

typedef struct {
    int top[2], bot[2];
    int *V;
    int m;
} DblStack;

void stack_init(DblStack &stack, int length) {
    stack.m = length;
    stack.V = new int[length];
    stack.top[0] = -1;
    stack.bot[0] = -1;
    stack.top[1] = length;
    stack.bot[1] = length;
}

bool stack_is_full(DblStack stack) {
    return stack.bot[0] + 1 == stack.bot[1];
}

bool stack_is_empty(DblStack stack, int select) {
    return stack.bot[select] == stack.top[select];
}

// select = 0/1;
bool stack_push(DblStack &stack, int content, int select) {
    if (stack_is_full(stack)) {
        return false;
    }
    stack.bot[select] += select == 0 ? 1 : -1;
    stack.V[stack.bot[select]] = content;
    return true;
}

int stack_pop(DblStack &stack, int select) {
    int result = stack.V[stack.bot[select]];
    stack.bot[select] += select == 0 ? -1 : 1;
    return result;
}

int main() {
    while (true) {
        int length;
        scanf("%d", &length);
        if (length == 0) {
            break;
        }
        DblStack stack;
        stack_init(stack, length);
        int length_a, length_b;
        scanf("%d%d", &length_a, &length_b);
        int pop_a, pop_b;
        scanf("%d%d", &pop_a, &pop_b);
        for (int i = 0; i < length_a; ++i) {
            int buffer;
            scanf("%d", &buffer);
            stack_push(stack, buffer, 0);
        }
        for (int i = 0; i < length_b; ++i) {
            int buffer;
            scanf("%d", &buffer);
            stack_push(stack, buffer, 1);
        }
        printf("%d\n", stack_is_full(stack) ? 1 : 0);
        for (int i = 0; i < pop_a; ++i) {
            printf("%d ", stack_pop(stack, 0));
        }
        printf("%d\n", stack_is_empty(stack, 0) ? 0 : 1);
        for (int i = 0; i < pop_b; ++i) {
            printf("%d ", stack_pop(stack, 1));
        }
        printf("%d\n", stack_is_empty(stack, 1) ? 0 : 1);
    }
    return 0;
}