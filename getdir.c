#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#define f(a)     fprintf(ptr,"%s",a);

int main(){
    char s[1024];
    FILE* ptr;
    ptr=fopen("paths.txt","w");
    if(ptr==NULL){
        printf("DO NOT RUN!!! ERROR");
        return 1;
    }
    getcwd(s,1024); 
    f(s);
    f("/ls\n");
    f(s);
    f("/mkdir\n");
    f(s);
    f("/cat\n");
    f(s);
    f("/date\n");
    f(s);
    f("/rm\n");
    
}   