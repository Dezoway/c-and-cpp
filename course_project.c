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
}DLinkedList;//�������� ������� ������

DLinkedList* createLinkedList();//�������� ������
void showDLList();//�������� ������
void pushNode(DLinkedList* list);//���������� ����� ������
void insertIn(DLinkedList* list,Node* tmp);//������� ������ � ������ �� �����������
int findCorrect(DLinkedList* list, char* title);//����� � ������������� ������(����)
int deleteNode(DLinkedList *list, char* title);//�������� ������(����)
int saveToFile(DLinkedList *list);//���������� ������ � ����
DLinkedList* loadToList(DLinkedList *list);//�������� ������ �� �����
void quit(DLinkedList *list);//�����
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
            if (list != NULL && list->head->title != NULL){
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
            scanf("%s",title);
            if(findCorrect(list,title)){
                printf("������ ������� ��������.\n");
                system("pause");
            }
            else{
                printf("������ �� �������.\n");
                system("pause");
            }
            ;break;
        case 5:
            system("cls");
            if(list){
                printf("������� �������� �������: ");
                scanf("%s",title);
                if(deleteNode(list,title)){
                    printf("������ ������� �������.\n");
                    system("pause");
                }
                else{
                    printf("������ �� �������.\n");
                    system("pause");
                }
            }
            else {printf("������� �� ����������, �������� ������ ������� ������� ���� ��������� �� �����.\n");
            system("pause");}
            break;
        case 6:
            system("cls");
            if (list != NULL && list->head->title != NULL){
                if(saveToFile(list)){printf("������� ������� ���������.\n");system("pause");}
            }
            else{printf("������ ����, �������� ������ ������� ������� ���� ��������� �� �����.\n");system("pause");}



            ;break;
        case 7:
            system("cls");
            list = loadToList(list);
            /*if(loadToList(list)){
                printf("������ ������� ������� ��������.\n");
                system("pause");
                }
            else{
                printf("���� � ����� ������ �� ������.\n");
                system("pause");
                }*/
            break;
        case 8:
            quit(list);
            return 0;
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
    tmp->head = tmp->tail = NULL;//������������� ��������� �� ������ ������ � �����
    pushNode(tmp);
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
    printf("������� �������� ������� �� ���������� ��� ��������: ");
    scanf("%s",&tmp->title);
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
                        printf("������� �������� ������� �� ���������� ��� ��������: ");
                        scanf("%s",&name);
                        strcpy(tmp->title,name);
                    }
                    else if (choice == 2){
                        system("cls");
                        printf("�������� ��� �������:\n1. ������\n2. ������\n������� �����:");
                        int choice2;
                        scanf("%d",&choice2);
                        if(choice2 == 1)strcpy(tmp->type,"������");
                        else if (choice2 == 2)strcpy(tmp->type, "������");
                        else{printf("������������ ����.\n");system("pause");continue;}
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
            else tmp = tmp->next;
        }return 0;
}

int deleteNode(DLinkedList* list, char* title){
    Node* tmp = list->head;
    while(tmp){
        if(strcmp(tmp->title,title) == 0){
            if(tmp->prev){  //���� ����� ��������� ��������� ���� �������
                tmp->prev->next = tmp->next;
            }
            if(tmp->next){ //���� ����� ���������� �������� ���� �������
                tmp->next->prev = tmp->prev;
            }
            if(!tmp->prev){//���� ������� �������� ������(������)
                list->head = tmp->next;
            }
            if(!tmp->next){//���� ������� �������� ���������(�����)
                list->tail = tmp->prev;
            }
            free(tmp);
            return 1;
        }
        else tmp = tmp->next;
    }
    return 0;
}

int saveToFile(DLinkedList* list){
    FILE *output;
    Node *tmp = list->head;
    char file[SIZE];
    printf("������� ���_�����.txt: ");
    scanf("%s",file);
    output = fopen(file,"wb");
    int counter = 1;
    if(output){
        while(tmp != NULL){
           printf("%d",counter) ;
           fwrite(tmp,sizeof(Node),1,output);
           tmp = tmp->next;
            counter++;
        }
        fclose(output);
        return 1;
    }
    else printf("������! �� ������� ��������� ����\n");
    system("pause");
    fclose(output);
    return 0;
}

DLinkedList* loadToList(DLinkedList* list){
    if(list != NULL){ //������� ������ ���� �� ����������
    Node* tmp = (list)->head;
        while(tmp){
            list->head = list->head->next;
            free(tmp);
            tmp = list->head;
        }
        free(list);
        list = NULL;
    }
    list = (DLinkedList*) malloc(sizeof(DLinkedList)); //��������� ������ ��� ����� ������
    list->head = NULL;
    list->tail = NULL;
    FILE *input;
    char file[SIZE];
    printf("������� ���_�����.txt: ");
    scanf("%s",file);
    input = fopen(file,"rb");
    while(!feof(input)){
        printf("a\n");

        Node *tmp = (Node*) malloc(sizeof(Node));
        if(fread(tmp,sizeof(Node),1,input)){
        printf("%s\t%s\t%d\n",tmp->title,tmp->type,tmp->price);
        if(list->head == NULL && list->tail == NULL){
            list->head = tmp;
            list->tail = tmp;
            tmp->next=NULL;
            tmp->prev = NULL;
        }
        else insertIn(list,tmp);
        }


    }
    return list;
}

void quit(DLinkedList *list){
    if(list != NULL){
        Node *tmp = list->head;
        while(tmp){
            list->head = list->head->next;
            free(tmp);
            tmp = list->head;
        }
        free(list);
        list = NULL;
    }
    else return;
}





