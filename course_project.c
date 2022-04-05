#include<stdio.h>
#include<locale.h>
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
void pushNode(DLinkedList *list);//Добавление в начало списка новой записи
void findCorrect(DlinkedList *list);//Поиск и корректировка записи(узла)
void deleteNode(DlinkedList *list);//Удаление записи(узла)
void saveToFile(DlinkedList *list);//Сохранение списка в файл
void loadToList(DlinkedList *list);//Загрузка списка из файла
void exit(DlinkedList *list);//Выход




int main(void){
    setlocale(LC_ALL,"Rus");
    int a;
    while(1!=0){
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
        default:
            printf("Неверная команда\n\n");
            getchar();
            break;
        }
    }

}


DLinkedList* createLinkedList(){
    DLinkedList *tmp =(DLinkedList*)malloc(sizeof(DLinkedList));
    if(tmp == NULL)exit(1);
    tmp ->size = 0;//Указатель на размер
    tmp->head = tmp->tail = NULL;//Инициализация указателя на голову списка и хвост
    return tmp;
}



void showDLList(DLinkedList* list){
    Node *tmp = list->head;//Указатель ссылается на первый элемент
    int counter = 1;
    while(tmp){
        printf("%d.%s\n%s\n%d\n\n",counter,tmp->title,tmp->type,tmp->price);
        counter++;
    }
}


