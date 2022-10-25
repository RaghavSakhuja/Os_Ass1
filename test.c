#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#define p(a) printf("%s\n",a)


int main(){
    char* args[3];
    args[0]=".";
    args[1]="..";
    args[2]="..";
    int rc=fork();
    if(rc<0){
        p("Fork failed");
    }
    else if(rc==0){
        p("correct");
        execvp("./ls",args);
        p("shontnot");
    }
    else{
        wait(NULL);
    }

}