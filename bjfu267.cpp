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

    static int get_max_depth(TreeNode<T> *head) {
        int max_depth = 0;
        get_max_depth_0(head, 0, max_depth);
        return max_depth;
    }

    static void get_max_depth_0(TreeNode<T> *head, int depth, int &max_depth) {
        if (head == nullptr) {
            max_depth = depth > max_depth ? depth : max_depth;
            return;
        }
        get_max_depth_0(head->left, depth + 1, max_depth);
        get_max_depth_0(head->right, depth + 1, max_depth);
    }

    static void get_longest_path(TreeNode<T> *head, char *longest_path) {
        int max_depth = get_max_depth(head);
        get_longest_path_0(head, longest_path, 0, max_depth);
        longest_path[max_depth] = 0;
    }

    static bool get_longest_path_0(TreeNode<T> *head, char *longest_path, int depth, int max_depth) {
        if (head == nullptr) {
            return depth == max_depth;
        }
        longest_path[depth] = head->content;
        return get_longest_path_0(head->left, longest_path, depth + 1, max_depth) ||
               get_longest_path_0(head->right, longest_path, depth + 1, max_depth);
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
        int max_depth = TreeNode<char>::get_max_depth(head);
        char *longest_path = new char[max_depth + 1];
        TreeNode<char>::get_longest_path(head, longest_path);
        printf("%d\n%s\n", max_depth, longest_path);
    }
    return 0;
}