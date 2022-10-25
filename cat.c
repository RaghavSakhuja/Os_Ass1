#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#define p(a) printf("%s\n",a)
#define plen(a) printf("%ld\n",strlen(a));


int main(int argc,char* argv[]){
	// p("aaaaaaaaaaa");
	int flag1=(!strcmp(argv[3],"x")); //-e
	int flag2=(!strcmp(argv[4],"x")); //-n
    char* file1=argv[1];
    char* file2;
    if(strcmp(argv[2],"nonexistent")){
        file2=NULL;
    }
    file2=argv[2];
    int i=1;
    FILE* fptr;
    FILE* fptr2=NULL;
    fptr=fopen(file1,"r");
    if(fptr==NULL){
        printf("cat: %s: No such file or directory\n",file1);
        return 0;
    }
    if(file2!=NULL){
        fptr2=fopen(file2,"r");
        if(fptr2==NULL){
            printf("cat: %s: No such file or directory\n",file2);
            return 0;
        }
    }

    char input[1024];
    while(fgets(input,sizeof(input),fptr)){
        int len=strlen(input);
        if(flag2){
            printf("%d\t%s",i,input);            
        }
        else{
            printf("%s",input);
        }
        if(input[len-1]=='\n'){
            i++;
        }

    }
    if(flag1){
        printf("$");
    }
    if(fptr2){
        char input2[1024];
        while(fgets(input2,sizeof(input2),fptr2)){
            int len=strlen(input2);
            if(flag2){
                printf("%d\t%s",i,input2);            
            }
            else{
                printf("%s",input2);
            }
            if(input2[len-1]=='\n'){
                i++;
            }
        }
        if(flag1){
            printf("$");
        }
    }


	// printf("%d %d\n",flag1,flag2);
}
