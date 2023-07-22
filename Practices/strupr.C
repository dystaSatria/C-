#include <stdio.h>
#include <stdlib.h>
//strupr fonksiyonu
//dari kecil ke huruf besar

int main(void)
{
{
char city[100];
printf("sehir ismi giriniz: ");
gets(city);
strupr(city);
printf("Buyuk harf sehir ismi : %s\n", city);
}

return EXIT_SUCCESS;
}
