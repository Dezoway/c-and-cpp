#include<stdio.h>
#include<locale.h>
#define SIZE 20
typedef struct _Node {
    char title[SIZE];
    char type[SIZE];
    int price;
    struct _Node *next;//��������� �� ��������� ����
    struct _Node *prev;//��������� �� ���������� ����
} Node;//�������� ���� ������

typedef struct _DLinkedList{
    Node *head;//������ ������
    Node *tail;//����� ������
}DLinkedList;//�������� ������� ������


DLinkedList* createLinkedList();//�������� ������
void showDLList();//�������� ������
void pushNode(DLinkedList *list, void *data);//���������� � ������ ������ ����� ������
void findCorrect(DlinkedList *list);//����� � ������������� ������(����)
void deleteNode(DlinkedList *list);//�������� ������(����)
void saveToFile(DlinkedList *list);//���������� ������ � ����
void loadToList(DlinkedList *list);//�������� ������ �� �����
void exit(DlinkedList *list);//�����




int main(void){
    setlocale(LC_ALL,"Rus");
    int a;
    while(1!=0){
        printf("�������� �������� ��������:\n");
        printf("1. �������� ������.\n");
        printf("2. �������� ������.\n");
        printf("3. ���������� � ������ ����� �������\n");
        printf("4. ����� � ������������� ������ � ������.\n");
        printf("5. �������� ������ �� ������.\n");
        printf("6. ���������� ������ � �����.\n");
        printf("7. �������� ������ �� �����.\n");
        printf("8. �����\n");
        printf("������� �����: ");
        scanf("%d",&a);
        printf("\n");
        switch(a){
        case 1:NULL;break;
        case 2:NULL;break;
        case 3:NULL;break;
        case 4:NULL;break;
        case 5:NULL;break;
        case 6:NULL;break;
        case 7:NULL;break;
        case 8:return 0;
        default: printf("�������� �������\n\n");break;
        }
    }

}
