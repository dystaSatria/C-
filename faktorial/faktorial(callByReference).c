/******************************************************************************

                            Faktorial (Call by Reference)
                            
*******************************************************************************/

#include <stdio.h>
int factorial(int);


int main()
{
    int x;
    printf("Input your number :\n");
    
    scanf("%d", &x);
    
    if (x ==0) 
        printf("0! = 1");
    else 
        printf("\n%d! = %d", x, factorial(x));
        
}

int factorial(int x){
    int numeral, f = 1;
    
    for (numeral=1 ;numeral <= x; ++numeral)
        f = numeral * f;
    return f;
}

