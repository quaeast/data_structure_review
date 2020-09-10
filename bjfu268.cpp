#include <cstdio>

template<class T>
class TreeNode {
public:
    T content;
    TreeNode<T> *left;
    TreeNode<T> *right;

    static void construct_binary_tree(TreeNode<T> *&head) {
        char c = getchar();
        if (c == '0') {
            return;
        }
        head = new TreeNode<char>;
        head->content = c;
        construct_binary_tree(head->left);
        construct_binary_tree(head->right);
    }

    static void show_path(TreeNode<T> *head, char *char_path, int depth) {
        if (head == nullptr) {
            return;
        }
        char_path[depth] = head->content;
        if (head->left == nullptr && head->right == nullptr) {
            for (int i = 0; i < depth + 1; ++i) {
                printf("%c", char_path[depth - i]);
            }
            printf("\n");
        }
        show_path(head->left, char_path, depth + 1);
        show_path(head->right, char_path, depth + 1);
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
        char *char_path = new char[100];
        TreeNode<char>::show_path(head, char_path, 0);
    }
}