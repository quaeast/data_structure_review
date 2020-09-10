#include <cstdio>

template<class T>
class TreeNode {
public:
    T content;
    TreeNode *left;
    TreeNode *right;

    static void construct_binary_tree(TreeNode<T> *&head) {
        char c = getchar();
        if (c == '0') {
            return;
        }
        head = new TreeNode<T>;
        head->content = c;
        construct_binary_tree(head->left);
        construct_binary_tree(head->right);
    }

    static void dual_order_travel(TreeNode<T> *head) {
        if (head == nullptr) {
            return;
        }
        printf("%c", head->content);
        dual_order_travel(head->left);
        printf("%c", head->content);
        dual_order_travel(head->right);
    }
};


int main() {
    while (true) {
        TreeNode<char> *head = nullptr;
        TreeNode<char>::construct_binary_tree(head);
        getchar();
        if (head == nullptr) {
            break;
        }
        TreeNode<char>::dual_order_travel(head);
        putchar('\n');
    }
    return 0;
}