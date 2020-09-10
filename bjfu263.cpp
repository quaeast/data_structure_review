#include <cstdio>
#include <cstring>

template<class T>
class TreeNode {
public:
    T content;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

template<class T>
int construct_bin_tree(TreeNode<T> *&head, T *content_array, int pos) {
    if (content_array[pos] == '0') {
        head = nullptr;
        return pos + 1;
    }
    head = new TreeNode<T>;
    head->content = content_array[pos];
    pos++;
    pos = construct_bin_tree(head->left, content_array, pos);
    pos = construct_bin_tree(head->right, content_array, pos);
    return pos;
}

template<class T>
bool bin_tree_compare(TreeNode<T> *head_a, TreeNode<T> *head_b) {
    if (head_a == nullptr && head_b == nullptr) {
        return true;
    } else if (head_a == nullptr || head_b == nullptr) {
        return false;
    } else if (head_a->content != head_b->content) {
        return false;
    } else {
        return bin_tree_compare(head_a->left, head_b->left) && bin_tree_compare(head_a->right, head_b->right);
    }
}

int main() {
    while (true) {
        char string_a[500];
        char string_b[500];
        scanf("%s", string_a);
        if (strcmp(string_a, "0") == 0) {
            break;
        }
        scanf("%s", string_b);
        auto head_a = new TreeNode<char>;
        auto head_b = new TreeNode<char>;
        construct_bin_tree(head_a, string_a, 0);
        construct_bin_tree(head_b, string_b, 0);
        printf("%s\n", bin_tree_compare<char>(head_a, head_b) ? "YES" : "NO");
    }
    return 0;
}
