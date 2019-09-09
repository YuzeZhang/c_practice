//
// Created by zeno on 2019/9/8.
//

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define PERSONS_MAX_SIZE 256
#define NAME_MAX_SIZE 1024
#define PHONE_MAX_SIZE 256

typedef struct PersonInfo{
    char name[NAME_MAX_SIZE];
    char phone_num[PHONE_MAX_SIZE];
}PersonInfo;
typedef struct AddrBook{
    PersonInfo persons[PERSONS_MAX_SIZE];
    size_t size;  //��ǰ��������ЧԪ�صĸ���
}AddrBook;
void Init(AddrBook* addr_book){
    assert(addr_book);
    addr_book ->size = 0;
    for (int i = 0; i < PERSONS_MAX_SIZE; ++i) {
        memset(addr_book->persons[i].name,'\0',NAME_MAX_SIZE);
        memset(addr_book->persons[i].phone_num,'\0',PHONE_MAX_SIZE);
    }
}
void Add(AddrBook* addr_book){
    assert(addr_book);
    printf("������ϵ�ˣ�\n");
    if (addr_book->size>=PERSONS_MAX_SIZE){
        printf("��ϵ����������ɾ��һ������������ϵ��!\n");
        return;
    }
    //PersonInfo* p = &addr_book->persons[addr_book->size];
    printf("��������ϵ�˵�������");
    scanf("%s",addr_book->persons[addr_book->size].name);
    printf("��������ϵ�˵ĵ绰��");
    scanf("%s",addr_book->persons[addr_book->size].phone_num);
    ++addr_book->size;
    printf("�����ɹ���\n");
}
void Remove(AddrBook* addr_book){
    assert(addr_book);
    printf("ɾ��ͨѶ¼�е���ϵ�ˣ�\n");
    if(addr_book->size==0){
        printf("ͨѶ¼Ϊ�գ�\n");
        return;
    }
    printf("������Ҫɾ������ϵ�˵����:");
    int index;
    scanf("%d",&index);
    if(index<0||index>=addr_book->size){
        printf("��������������\n");
        return;
    }
    if(index == addr_book->size-1){
        //ɾ�����һ��Ԫ��
        --addr_book->size;
    }else{
        //ɾ���м�Ԫ��
        PersonInfo* target = &addr_book->persons[index];
        PersonInfo* last = &addr_book->persons[addr_book->size-1];
        strcpy(target->name,last->name);
        strcpy(target->phone_num,last->phone_num);
        --addr_book->size;
    }
    printf("ɾ���ɹ���\n");
}
void FindAll(AddrBook* addr_book){

}
void PrintAll(AddrBook* addr_book){
    assert(addr_book);
    printf("===========================\n");
    for (int i = 0; i < addr_book->size; ++i) {
        PersonInfo* p = &addr_book->persons[i];
        printf("[%d] %s : %s\n",i,p->name,p->phone_num);
    }
    printf( "��ǰ���� %d ����¼!\n",addr_book->size);
    printf("===========================\n");
}
void Update(AddrBook* addr_book){
    assert(addr_book);
    printf("������ϵ�˼�¼��\n");
    if(addr_book->size==0){
        printf("ͨѶ¼Ϊ�գ�\n");
        return;
    }
    printf("��������Ҫ�޸ĵ���ϵ�˵���ţ�\n");
    int index = 0;
    scanf("%d",&index);
    if(index<0||index>=addr_book->size){
        printf("���������ϵ���������\n");
        return;
    }
    PersonInfo* p = &addr_book->persons[index];
    printf("��ǰ����Ϊ%s,�������޸ĺ������(*��ʾ��ǰ�ֶβ��޸�):",p->name);
    char name[NAME_MAX_SIZE] ={0};
    scanf("%s",name);
    if(strcmp(name,"*")!=0){
        strcpy(p->name,name);
    }
    printf("��ǰ�绰Ϊ%s,�������޸ĺ�ĵ绰(*��ʾ��ǰ�ֶβ��޸�):",p->phone_num);
    char phone_num[PHONE_MAX_SIZE] ={0};
    scanf("%s",phone_num);
    if(strcmp(phone_num,"*")!=0){
        strcpy(p->phone_num,phone_num);
    }
    printf("�޸���ɣ�\n");
}
int Menu(){
    printf("===========================\n");
    printf("     ��ӭʹ��ͨѶ¼����!\n");
    printf("     1.��ʾ������ϵ����Ϣ\n");
    printf("     2.������ϵ����Ϣ\n");
    printf("     3.�޸���ϵ����Ϣ\n");
    printf("     4.ɾ����ϵ����Ϣ\n");
    printf("     0.�˳�ͨѶ¼����\n");
    printf("===========================\n");
    printf("     ����������ѡ��\n");
    int choice;
    scanf("%d",&choice);
    return choice;
}
AddrBook addr_book;
typedef void(*Func)(AddrBook*);
int main() {
    Init(&addr_book);
    Func func_table[] = {
            NULL,
            PrintAll,
            Add,
            Update,
            Remove,
    };
    while (1) {
        int choice = Menu();
        if(choice<0||choice>4){
            printf("���������������������룡\n");
            continue;
        }
        if (choice == 0) {
            printf("goodbye!\n");
            break;
        }
        system("cls");
        func_table[choice](&addr_book);
    }
    return 0;
}
