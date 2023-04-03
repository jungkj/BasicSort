#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage();
int is_valid_num(char *word);
void swap(double *x, double *y);
void sort(double *a, int length);

int is_valid_num(char *word)
{
    int found_dot = 0;

    for (int i=0; i<strlen(word); ++i)
    {
        if (word[i] == '-')
        {
            if (i != 0)
            {
                return 0;
            }
            continue;
        }

        if (word[i] == '.')
        {
            if (found_dot == 1)
            {
                return 0;
            }
            found_dot = 1;
            continue;
        }

        if (!isdigit(word[i]))
        {
            return 0;
        }
    }

    return 1;
}

void usage()
{
	printf("usage: sort[-r] num1 num2 ...\n\t-r: reverse sort\n");
}

void swap(double *x, double *y)
{
        double temp; 
	temp = *x;
        *x = *y;
	*y = temp;
}

void sort(double *a, int length){
	int i, j; 
	for (i = 1; i < length; ++i){
		j = i; 
		while (j > 0 && a[j-1] > a[j])
		{
			swap(&a[j], &a[j-1]);
			--j;
		}
		
	}
}

int main(int argc, char *argv[])
{
    if (argc < 1)
	    usage();
    int counter;
    int testr=0;
    for (int i = 0; i < argc; ++i)
    {
	    ++counter;
    }
   
    double *arrayofnum = (double *)calloc(counter, sizeof(double));
    
    if (argv[1][0] == '-' && argv[1][1] == 'r')
    {
	    if (argc > 2)
	    {
	    testr = 1;
	    }
	    else
	    {
	    usage();
	    }
    }
    for (int i = 1; i < argc; ++i)
    {
	   if (is_valid_num(argv[i]) == 1 || testr ==1)
	   {
		   arrayofnum[i] = atof(argv[i]);
	   }
	   else 
	   {
		  
		   printf("%s is not a valid number\n", argv[i]);	  
 		   return 0;
	   }
    }    


    sort(arrayofnum, argc); 
    if (testr == 1)
    {
	    for (int i = argc-1; i > 1; i--)
	    {
		    printf("%f\n", arrayofnum[i]);
	    }
    }
    else
    {
	    for (int i = 1; i < argc; ++i)
	    {
		    printf("%f\n", arrayofnum[i]);
	    }
    }
}

