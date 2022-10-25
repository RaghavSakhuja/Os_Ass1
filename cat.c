#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#define p(a) printf("%s\n",a)
#define plen(a) printf("%ld\n",strlen(a));


int main(int argc,char* argv[]){
	// p("aaaaaaaaaaa");
	int flag1=(!strcmp(argv[2],"x")); //-e
	int flag2=(!strcmp(argv[3],"x")); //-n
    char* file1=argv[0];
    char* file2;
    if(strcmp(argv[1],"nonexistent")){
        file2=NULL;
    }
    file2=argv[1];
    int i=1;
    FILE* fptr;
    FILE* fptr2;
    fptr=fopen(file1,"r");
    if(fptr==NULL){
        printf("cat: %s: No such file or directory",file1);
        return 0;
    }
    fptr2=fopen(file1,"r");
    if(fptr2==NULL){
        printf("cat: %s: No such file or directory",file2);
        return 0;
    }

    char input[1024];
    while(fgets(input,sizeof(input),fptr)){
        int len=strlen(input);
        if(input[len-1]=='\n'){
            i++;
        }
        if(flag2){
            printf("%d\t%s",input);            
        }
        else{
            printf("%s",input);
        }
    }
    if(flag1){
        printf("$");
    }

    while(fgets(input,sizeof(input),fptr2)){
        int len=strlen(input);
        if(input[len-1]=='\n'){
            i++;
        }
        if(flag2){
            printf("%d\t%s",i,input);            
        }
        else{
            printf("%s",input);
        }
    }
    if(flag1){
        printf("$");
    }



	// printf("%d %d\n",flag1,flag2);
}
