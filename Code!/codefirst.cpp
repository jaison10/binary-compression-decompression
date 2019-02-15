#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_RLEN 50 

char str[] = "11110000"; 
char* dest;
int i, j = 0, k;

/* Returns the Run Length Encoded string for the  

   source string src */

char* enc(char* src) 
{ 

    int rLen; 

    char count[MAX_RLEN];

    int len = strlen(src);

	
    dest = (char*)malloc(sizeof(char) * (len * 2 + 1)); 
    

    /* traverse the input string one by one */

    for (i = 0; i < len; i++) { 

        /* Copy the first occurrence of the new character */

        dest[j++] = src[i];

        /* Count the number of occurrences of the new character */

        rLen = 1; 

        while (i + 1 < len && src[i] == src[i + 1]) { 
        
            rLen++;

            i++;
        } 

        /* Store rLen in a character array count[] */

        sprintf(count, "%d", rLen); 

        // Copy the count[] to destination 

        for (k = 0; *(count + k); k++, j++)
		{

            dest[j] = count[k]; 

        } 

    } 

    /*terminate the destination string */

    dest[j] = '\0'; 
	printf("\n Compression result: %s",dest);    // Compression Result!
	
	printf(" \n value of j is %d",j);                   //testing
	printf(" \n valur of des[0] is %c ", dest[0]);     //testing
	getchar();
	
} 

char dec()
{
	int index_res=0,addcount;
	char decres[8];
	printf("\n value of j in decomp is : %d",j);                //testing
	printf("\n Value of des[1] in decomp is : %s",dest);       //testing
	
	for(int s=0;s<j;s++)        // Decompression starts! 
	{
		if(dest[s+1]==0||dest[s+1]==1) 
		{
			decres[index_res]=dest[s]; 
			index_res++; 
		} 
		else 
		{
			for( addcount=1;addcount<=dest[s+1];addcount++)  
			{
				decres[index_res]=dest[s];
				index_res++;
			}
			s++;
		}
	}
	printf("\n Decompression result: %s",decres);        // Decompression result!
	
}

int main() 
{ 
    enc(str);   //calling encoding function!
	dec();     //calling encoding function!
	
    getchar(); 
} 

