#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#define p(a) printf("%s\n",a)
#define plen(a) printf("%d\n",strlen(a));


void echo(){




}

void pwd(){
    char s[1024];
    p(getcwd(s,1024));
}

void cd(char* cd){
    char* res;
    

    int a=chdir(cd);
    if(a==0){
        printf("cd: %s: No such file or directory\n",cd);
    }
    printf("%d\n",a);
}



int kernel(){
        char* cmd={0};
        long unsigned int len=0;
        printf(">>");
        getline(&cmd,&len,stdin);
        len=strlen(cmd);
        len--;
        cmd[len]='\0';
        char strr[len];
        strcpy(strr,cmd);
        char* res=strtok(cmd," ");
        p(res);
        if(!strcmp(res,"cd")){
            p(res);
            cd(strr);
        }
        else if(!strcmp(res,"echo")){
            echo();
        }
        else if(!strcmp(res,"pwd")){
            pwd();
        }
        else if(!strcmp(res,"ls")){
            
        }
        else if(!strcmp(res,"cat")){
            
        }
        else if(!strcmp(res,"mkdir")){
            
        }
        else if(!strcmp(res,"rm")){
            
        }
        else if(!strcmp(res,"cat")){
            
        }
        else if(!strcmp(res,"exit")){
            return 0;
        }
        return 1;
}
int main(){
    int a=1;
    while(a){
    a=kernel();
    }
}
