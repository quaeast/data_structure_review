#include <cstdio>

template<class T>
class TreeNode {
public:
    T content;
    TreeNode<T> *left;
    TreeNode<T> *right;

    static void construct_binary_tree(TreeNode<T> *&head) {
        char c;
        c = getchar();
        if (c == '0') {
            return;
        }
        head = new TreeNode<char>;
        head->content = c;
        construct_binary_tree(head->left);
        construct_binary_tree(head->right);
    }

    static int max_width(TreeNode<T> *head) {
        int max_depth = 100;
        int width[max_depth];
        for (int i = 0; i < max_depth; ++i) {
            width[i] = 0;
        }
        max_width_0(head, width, 0);
        int max = 0;
        for (int i = 0; i < max_depth; ++i) {
           max = max>width[i]?max:width[i];
        }
        return max;
    }

    static void max_width_0(TreeNode<T> *head, int *width, int depth) {
        if (head == nullptr) {
            return;
        }
        width[depth]++;
        max_width_0(head->left, width, depth + 1);
        max_width_0(head->right, width, depth + 1);
    }
};

int main() {
    while (true){
        TreeNode<char> *head = nullptr;
        TreeNode<char>::construct_binary_tree(head);
        getchar();
        if (head== nullptr){
            break;
        }
        printf("%d\n", TreeNode<char>::max_width(head));
    }
    return 0;
}