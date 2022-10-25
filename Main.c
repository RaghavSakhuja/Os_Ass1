#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#define p(a) printf("%s\n",a)
#define plen(a) printf("%ld\n",strlen(a));


void echon(char* c){
    bool flag=false;
        for(int i=0;i<strlen(c);i++){
            if(c[i]=='"'){
                if(flag==true){
                    flag=false;
                }
                else flag=true;
            }
        }
        char* txt[100];
        txt[0]=c;
        int j=1;
        while (flag)
        {
            char* nextline={0};
            long unsigned int len=0;
            printf(">");
            getline(&nextline,&len,stdin);
            for(int i=0;i<strlen(nextline);i++){
                if(nextline[i]=='"'){
                    if(flag==false){
                        flag=true;
                    }
                    else    flag=false;
                }
            }
            txt[j]=nextline;
            j++;
        }
        for(int i=0;i<j;i++){
            int g=strlen(txt[i]);
            for(int l=0;l<g;l++){
                if(txt[i][l]!='"'){
                    if(i==j-1 && l==g-1 && txt[i][l]=='\n'){
                            // p("YAHAB");
                    }
                    else    printf("%c",txt[i][l]);
                }
            }
            if(i==0 && j!=1){
                printf("\n");
            }
        }
}
void echoe(char* c){
    bool flag=false;
        for(int i=0;i<strlen(c);i++){
            if(c[i]=='"'){
                if(flag==true){
                    flag=false;
                }
                else flag=true;
            }
        }
        char* txt[100];
        txt[0]=c;
        int j=1;
        while (flag)
        {
            char* nextline={0};
            long unsigned int len=0;
            printf(">");
            getline(&nextline,&len,stdin);
            for(int i=0;i<strlen(nextline);i++){
                if(nextline[i]=='"'){
                    if(flag==false){
                        flag=true;
                    }
                    else flag=false;
                }
            }
            txt[j]=nextline;
            j++;
        }
        for(int i=0;i<j;i++){
            int g=strlen(txt[i]);
            for(int l=0;l<g;l++){
                if(txt[i][l]=='"'){

                }
                else if(txt[i][l]=='\\' && l!=g-1){
                    if(txt[i][l+1]=='t'){
                        printf("\t");
                    }                
                    else if(txt[i][l+1]!='c'){
                        break;
                    }
                    else if(txt[i][l+1]!='n'){
                        printf("\n");

                    }
                    else if(txt[i][l+1]!='\\'){
                        printf("\\");
                    }
                    else{
                        printf("%c",txt[i][l]);
                        printf("%c",txt[i][l+1]);
                    }
                    l++;
                }
                else{
                printf("%c",txt[i][l]);

                }
            }
            if(i==0){
                printf("\n");
            }
        }

}
void echosimple(char *c){
    bool flag=false;
        for(int i=0;i<strlen(c);i++){
            if(c[i]=='"'){
                if(flag==true){
                    flag=false;
                }
                else flag=true;
            }
        }
        char* txt[100];
        txt[0]=c;
        int j=1;
        while (flag)
        {
            char* nextline={0};
            long unsigned int len=0;
            printf(">");
            getline(&nextline,&len,stdin);
            for(int i=0;i<strlen(nextline);i++){
                if(nextline[i]=='"'){
                    if(flag==false){
                        flag=true;
                    }
                    else                    flag=false;
                }
            }
            txt[j]=nextline;
            j++;
        }
        for(int i=0;i<j;i++){
            for(int l=0;l<strlen(txt[i]);l++){
                if(txt[i][l]!='"')
                printf("%c",txt[i][l]);
            }
            if(i==0){
                printf("\n");
            }
        }

    
}
void echone(char *c){
    bool flag=false;
        for(int i=0;i<strlen(c);i++){
            if(c[i]=='"'){
                if(flag==true){
                    flag=false;
                }
                else flag=true;
            }
        }
        char* txt[100];
        txt[0]=c;
        int j=1;
        while (flag)
        {
            char* nextline={0};
            long unsigned int len=0;
            printf(">");
            getline(&nextline,&len,stdin);
            for(int i=0;i<strlen(nextline);i++){
                if(nextline[i]=='"'){
                    if(flag==false){
                        flag=true;
                    }
                    else flag=false;
                }
            }
            txt[j]=nextline;
            j++;
        }
        for(int i=0;i<j;i++){
            int g=strlen(txt[i]);
            for(int l=0;l<g;l++){
                if(txt[i][l]=='"'){

                }
                else if(txt[i][l]=='\\' && l!=g-1){
                    // p("sahi pahunch gaya");
                    if(txt[i][l+1]=='t'){
                        printf("\t");
                    }                
                    else if(txt[i][l+1]!='c'){
                        break;
                    }
                    else if(txt[i][l+1]!='n'){
                        printf("\n");

                    }
                    else if(txt[i][l+1]!='\\'){
                        printf("\\");
                    }
                    else{
                        printf("%c",txt[i][l]);
                        printf("%c",txt[i][l+1]);
                    }
                    l++;
                }
                else{
                    if(i==j-1 && l==g-1 && txt[i][l]=='\n'){
                            // p("YAHAB");
                    }

                    printf("%c",txt[i][l]);

                }
            }
            if(i==0){
                printf("\n");
            }
        }


}


void echo(char* echo){
    char res[strlen(echo)-4];
    char save[strlen(echo)-2];
    strcpy(res,echo+5);
    strcpy(save,echo+5);
    char* t2=strtok(res," ");
    // p(t2);
    char t1[strlen(t2)];
    strcpy(t1,t2);
    // p(t1);
    t2=strtok(NULL," ");
    // p(t1);
    // p(t2);
    char* arg;
    if(!(strcmp(t1,"-n"))){
        if(!(strcmp(t2,"-e"))){
            arg=save+6;//-n -e 
            p("ne 1");
            p(arg);
            echone(arg);
        }
        else{
            p("n 2");
            arg=save+3;//-n 
            p(arg);
            echon(arg);
        }
    }
    else if(!(strcmp(t1,"-e"))){
        if(!(strcmp(t2,"-n"))){
            arg=save+6;
            p("ne 3");
            p(arg);
            echone(arg);
        }
        else{
            arg=save+3;
            p("e 4");
            p(arg);
            echoe(arg);
        }
    }
    else if((!strcmp(t1,"-ne")) ||!(strcmp(t1,"-en"))){
            arg=save+4;
            p("ne 5");
            p(arg);

        echone(arg);
    }
    else{
            p("l 6");
            p(arg);
        echosimple(arg);
    }    
}

void pwd(){
    char s[1024];
    p(getcwd(s,1024));
}

void cd(char* cd){
    // p(cd);
    char res[strlen(cd)-2];
    strcpy(res,cd+3);
    // plen(res);
    // p(res);
    int a=chdir(res);
    // printf("%d\n",a);
    if(a!=0){
        printf("cd: %s: No such file or directory\n",res);
    }
}



int kernel(){
        char* cmd={0};
        long unsigned int len=0;
        printf(">>");
        getline(&cmd,&len,stdin);
        len=strlen(cmd);
        if(!strcmp(cmd,"\n")){
            return 1;
        }
        len--;
        cmd[len]='\0';
        char strr[len];
        strcpy(strr,cmd);
        char* res=strtok(cmd," ");
        // p(res);
        if(!strcmp(res,"cd")){
            cd(strr);
        }
        else if(!strcmp(res,"echo")){
            echo(strr);
        }
        else if(!strcmp(res,"pwd")){
            pwd();
        }
        else if(!strcmp(res,"ls")){
            char* t1=NULL;
            char* t2=NULL;
            char* t3=NULL;
            char* args[3];
            args[0]=args[1]=args[2]="..";
            int andt=0,number=3,count=0;
            t1=strtok(NULL," ");
            if(t1!=NULL){
                count++;
                t2=strtok(NULL," ");
                if(t2!=NULL){
                    count++;
                    t3=strtok(NULL," ");
                    if(t3!=NULL){
                        count++;
                    }
                }
            }
            if(count==0){
                t1=t2=t3="x";
            }
            else if(count==1){
                t2=t3="x";
            }
            else if(count==2){
                t3="x";
            }
            if((!strcmp(t1,"-a")) || (!strcmp(t2,"-a"))){
                args[1]=strdup("x");
                number+=3;
            }
            if((!strcmp(t1,"-a")) || (!strcmp(t2,"-a"))){
                args[2]=strdup("x");
                number+=3;
            }
            if(!strcmp(t1,"&t")){
                andt=1;
                number+=3;
            }
            else{
                if(strlen(strr)<3){
                    args[0]=strdup(".");
                }
                else{
                    args[0]=strr+number;
                }
                p(args[0]);
                p("aaaaa");
                p(args[1]);
                p(args[2]);
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