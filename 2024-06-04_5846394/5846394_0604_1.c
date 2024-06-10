#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 리스트 구조체 정의
typedef struct {
    Node* head;
} DoublyCircularLinkedList;

// 리스트 초기화 함수
void initializeList(DoublyCircularLinkedList* list) {
    list->head = NULL;
}

// 리스트 처음에 노드 추가 함수
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
    printf("리스트 처음에 %d 추가됨.\n", data);
}

// 리스트 마지막에 노드 추가 함수
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
    printf("리스트 마지막에 %d 추가됨.\n", data);
}

// 리스트 처음 노드 삭제 함수
void deleteFirst(DoublyCircularLinkedList* list) {
    if (list->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
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

    printf("리스트 처음에서 %d 삭제됨.\n", toDelete->data);
    free(toDelete);
}

// 리스트 마지막 노드 삭제 함수
void deleteLast(DoublyCircularLinkedList* list) {
    if (list->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
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

    printf("리스트 마지막에서 %d 삭제됨.\n", toDelete->data);
    free(toDelete);
}

// 리스트 출력 함수
void printList(DoublyCircularLinkedList* list) {
    if (list->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }

    Node* current = list->head;
    printf("리스트: ");
    do {
        printf("-> %d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("(head)");
    printf("\n");
}

// 메인 함수
int main() {
    DoublyCircularLinkedList list;
    initializeList(&list);
    int choice, data;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
        printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
        printf("3. 리스트 처음 노드 삭제\n");
        printf("4. 리스트 마지막 노드 삭제\n");
        printf("5. 리스트 프린트\n");
        printf("6. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("숫자 입력: ");
            scanf("%d", &data);
            addFirst(&list, data);
            break;
        case 2:
            printf("숫자 입력: ");
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
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 시도해주세요.\n");
        }
    }

    return 0;
}
