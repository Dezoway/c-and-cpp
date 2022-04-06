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
void pushNode(DLinkedList *list);//Добавление в список новой записи
// void sorted(DlinkedList *list);//Сортировка записей
//void findCorrect(DlinkedList *list);//Поиск и корректировка записи(узла)
//void deleteNode(DlinkedList *list);//Удаление записи(узла)
//void saveToFile(DlinkedList *list);//Сохранение списка в файл
//void loadToList(DlinkedList *list);//Загрузка списка из файла
//void exit(DlinkedList *list);//Выход




int main(void){
    setlocale(LC_ALL,"Rus");
    int a;
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
            if (list != NULL){
            showDLList(list);
            }
            else{
                printf("Элементы списка не обнаружены. Загрузите список из файла либо создайте список и  добавьте элементы вручную\n");
                system("pause");
            }
            ;break;
        case 3:
            if(list){
                system("cls");
                pushNode(list);
            }
            else printf("Список не обнаружен, создайте список.");

            ;break;
        case 4:NULL;break;
        case 5:NULL;break;
        case 6:NULL;break;
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
    printf("Введите название издания: ");
    scanf("%s",tmp->title);
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

}

