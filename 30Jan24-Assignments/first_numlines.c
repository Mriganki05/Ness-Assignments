#include<stdio.h>
#include<stdlib.h>


char ** firstnumlines(FILE * inputfp,unsigned int num){
	char **headbuf=calloc(num,sizeof(char *));

	for(int i=0;i<num;i++){
		headbuf[i]=malloc(255*sizeof(char));
		fgets(headbuf[i],255,inputfp);
	}
	return headbuf;
}


int main(int argc,char *argv[]){

	FILE * fp=fopen(argv[1],"r");
	int num=atoi(argv[2]);
	char **firstlines=firstnumlines(fp,num);
	for(int i=0;i<num;i++)
	{
		if(firstlines[i]!=NULL)
		{
			printf("%s",firstlines[i]);
			free(firstlines[i]);
		}
	}
	free(firstlines);
	fclose(fp);
}
