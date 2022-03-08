#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
void initArray(int *&a, int size){
    a = new int[size];
    for(int x = 0; x != size;x++){
        a[x] = rand()%26-10;
    }
}
void printArray(int *a, int size){
    for(int x = 0; x != size; x++){
        printf("%d ",a[x]);
    }printf("\n");
}
void addElement(int *&a, int &size){
    int k, n, j = 0;
    scanf("%d %d",&k,&n);
    k--;
    int *b = new int[size+1];
    if(k < 0){
        printf("a\n");
        b[0] = n;
        for(int x = 1; x != size+1;x++)b[x] = a[x-1];

    }
    else if(k > size){
        printf("b\n");
        for(int x = 0; x!= size; x++)b[x] = a[x];
        b[size] = n;
    }
    else{
    for(int x = 0; x != size+1;x++){
        printf("c\n");
        if(x != k){
            b[x] = a[j];
            j++;
        }
        else b[k] = n;
    }
    }
    delete[] a;
    a = b;
    size = size+ 1;
}
void delElement(int *&a, int &size){
    int k, n, j = 0;
    scanf("%d",&k);
    if(k < 1 || k > size)return;
    k--;
    int *b = new int[size-1];
    for(int x = 0; x != size; x++){
        if(x == k)continue;
        else{
            b[j] = a[x];
            j++;
        }
    }
    delete[] a;
    a = b;
    size -= 1;
}


int main(){

    int n,beg;
    cin>>n>>beg;
    srand(beg);
    int *a=NULL;
    a=new int[n];
    initArray(a,n);
    printArray(a,n);
    int k;//выбор пользователя
    while(true){ // бесконечный цикл
        cin>>k;//ввод выбранного варианта
        switch(k){
            case 1: addElement(a,n); break; //1 - добавление элемента
            case 2: delElement(a,n); break; //2 - удаление элемента
            case 3: printArray(a,n); break; //3 - печать массива
            default: delete[] a; return 0; //другие числа - окончание работы программы
        }
    }
}
