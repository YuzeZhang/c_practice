//
// Created by zeno on 2019/9/9.
//


#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX_SIZE 1024
#define PHONE_MAX_SIZE 256

typedef struct PersonInfo{
    char name[NAME_MAX_SIZE];
    char phone_num[PHONE_MAX_SIZE];
}PersonInfo;
typedef struct AddrBook{
    PersonInfo* persons;
    int size;  //��ǰ��������ЧԪ�صĸ���
    int capacity; //��ǰ������������
}AddrBook;
void Init(AddrBook* addr_book){
    assert(addr_book);
    addr_book ->size = 0;
    addr_book->capacity = 10;
    addr_book->persons = (PersonInfo*)malloc(sizeof(PersonInfo) * addr_book->capacity);
    for (int i = 0; i < addr_book->capacity; ++i) {
        memset(addr_book->persons[i].name,'\0',NAME_MAX_SIZE);
        memset(addr_book->persons[i].phone_num,'\0',PHONE_MAX_SIZE);
    }
}
void Add(AddrBook* addr_book){
    assert(addr_book);
    printf("������ϵ�ˣ�\n");
    if (addr_book->size>=addr_book->capacity){
        addr_book->capacity+=10;
        addr_book->persons = (PersonInfo*)realloc(addr_book->persons, sizeof(PersonInfo)*addr_book->capacity);
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
void LoadFile(AddrBook* addr_book){
    assert(addr_book);
    FILE* fp = fopen("E:\\jetbrains\\CLionProjects\\untitled1\\mail.txt","r");
    if(fp==NULL){
        //��ӡ����ԭ��
        perror("fopen");
        return;
    }
    int i = 0;
    while (fscanf(fp,"%s%s",addr_book->persons[i].name,addr_book->persons[i].phone_num)!=EOF){
        ++i;
    }
     addr_book->size = i;
    fclose(fp);
}
void SaveFile(AddrBook* addr_book){
    assert(addr_book);
    int i;
    FILE* fp = fopen("E:\\jetbrains\\CLionProjects\\untitled1\\mail.txt","r");
    //����ʱ�ļ�
    FILE* fpTmp = fopen("E:\\jetbrains\\CLionProjects\\untitled1\\tmp.txt","w");
    if(fp == NULL||fpTmp == NULL){
        perror("fopen");
        return;
    }
    //����ʱ�ļ�д����º����Ϣ
    for(i = 0;i<addr_book->size;++i){
        fprintf(fpTmp,"%s %s\n",addr_book->persons[i].name,addr_book->persons[i].phone_num);
    }
    fclose(fp);
    fclose(fpTmp);
    remove("E:\\jetbrains\\CLionProjects\\untitled1\\mail.txt");
    rename("E:\\jetbrains\\CLionProjects\\untitled1\\tmp.txt","E:\\jetbrains\\CLionProjects\\untitled1\\mail.txt");
}
AddrBook addr_book;
typedef void(*Func)(AddrBook*);
int main() {
    Init(&addr_book);
    LoadFile(&addr_book);
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
    SaveFile(&addr_book);
    return 0;
}