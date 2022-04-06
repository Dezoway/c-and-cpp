#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
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
    size_t size;//������ ������
}DLinkedList;//�������� ������� ������

DLinkedList* createLinkedList();//�������� ������
void showDLList();//�������� ������
void pushNode(DLinkedList* list);//���������� ����� ������
void insertIn(DLinkedList* list,Node* tmp);//������� ������ � ������ �� �����������
int findCorrect(DLinkedList* list, char* title);//����� � ������������� ������(����)
//void deleteNode(DLinkedList *list);//�������� ������(����)
//void saveToFile(DLinkedList *list);//���������� ������ � ����
//void loadToList(DLinkedList *list);//�������� ������ �� �����
//void exit(DLinkedList *list);//�����
int main(void){
    setlocale(LC_ALL,"Rus");
    int a;
    char title[SIZE];
    DLinkedList *list = NULL;
    while(1!=0){
        system("cls");
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
        switch(a){
        case 1:{
            list = createLinkedList();
            system("cls");
            printf("������ ������\n");
            system("pause");
            break;
        }
        case 2:
            system("cls");
            if (list != NULL){
            showDLList(list);
            }
            else{
                printf("������� �� ����������. ��������� ������ ������� �� ����� ���� �������� ������ �  �������� �������� �������\n");
                system("pause");
            }
            ;break;
        case 3:
            if(list){
                system("cls");
                pushNode(list);
                printf("������� ������� ���������.\n");
                system("pause");
            }
            else{
                system("cls");
                printf("������ �� ���������, �������� ������.");
                system("pause");
            }
            ;break;
        case 4:
            system("cls");
            printf("������� �������� �������: ");
            scanf("%s",&title);
            if(findCorrect(list,title)){
                printf("������ ������� ��������.\n");
                system("pause");
            }
            else{
                printf("������ �� �������.\n");
                system("pause");
            }
            ;break;
        case 5:NULL;break;
        case 6:NULL;break;
        case 7:NULL;break;
        case 8:return 0;
        default:
            system("cls");
            printf("�������� �������\n");
            system("pause");
            break;
        }
    }

}

DLinkedList* createLinkedList(){
    DLinkedList *tmp =(DLinkedList*)malloc(sizeof(DLinkedList));
    tmp ->size = 0;//��������� �� ������
    tmp->head = tmp->tail = NULL;//������������� ��������� �� ������ ������ � �����
    pushNode(tmp);
    tmp->size ++;
    return tmp;
}

void showDLList(DLinkedList* list){
    Node *tmp = list->head;//��������� ��������� �� ������ �������
    int counter = 1;
    while(tmp){
        printf("%d.%s\n%s\n%d\n\n",counter,tmp->title,tmp->type,tmp->price);
        counter++;
        tmp = tmp->next;
    }
    system("pause");
}

void pushNode(DLinkedList* list){
    system("cls");
    Node *tmp = (Node*)malloc(sizeof(Node));
    int choice;
    int price;
    if(tmp == NULL){
        printf("�������� ������.");
        exit(2);
    }
    printf("������� �������� �������: ");
    scanf("%s",tmp->title);
    while(choice != 1 && choice !=2){
        system("cls");
        printf("�������� ��� �������:\n1. ������\n2. ������\n������� �����:");
        scanf("%d",&choice);
        printf("%d",choice);
        if(choice != 1 && choice != 2){
            printf("������������ ����.\n");
            system("pause");
        }
        else if(choice == 1){
            strcpy(tmp->type,"������");
        }
        else if (choice == 2){
            strcpy(tmp->type,"������");
        }
    }
    system("cls");
    printf("������� ����: ");
    scanf("%d",&price);
    tmp->price = price;
    if(list->head == NULL){
        list->head = tmp;
        list->tail = tmp;
        tmp->next = NULL;
        tmp->prev = NULL;
    }
    else insertIn(list,tmp);
}

void insertIn(DLinkedList* list, Node* temp){
    Node *temp2 = list->head;
    while(temp2){
        if(strcmp(temp->title,temp2->title) == 1){
            if(temp2->next == NULL){    //���� ������� ������� �������� ���������(�����)
                temp->next = NULL;
                temp->prev = list->tail;
                temp2->next = temp;
                list->tail = temp;
                return;
            }
            else temp2 = temp2->next;   //����� ������� �� ��������� �������
        }
        else{
            if(list->head==temp2){  // ���� ������� ������� �������� ������(������)
                temp->next = list->head;
                temp->prev = NULL;
                list->head->prev = temp;
                list->head = temp;
                return;
            }
            else{
                temp->next = temp2; // ���� ������� �������� ���������� ����� �������� ���������
                temp->prev = temp2->prev;
                temp2->prev->next = temp;
                temp2->prev = temp;
                return;
            }
        }

    }
}

int findCorrect(DLinkedList* list, char* title){
    Node* tmp = list->head;
    while(tmp){
        if(strcmp(tmp->title,title)==0){ // ���� �������� ������� � ������ � � ������� ����� �� �������� ������
            int choice;
            while(1 != 0){
                system("cls");
                printf("������ �������.\n�������� ���� ������� ������ ��������\n");
                printf("1. ��������\n2. ��� �������\n3. ����\n������� �����: ");
                scanf("%d",&choice);
                if(choice != 1 && choice != 2 && choice !=3 ){
                    printf("������������ ����.");
                    system("pause");
                }
                else{
                    if(choice == 1){
                        char name[SIZE];
                        printf("������� ��������: ");
                        scanf("%s",&name);
                        strcpy(tmp->title,name);
                    }
                    else if (choice == 2){
                        char type[SIZE];
                        printf("������� ��� �������: ");
                        scanf("%s",&type);
                        strcpy(tmp->type,type);
                    }
                    else if (choice == 3){
                        int price;
                        printf("������� ����: ");
                        scanf("%d",&price);
                        tmp->price = price;
                    }
                    return 1;
                    }
                }
            }
            tmp = tmp->next;
        }return 0;
}

