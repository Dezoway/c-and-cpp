#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#define SIZE 20
typedef struct _Node {
    char title[SIZE];
    char type[SIZE];
    int price;
    struct _Node *next;//Указатель на следующий узел
    struct _Node *prev;//Указатель на предыдущий узел
} Node;//Создание узла списка

typedef struct _DLinkedList{
    Node *head;//Голова списка
    Node *tail;//Хвост списка
    size_t size;//Размер списка
}DLinkedList;//Хранение размера списка

DLinkedList* createLinkedList();//Создание списка
void showDLList();//Просмотр списка
void pushNode(DLinkedList* list);//Добавление новой записи
void insertIn(DLinkedList* list,Node* tmp);//Вставка записи в список по возрастанию
int findCorrect(DLinkedList* list, char* title);//Поиск и корректировка записи(узла)
int deleteNode(DLinkedList *list, char* title);//Удаление записи(узла)
int saveToFile(DLinkedList *list);//Сохранение списка в файл
//void loadToList(DLinkedList *list);//Загрузка списка из файла
//void exit(DLinkedList *list);//Выход
int main(void){
    setlocale(LC_ALL,"Rus");
    int a;
    char title[SIZE];
    DLinkedList *list = NULL;
    while(1!=0){
        system("cls");
        printf("Выберите желаемое действие:\n");
        printf("1. Создание списка.\n");
        printf("2. Просмотр списка.\n");
        printf("3. Добавление в список новой записию\n");
        printf("4. Поиск и корректировка записи в списке.\n");
        printf("5. Удаление записи из списка.\n");
        printf("6. Сохранение списка в файле.\n");
        printf("7. Загрузка списка из файла.\n");
        printf("8. Выход\n");
        printf("Введите число: ");
        scanf("%d",&a);
        switch(a){
        case 1:{
            list = createLinkedList();
            system("cls");
            printf("Список создан\n");
            system("pause");
            break;
        }
        case 2:
            system("cls");
            if (list != NULL && list->head->title != NULL){
            showDLList(list);
            }
            else{
                printf("Издания не обнаружены. Загрузите список изданий из файла либо создайте список и  добавьте элементы вручную\n");
                system("pause");
            }
            ;break;
        case 3:
            if(list){
                system("cls");
                pushNode(list);
                printf("Издание успешно добавлено.\n");
                system("pause");
            }
            else{
                system("cls");
                printf("Список не обнаружен, создайте список.");
                system("pause");
            }
            ;break;
        case 4:
            system("cls");
            printf("Введите название издания: ");
            scanf("%s",title);
            if(findCorrect(list,title)){
                printf("Запись успешно изменена.\n");
                system("pause");
            }
            else{
                printf("Запись не найдена.\n");
                system("pause");
            }
            ;break;
        case 5:
            system("cls");
            if(list){
                printf("Введите название издания: ");
                scanf("%s",title);
                if(deleteNode(list,title)){
                    printf("Запись успешно удалена.\n");
                    system("pause");
                }
                else{
                    printf("Запись не найлена.\n");
                    system("pause");
                }
            }
            else {printf("Издания не обнаружены, создайте список изданий вручную либо загрузите из файла.\n");
            system("pause");}
            break;
        case 6:
            system("cls");
            if (list != NULL && list->head->title != NULL){
                if(saveToFile(list)){printf("Издания успешно сохранены.\n");system("pause");}
                else{printf("Список пуст, создайте список изданий вручную либо загрузите из файла.\n");system("pause");}
            }



            ;break;
        case 7:NULL;break;
        case 8:return 0;
        default:
            system("cls");
            printf("Неверная команда\n");
            system("pause");
            break;
        }
    }
}

DLinkedList* createLinkedList(){
    DLinkedList *tmp =(DLinkedList*)malloc(sizeof(DLinkedList));
    tmp ->size = 0;//Указатель на размер
    tmp->head = tmp->tail = NULL;//Инициализация указателя на голову списка и хвост
    pushNode(tmp);
    tmp->size ++;
    return tmp;
}

void showDLList(DLinkedList* list){
    Node *tmp = list->head;//Указатель ссылается на первый элемент
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
        printf("Нехватка памяти.");
        exit(2);
    }
    printf("Введите название издания на английском без пробелов: ");
    scanf("%s",&tmp->title);
    while(choice != 1 && choice !=2){
        system("cls");
        printf("Выберите тип издания:\n1. Газета\n2. Журнал\nВведите число:");
        scanf("%d",&choice);
        printf("%d",choice);
        if(choice != 1 && choice != 2){
            printf("Некорректный ввод.\n");
            system("pause");
        }
        else if(choice == 1){
            strcpy(tmp->type,"Газета");
        }
        else if (choice == 2){
            strcpy(tmp->type,"Журнал");
        }
    }
    system("cls");
    printf("Введите цену: ");
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
            if(temp2->next == NULL){    //Если текущий элемент является последним(хвост)
                temp->next = NULL;
                temp->prev = list->tail;
                temp2->next = temp;
                list->tail = temp;
                return;
            }
            else temp2 = temp2->next;   //Иначе переход на следующий элемент
        }
        else{
            if(list->head==temp2){  // Если текущий элемент является первым(голова)
                temp->next = list->head;
                temp->prev = NULL;
                list->head->prev = temp;
                list->head = temp;
                return;
            }
            else{
                temp->next = temp2; // Если текущий эелемент расположен между соседних элементов
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
        if(strcmp(tmp->title,title)==0){ // Если название издания в списке и в образце равны то изменить запись
            int choice;
            while(1 != 0){
                system("cls");
                printf("Запись найдена.\nВыберите поле которое хотите изменить\n");
                printf("1. Название\n2. Тип издания\n3. Цена\nВведите число: ");
                scanf("%d",&choice);
                if(choice != 1 && choice != 2 && choice !=3 ){
                    printf("Некорректный ввод.");
                    system("pause");
                }
                else{
                    if(choice == 1){
                        char name[SIZE];
                        printf("Введите название издания на английском без пробелов: ");
                        scanf("%s",&name);
                        strcpy(tmp->title,name);
                    }
                    else if (choice == 2){
                        system("cls");
                        printf("Выберите тип издания:\n1. Газета\n2. Журнал\nВведите число:");
                        int choice2;
                        scanf("%d",&choice2);
                        if(choice2 == 1)strcpy(tmp->type,"Газета");
                        else if (choice2 == 2)strcpy(tmp->type, "Журнал");
                        else{printf("Некорректный ввод.\n");system("pause");continue;}
                    }
                    else if (choice == 3){
                        int price;
                        printf("Введите цену: ");
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
            if(tmp->prev){  //Если перед удаляемым элементом есть элемент
                tmp->prev->next = tmp->next;
            }
            if(tmp->next){ //Если после удаляемого элемента есть элемент
                tmp->next->prev = tmp->prev;
            }
            if(!tmp->prev){//Если элемент является первым(голова)
                list->head = tmp->next;
            }
            if(!tmp->next){//Если элемент является последним(хвост)
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
    printf("Введите имя_файла.txt: ");
    scanf("%s",file);
    output = fopen(file,"wb");
    if(output){
        while(tmp){
           fwrite(tmp->title,sizeof(tmp->title),1,output);
           fwrite(tmp->type,sizeof(tmp->type),1,output);
           fwrite(&tmp->price,sizeof(int),1,output);
           tmp = tmp->next;
        }
        fclose(output);
        return 1;
    }
    else printf("Ошибка! Не удалось прочитать файл\n");
    system("pause");
    fclose(output);
    return 0;
}
