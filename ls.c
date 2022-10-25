//Used for basic input/output stream
#include <stdio.h>
//Used for handling directory files
#include <dirent.h>
//For EXIT codes and error handling
#include <errno.h>
#include <stdlib.h>
#define p(a) printf("%s\n",a)



int main(int argc,char* argv[]){
	p("aaaaaaaaaaa");
	struct dirent* d;
	DIR *dh =opendir(argv[0]);
	int flag1=(!strcmp(argv[1],"x")); //-a
	int flag2=(!strcmp(argv[1],"x")); //-1
	printf("%d %d\n",flag1,flag2);
	if(!dh){
	
		if (errno = ENOENT)
		{
			//If the directory is not found
			p("Directory doesn't exist");
		}
		else
		{
			//If the directory is not readable then throw error and exit
			p("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	while((d=readdir(dh))!=NULL){
		if(flag1==0 && d->d_name[0]=="."){
			continue;
		}
		printf("%s ",d->d_name);
		if(flag2==1){
			printf("\n");
		}
	}
	closedir(dh);
}