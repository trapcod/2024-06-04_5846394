#include <stdio.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// ����Ʈ ����ü ����
typedef struct {
    Node* head;
} DoublyCircularLinkedList;

// ����Ʈ �ʱ�ȭ �Լ�
void initializeList(DoublyCircularLinkedList* list) {
    list->head = NULL;
}

// ����Ʈ ó���� ��� �߰� �Լ�
void addFirst(DoublyCircularLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (list->head == NULL) {
        newNode->next = newNode->prev = newNode;
        list->head = newNode;
    }
    else {
        Node* tail = list->head->prev;
        newNode->next = list->head;
        newNode->prev = tail;
        list->head->prev = tail->next = newNode;
        list->head = newNode;
    }
    printf("����Ʈ ó���� %d �߰���.\n", data);
}

// ����Ʈ �������� ��� �߰� �Լ�
void addLast(DoublyCircularLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (list->head == NULL) {
        newNode->next = newNode->prev = newNode;
        list->head = newNode;
    }
    else {
        Node* tail = list->head->prev;
        newNode->next = list->head;
        newNode->prev = tail;
        tail->next = list->head->prev = newNode;
    }
    printf("����Ʈ �������� %d �߰���.\n", data);
}

// ����Ʈ ó�� ��� ���� �Լ�
void deleteFirst(DoublyCircularLinkedList* list) {
    if (list->head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        return;
    }

    Node* toDelete = list->head;

    if (list->head->next == list->head) {
        list->head = NULL;
    }
    else {
        Node* tail = list->head->prev;
        list->head = list->head->next;
        list->head->prev = tail;
        tail->next = list->head;
    }

    printf("����Ʈ ó������ %d ������.\n", toDelete->data);
    free(toDelete);
}

// ����Ʈ ������ ��� ���� �Լ�
void deleteLast(DoublyCircularLinkedList* list) {
    if (list->head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        return;
    }

    Node* toDelete = list->head->prev;

    if (toDelete->next == toDelete) {
        list->head = NULL;
    }
    else {
        Node* newTail = toDelete->prev;
        newTail->next = list->head;
        list->head->prev = newTail;
    }

    printf("����Ʈ ���������� %d ������.\n", toDelete->data);
    free(toDelete);
}

// ����Ʈ ��� �Լ�
void printList(DoublyCircularLinkedList* list) {
    if (list->head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        return;
    }

    Node* current = list->head;
    printf("����Ʈ: ");
    do {
        printf("-> %d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("(head)");
    printf("\n");
}

// ���� �Լ�
int main() {
    DoublyCircularLinkedList list;
    initializeList(&list);
    int choice, data;

    while (1) {
        printf("\n�޴�:\n");
        printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
        printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
        printf("3. ����Ʈ ó�� ��� ����\n");
        printf("4. ����Ʈ ������ ��� ����\n");
        printf("5. ����Ʈ ����Ʈ\n");
        printf("6. ����\n");
        printf("����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("���� �Է�: ");
            scanf("%d", &data);
            addFirst(&list, data);
            break;
        case 2:
            printf("���� �Է�: ");
            scanf("%d", &data);
            addLast(&list, data);
            break;
        case 3:
            deleteFirst(&list);
            break;
        case 4:
            deleteLast(&list);
            break;
        case 5:
            printList(&list);
            break;
        case 6:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
        }
    }

    return 0;
}
