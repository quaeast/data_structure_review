#include <cstdio>
#include <cstring>

template<class T>
class TreeNode {
public:
    T content;
    TreeNode *left;
    TreeNode *right;
};

template<class T>
void construct_binary_tree(TreeNode<T> *&head) {
    char c = getchar();
    if (c == '0') {
        head = nullptr;
        return;
    }
    head = new TreeNode<T>;
    head->content = c;
    construct_binary_tree(head->left);
    construct_binary_tree(head->right);
}

template<class T>
void swap_binary_tree(TreeNode<T> *&head) {
    if (head == nullptr) {
        return;
    }
    auto temp = head->left;
    head->left = head->right;
    head->right = temp;
    swap_binary_tree(head->left);
    swap_binary_tree(head->right);
}

template<class T>
void pre_order(TreeNode<T> *&head) {
    if (head== nullptr){
        return;
    }
    putchar(head->content);
    pre_order(head->left);
    pre_order(head->right);
}

int main() {
    while (true) {
        TreeNode<int> *head = nullptr;
        construct_binary_tree(head);
        if (head == nullptr) {
            break;
        }
        swap_binary_tree(head);
        pre_order(head);
        getchar();
        putchar('\n');
    }
    return 0;
}
