//
// Created by Zeno on 2019/12/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    printf("printf ");
    fwrite("fwrite ", 6, 1, stdout);
    fprintf(stdout, "%s", "fprintf");
    write(1, "write ", 5);
    sleep(3);
    return 0;
}
