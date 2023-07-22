#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strset
//char *strset(char *str,int ch);

char *strset (char *str,int ch)
{
while( *str != '\0')
{
*str = ch;
++str;

}
return str;
}
int main(void)
{
{
char str[100];
int ch = 0;

printf("Bir yazi giriniz:");
gets(str);
printf("yaziyi hangi karakter ile doldurmak istersiniz:");
ch = getchar();

printf("ilk durumu: %s\n", str);
myStrset(str, ch);
printf("ikinci durumu: %s\n", str);
}

return EXIT_SUCCESS;
}
