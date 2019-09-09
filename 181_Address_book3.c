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
    int size;  //当前数组中有效元素的个数
    int capacity; //当前数组的最大容量
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
    printf("新增联系人！\n");
    if (addr_book->size>=addr_book->capacity){
        addr_book->capacity+=10;
        addr_book->persons = (PersonInfo*)realloc(addr_book->persons, sizeof(PersonInfo)*addr_book->capacity);
    }
    //PersonInfo* p = &addr_book->persons[addr_book->size];
    printf("请输入联系人的姓名：");
    scanf("%s",addr_book->persons[addr_book->size].name);
    printf("请输入联系人的电话：");
    scanf("%s",addr_book->persons[addr_book->size].phone_num);
    ++addr_book->size;
    printf("新增成功！\n");
}
void Remove(AddrBook* addr_book){
    assert(addr_book);
    printf("删除通讯录中的联系人！\n");
    if(addr_book->size==0){
        printf("通讯录为空！\n");
        return;
    }
    printf("请输入要删除的联系人的序号:");
    int index;
    scanf("%d",&index);
    if(index<0||index>=addr_book->size){
        printf("您输入的序号有误！\n");
        return;
    }
    if(index == addr_book->size-1){
        //删除最后一个元素
        --addr_book->size;
    }else{
        //删除中间元素
        PersonInfo* target = &addr_book->persons[index];
        PersonInfo* last = &addr_book->persons[addr_book->size-1];
        strcpy(target->name,last->name);
        strcpy(target->phone_num,last->phone_num);
        --addr_book->size;
    }
    printf("删除成功！\n");
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
    printf( "当前共有 %d 条记录!\n",addr_book->size);
    printf("===========================\n");
}
void Update(AddrBook* addr_book){
    assert(addr_book);
    printf("更新联系人记录！\n");
    if(addr_book->size==0){
        printf("通讯录为空！\n");
        return;
    }
    printf("请输入您要修改的联系人的序号：\n");
    int index = 0;
    scanf("%d",&index);
    if(index<0||index>=addr_book->size){
        printf("您输入的联系人序号有误！\n");
        return;
    }
    PersonInfo* p = &addr_book->persons[index];
    printf("当前姓名为%s,请输入修改后的姓名(*表示当前字段不修改):",p->name);
    char name[NAME_MAX_SIZE] ={0};
    scanf("%s",name);
    if(strcmp(name,"*")!=0){
        strcpy(p->name,name);
    }
    printf("当前电话为%s,请输入修改后的电话(*表示当前字段不修改):",p->phone_num);
    char phone_num[PHONE_MAX_SIZE] ={0};
    scanf("%s",phone_num);
    if(strcmp(phone_num,"*")!=0){
        strcpy(p->phone_num,phone_num);
    }
    printf("修改完成！\n");
}
int Menu(){
    printf("===========================\n");
    printf("     欢迎使用通讯录程序!\n");
    printf("     1.显示所有联系人信息\n");
    printf("     2.新增联系人信息\n");
    printf("     3.修改联系人信息\n");
    printf("     4.删除联系人信息\n");
    printf("     0.退出通讯录程序\n");
    printf("===========================\n");
    printf("     请输入您的选择：\n");
    int choice;
    scanf("%d",&choice);
    return choice;
}
void LoadFile(AddrBook* addr_book){
    assert(addr_book);
    FILE* fp = fopen("E:\\jetbrains\\CLionProjects\\untitled1\\mail.txt","r");
    if(fp==NULL){
        //打印错误原因
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
    //打开临时文件
    FILE* fpTmp = fopen("E:\\jetbrains\\CLionProjects\\untitled1\\tmp.txt","w");
    if(fp == NULL||fpTmp == NULL){
        perror("fopen");
        return;
    }
    //给临时文件写入更新后的信息
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
            printf("您的输入有误，请重新输入！\n");
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