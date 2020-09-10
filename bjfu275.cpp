#include <cstdio>
#include <cmath>


class ListNode {
public:
    int content;
    ListNode *next;
};

class AdjacentList {
private:
    static const int max_vertex_num = 200;

    void add_path0(int a, int b) {
        auto new_node = new ListNode;
        new_node->content = b;
        new_node->next = vertex_list[a]->next;
        vertex_list[a]->next = new_node;
    }

public:
    int vertex_num;
    ListNode **vertex_list;

    AdjacentList(int vertex_num) {
        this->vertex_num = vertex_num;
        this->vertex_list = new ListNode *[max_vertex_num];
        for (int i = 1; i < vertex_num + 1; ++i) {
            vertex_list[i] = new ListNode;
        }
    }

    void add_vertex(int vertex) {
        vertex_list[vertex] = new ListNode;
    }

    void add_path(int a, int b) {
        add_path0(a, b);
        add_path0(b, a);
    }

    void show_list() {
        for (int i = 1; i < max_vertex_num; ++i) {
            if (vertex_list[i] == nullptr) {
                continue;
            }
            printf("%d", i);
            auto temp = vertex_list[i]->next;
            while (temp != nullptr) {
                printf(" %d", temp->content);
                temp = temp->next;
            }
            printf("\n");
        }
    }
};

int main() {
    while (true) {
        int vertex_num, path_num;
        scanf("%d%d", &vertex_num, &path_num);
        AdjacentList *adjacentList = new AdjacentList(vertex_num);

        if (vertex_num == 0) {
            break;
        }
        for (int i = 0; i < path_num; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            adjacentList->add_path(a, b);
        }
        int new_vertex;
        scanf("%d", &new_vertex);
        adjacentList->add_vertex(new_vertex);
        adjacentList->show_list();
    }
    return 0;
}