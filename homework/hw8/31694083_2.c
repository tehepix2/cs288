#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

typedef struct node {
    int tiles[N][N];
    short zero_row, zero_column;
    struct node *next;
    struct node *parent;
} Node;

/* Global states */
Node *start = NULL;
Node *goal = NULL;
Node *succ_nodes[4];
Node *closed_list = NULL;

/* Function prototypes */
Node* initialize(char **argv);
void print_node(const Node *p);
int nodes_same(const Node *a, const Node *b);
Node* clone_node(const Node *src);
void swap_tiles(int r1, int c1, int r2, int c2, Node *p);
void move_up(Node *p);
void move_down(Node *p);
void move_left(Node *p);
void move_right(Node *p);
void expand(Node *sel);
void filter(int i, Node *list);
void reconstruct_and_print(Node *goal_node);

typedef struct qnode {
    Node *state;
    struct qnode *next;
} QNode;

QNode *q_front = NULL, *q_rear = NULL;

void enqueue(Node *p);
Node* dequeue(void);

Node *stack_open = NULL;

int main(int argc, char **argv) {
    if (argc != 18) {
        fprintf(stderr, "Usage: %s [bfs|dfs] idx0 ... idx15\n", argv[0]);
        return 1;
    }

    int use_bfs = strcmp(argv[1], "bfs") == 0;
    int use_dfs = strcmp(argv[1], "dfs") == 0;

    if (!use_bfs && !use_dfs) {
        fprintf(stderr, "First argument must be 'bfs' or 'dfs'\n");
        return 1;
    }

    start = initialize(argv + 1);

    if (use_bfs) {
        enqueue(start);
        int found = 0;

        while (q_front != NULL) {
            Node *sel = dequeue();

            if (nodes_same(sel, goal)) {
                printf("BFS: Goal found!\n");
                reconstruct_and_print(sel);
                found = 1;
                break;
            }

            sel->next = closed_list;
            closed_list = sel;

            expand(sel);

            for (int i = 0; i < 4; i++) {
                filter(i, closed_list);
            }

            for (int i = 0; i < 4; i++) {
                if (succ_nodes[i] != NULL) {
                    enqueue(succ_nodes[i]);
                }
            }
        }

        if (!found) {
            printf("BFS: No solution found.\n");
        }
    } else {
        stack_open = start;
        start->next = NULL;
        int found = 0;

        while (stack_open != NULL) {
            Node *sel = stack_open;
            stack_open = stack_open->next;
            sel->next = NULL;

            if (nodes_same(sel, goal)) {
                printf("DFS: Goal found!\n");
                reconstruct_and_print(sel);
                found = 1;
                break;
            }

            sel->next = closed_list;
            closed_list = sel;

            expand(sel);

            for (int i = 0; i < 4; i++) {
                filter(i, closed_list);
            }

            for (int i = 3; i >= 0; i--) {
                if (succ_nodes[i] != NULL) {
                    succ_nodes[i]->next = stack_open;
                    stack_open = succ_nodes[i];
                }
            }
        }

        if (!found) {
            printf("DFS: No solution found.\n");
        }
    }

    return 0;
}

/* argv[0] here is "bfs"/"dfs" (shifted by main's argv+1 call),
   argv[1..16] are the 16 tile values for the start state */
Node* initialize(char **argv) {
    Node *s = (Node *)malloc(sizeof(Node));
    int idx = 1;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int val = atoi(argv[idx++]);
            s->tiles[r][c] = val;
            if (val == 0) {
                s->zero_row = r;
                s->zero_column = c;
            }
        }
    }
    s->next = NULL;
    s->parent = NULL;

    goal = (Node *)malloc(sizeof(Node));
    int val = 1;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (r == N - 1 && c == N - 1) {
                goal->tiles[r][c] = 0;
                goal->zero_row = r;
                goal->zero_column = c;
            } else {
                goal->tiles[r][c] = val++;
            }
        }
    }
    goal->next = NULL;
    goal->parent = NULL;

    printf("Start state:\n");
    print_node(s);
    printf("Goal state:\n");
    print_node(goal);

    return s;
}

void print_node(const Node *p) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            printf("%2d ", p->tiles[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int nodes_same(const Node *a, const Node *b) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (a->tiles[r][c] != b->tiles[r][c]) {
                return 0;
            }
        }
    }
    return 1;
}

Node* clone_node(const Node *src) {
    Node *n = (Node *)malloc(sizeof(Node));
    memcpy(n->tiles, src->tiles, sizeof(src->tiles));
    n->zero_row = src->zero_row;
    n->zero_column = src->zero_column;
    n->next = NULL;
    n->parent = NULL;
    return n;
}

void swap_tiles(int r1, int c1, int r2, int c2, Node *p) {
    int tmp = p->tiles[r1][c1];
    p->tiles[r1][c1] = p->tiles[r2][c2];
    p->tiles[r2][c2] = tmp;
}

void move_up(Node *p) {
    int r = p->zero_row, c = p->zero_column;
    swap_tiles(r, c, r - 1, c, p);
    p->zero_row = r - 1;
}

void move_down(Node *p) {
    int r = p->zero_row, c = p->zero_column;
    swap_tiles(r, c, r + 1, c, p);
    p->zero_row = r + 1;
}

void move_left(Node *p) {
    int r = p->zero_row, c = p->zero_column;
    swap_tiles(r, c, r, c - 1, p);
    p->zero_column = c - 1;
}

void move_right(Node *p) {
    int r = p->zero_row, c = p->zero_column;
    swap_tiles(r, c, r, c + 1, p);
    p->zero_column = c + 1;
}

void expand(Node *sel) {
    for (int i = 0; i < 4; i++) {
        succ_nodes[i] = NULL;
    }

    if (sel->zero_row > 0) {
        Node *n = clone_node(sel);
        move_up(n);
        n->parent = sel;
        succ_nodes[0] = n;
    }
    if (sel->zero_row < N - 1) {
        Node *n = clone_node(sel);
        move_down(n);
        n->parent = sel;
        succ_nodes[1] = n;
    }
    if (sel->zero_column > 0) {
        Node *n = clone_node(sel);
        move_left(n);
        n->parent = sel;
        succ_nodes[2] = n;
    }
    if (sel->zero_column < N - 1) {
        Node *n = clone_node(sel);
        move_right(n);
        n->parent = sel;
        succ_nodes[3] = n;
    }
}

void filter(int i, Node *list) {
    if (succ_nodes[i] == NULL) {
        return;
    }
    Node *cur = list;
    while (cur != NULL) {
        if (nodes_same(succ_nodes[i], cur)) {
            free(succ_nodes[i]);
            succ_nodes[i] = NULL;
            return;
        }
        cur = cur->next;
    }
}

void enqueue(Node *p) {
    QNode *qn = (QNode *)malloc(sizeof(QNode));
    qn->state = p;
    qn->next = NULL;
    if (q_rear == NULL) {
        q_front = q_rear = qn;
    } else {
        q_rear->next = qn;
        q_rear = qn;
    }
}

Node* dequeue(void) {
    if (q_front == NULL) {
        return NULL;
    }
    QNode *qn = q_front;
    Node *p = qn->state;
    q_front = q_front->next;
    if (q_front == NULL) {
        q_rear = NULL;
    }
    free(qn);
    return p;
}

void reconstruct_and_print(Node *gnode) {
    Node *path[10000];
    int count = 0;
    Node *cur = gnode;

    while (cur != NULL) {
        path[count++] = cur;
        cur = cur->parent;
    }

    printf("Solution path (%d moves):\n", count - 1);
    for (int i = count - 1; i >= 0; i--) {
        print_node(path[i]);
    }
}