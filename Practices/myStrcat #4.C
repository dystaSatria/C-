#include <stdio.h>
#include <stdlib.h>

char *myStrcat(char *s1, const char *s2)
{
strcpy(s1 + strlen(s1), s2);
return s1;
}
int main()
{
    char s1[] = " Reza ";
    char s2 [] = " dysta ";
{
//kendi myStrcat

char sentence [100]= {'\0'};

myStrcat(sentence,s1);
printf("%s\n", sentence);
myStrcat(sentence,s2);
printf("%s\n", sentence);

return 0;
}
return EXIT_SUCCESS;
}

