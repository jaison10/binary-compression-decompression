#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main(void)
{
       
     srand(time(NULL));  // to prevent sequence repetition between runs   

  
     for(int i = 1; i <=8; i++)     // looping to print 8 numbers
     {
           cout<< rand( ) % 2;   // formula for numbers 
     }

     return 0;
}

