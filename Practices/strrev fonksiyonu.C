#include <stdio.h>
#include <stdlib.h>


//buat dituker namanyaa
//misal reza jadinya azer
//fikret --> tikref --> tekrif --> terkif
char *myStrrev(char *str)
{
int lengthStr = strlen(str);
int i = 0;
int tempChr = 0;

for(i=0; i < lengthStr/2; ++i)
{
tempChr = str[i];
str[i] = str [lengthStr - i - 1];
str [lengthStr - i - 1] = tempChr;

}

return str;
}


int main(void)
{
{
char city[100];

printf("sehir ismi giriniz: ");
gets(city);
myStrrev(city);

printf("ters cervilmis durumu : %s\n", city);
}

return EXIT_SUCCESS;
}