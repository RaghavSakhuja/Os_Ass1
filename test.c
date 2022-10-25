#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#define p(a) printf("%s\n",a)


int main(){
    char* args[4];
    args[0]=".";
    args[1]="..\0";
    args[2]="..\0";
    args[3]=NULL;
    int rc=fork();
    if(rc<0){
        p("Fork failed");
    }
    else if(rc==0){
        p("correct");
        int a=execvp(strdup("./ls"),args);
        printf("%d\n",a);
        p("shontnot");
    }
    else{
        wait(NULL);
    }

}