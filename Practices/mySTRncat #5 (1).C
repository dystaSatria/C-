#include <stdio.h>
#include <stdlib.h>



char *myStrncat(char *s1, const char *s2, unsigned int n)
{
printf("myStrncat cagrıldı\n");
char *ptr = s1 + strlen(s1);
while ( ( n > 0 ) && ( *s2 != '\0' ))
{
*ptr = *s2;
--n;
++s2;
++ptr;
}

*ptr = '\0';

return s1;
}
int main(void)
{
char s1[]="reza";
char s2[]="DYSTA";
{



unsigned int n = 0 ;


printf("Eklenecek karakter sayısı giriniz: ");
scanf("%d", &n);

printf("s1 : %s\n", s1);
myStrncat(s2, s1, n);
printf("s2 : %s\n", s2);
}
return EXIT_SUCCESS;
}