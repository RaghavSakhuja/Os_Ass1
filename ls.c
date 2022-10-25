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
// void _ls(const char *dir,int op_a,int op_1)
// {
// 	//Here we will list the directory
// 	struct dirent *d;
// 	DIR *dh = opendir(dir);
// 	if (!dh)
// 	//While the next entry is not readable we will print directory files
// 	while ((d = readdir(dh)) != NULL)
// 	{
// 		//If hidden files are found we continue
// 		if (!op_a && d->d_name[0] == '.')
// 			continue;
// 		printf("%s  ", d->d_name);
// 		if(op_1) printf("\n");
// 	}
// 	if(!op_1)
// 	printf("\n");
// }
// int main(int argc, const char *argv[])
// {
// 	if (argc == 1)
// 	{
//         char* s1[1024];
//         const char* s=getcwd(s,1024);
//         int a=getcwd(s,1024);
// 		_ls(s,0,0);
// 	}
// 	else if (argc == 2)
// 	{
// 		if (argv[1][0] == '-')
// 		{
// 			//Checking if option is passed
// 			//Options supporting: a, l
// 			int op_a = 0, op_1 = 0;
// 			char *p = (char*)(argv[1] + 1);
// 			while(*p){
// 				if(*p == 'a') op_a = 1;
// 				else if(*p == '1') op_1 = 1;
// 				else{
// 					perror("Option not available");
// 					exit(EXIT_FAILURE);
// 				}
// 				p++;
// 			}
//             char* s1[1024];
//             const char* s=getcwd(s,1024);

// 			_ls(s,op_a,op_1);
// 		}
// 	}
// 	return 0;
// }
