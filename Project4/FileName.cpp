#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int n;              // ������ ��ȣ
    char from;          // �����
    char to;            // ������
    char tmp;           // �ӽ� ����
    struct Node* next;  // ���� ��带 ����Ű�� ������
} Node;

Node* createNode(int n, char from, char to, char tmp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->n = n;
    newNode->from = from;
    newNode->to = to;
    newNode->tmp = tmp;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int n, char from, char to, char tmp) {
    Node* newNode = createNode(n, from, to, tmp);
    newNode->next = *top;
    *top = newNode;
}

Node* pop(Node** top) {
    if (*top == NULL) {
        return NULL;
    }
    Node* tempNode = *top;
    *top = (*top)->next;
    return tempNode;
}

void moveTower(int n, char from, char to, char tmp, Node** stack) {
    if (n == 1) {
        push(stack, n, from, to, tmp);
        Node* step = pop(stack);
        printf("���� %d�� %c���� %c�� �̵�\n", step->n, step->from, step->to);
        return;
    }
    moveTower(n - 1, from, tmp, to, stack);
    push(stack, n, from, to, tmp);
    Node* step = pop(stack);
    printf("���� %d�� %c���� %c�� �̵�\n", step->n, step->from, step->to);
    moveTower(n - 1, tmp, to, from, stack);
}

int main() {
    int n = 3; 
    Node* stack = NULL;  
    moveTower(n, 'A', 'C', 'B', &stack);
    return 0;
}
