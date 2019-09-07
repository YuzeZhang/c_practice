//
// Created by zeno on 2019/9/7.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
void* Memcpy(void* destination, const void* source,size_t num){
    assert(destination&&source);
    char* d = destination;
    char* s = source;
    while(num){
        *d++ = *s++;
        --num;
    }
    return destination;
}
struct {
    char name[1024];
    int age;
}person,person_copy;
int main(){
    char myname[] = "Pierre de Fermat";
    Memcpy(person.name,myname,strlen(myname)+1);
    person.age = 46;
    Memcpy(&person_copy,&person, sizeof(person));
    printf("person_copy:%s,%d\n",person_copy.name,person_copy.age);
    return 0;
}
