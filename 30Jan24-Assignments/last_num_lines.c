#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **lastnumlines(FILE *inputfp, unsigned int num) 
{    
	char **tailbuf = malloc(num * sizeof(char *));
    	for (int i = 0; i < num; i++) 
    	{
        	tailbuf[i]=malloc(255*sizeof(char));
    	}

    	int currentline = 0;
    	int index = 0;
    	char ch;

    	while ((ch = fgetc(inputfp)) != EOF) 
	{
        	tailbuf[currentline][index++] = ch;
		if (ch == '\n') 
		{
            		tailbuf[currentline][index] = '\0';
            		currentline = (currentline + 1) % num;
            		index = 0;
        	}
    	}


    	char **new_tailbuf = malloc(num * sizeof(char *));
    	int start = currentline;
    	for (int i = 0; i < num; i++) 
	{	
		//start=(start+1)%num;
        	new_tailbuf[i]=tailbuf[start];
        	start = (start + 1) % num;
    	}

    	free(tailbuf);

    	return new_tailbuf;
}

int main(int argc,char *argv[]) 
{
    FILE *fp = fopen(argv[1], "r");
    int num=atoi(argv[2]);
    char **lastlines = lastnumlines(fp,num);
    for (int i = 0; i < num; i++) 
    {
	if(lastlines[i]!=NULL)
	{
        printf("%s", lastlines[i]);
	free(lastlines[i]);
	}
    }
    free(lastlines);
    fclose(fp);
    return 0;
}

