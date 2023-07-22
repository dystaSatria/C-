//Perhitungan Matematika Pada Peluang Inbreeding Dalam Populasi Ternak Generasi Pertama

#include <stdio.h>

int main()
{
    int Ns, Nd, Nmp,Nmg,P1;
    
    printf("Inputkan Nilai Ns: ");
    scanf("%i", &Ns);
    
    printf("Inputkan Nilai Nd: ");
    scanf("%i", &Nd);

    Nmp = Ns * Nd; 
    
    printf("Hasil Ns * Nd = %i\n", Nmp);
    
    Nmg = (Nmp - 1) * (Nmp / 2 );
    printf("Hasil Nmg = %i\n", Nmg);
    return 0;
}
