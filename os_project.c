/* Operating System Concepts Project 1 */
/* Submitted by: */
/* Project Partners:- Shivam Gupta(NET ID: SXG190040)  &  Ashutosh Senapati(NET ID: AXS190030)  */

/* Names of Input Files:-  [f1.txt, f2.txt, f3.txt, f4.c, f5.txt, f6.txt, f7.txt, f8.yml, f9.txt, f10.txt, f11.c ]  */

/*  ## Compile:
                   gcc os_project.c
	## Run :
                ./a.out 11 f1.txt f2.txt f3.txt f4.c f5.txt f6.txt f7.txt f8.yml f9.txt f10.txt f11.c output.txt */
/* Import all the required C libraries */

#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>

/* Initialize the fork() and wait() functions call */
int fork(void);
int wait(int*);

/* Variables Initialization */
int i=0,j=0,num_files;


/* Main function */
int main(int argu_c, char *argu_v[])
{
/* Variable for wait function */
int w;
/*Converting the string to integer */
num_files = atoi(argu_v[1]);



/* Error checking if there are no sufficient number of arguments and input files */

	if (argu_c<4)
	{
	printf( " \n Please provide sufficient number of arguments and files \n ");
	exit(1);
	}
        if (num_files != argu_c-3)
	{
	printf( " \n Please provide sufficient number of Input files \n ");
	exit(1);
	}

    
    for(i=2;i<argu_c-1;i++) // Running the loop for argu_c-3 times
    { 
		/* Checking for the Child Process */

       if(fork() == 0) 
       {
	        /* opening all the files using file pointer */
            FILE *file_point = fopen(argu_v[i], "r");
	    
    

            /* a variable for holding the count of every character(all 256 characters) */
            int ch,frequency[256]={0};

            /* While loop till we extract the characters */
            while((ch=fgetc(file_point)))
            {

            /* break if End of File occurs */
            if(ch == EOF) break;

            /* Else add one to the counter for the specific character */
            frequency[ch]+=1;
            }
			/* File pointer for the output file */

            FILE *fwrite = fopen(argu_v[argu_c-1], "a");
			/* Writing the frequency of every character for every file */
            fprintf(fwrite, "_____Writing content of file name %s_____\n", argu_v[i]);
            for (j=0;j<256;j++)
            {
			/* Checking for only alphabets */
                if((j>=65) && ( j <=90))
			/* adding the count for small as well as the capital alphabets as they are treatesd in the same way  */

                {       
						frequency[j] = frequency[j] + frequency [j+32];
                        fprintf(fwrite,"frequeny of character %c is ==%d\n",(char) j,frequency[j]);


                }
            }

            exit(0);
       }
       


    }
  


    for(i=2;i<argu_c;i++) // loop will run argu_c-2 times for the wait operation to terminate the child processes 
        wait(NULL);
	printf("\n the argument count = %d \n",argu_c);
 	/*Displaying the message when Parent is successfully executed*/
	printf("\n Parent is successfully executed \n");
    
}
