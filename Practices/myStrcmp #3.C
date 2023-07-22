#include <stdio.h>
#include <stdlib.h>

int *myStrcmp(const char *s1, const char *s2)
{
int retValue = 0;

while ( *s1 == *s2 )
{
if(*s1 == '\0')
{
retValue = 0;
break;
}
++s1;
++s2;


}
retValue = *s1 - *s2;

return retValue;
}
int main()
{
    char s1[] = " Reza ";
    char s2 [] = " dysta ";
{
//kendi myStrcmp


int compare = myStrcmp (s1, s2);
printf("compare = %d\n", compare);
}
return EXIT_SUCCESS;
}
