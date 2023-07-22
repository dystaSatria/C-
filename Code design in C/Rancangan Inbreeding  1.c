
//Menurut formula matemtika

#include <stdio.h>
int main()
{
    float Nmg,Nmi,P1;
    int Ns, Nd ,Nmp;
    
    start :
    
    printf("Inputkan Nilai Ns: ");
    scanf("%i", &Ns);
    
    printf("Inputkan Nilai Nd: ");
    scanf("%i", &Nd);

    Nmp = Ns * Nd; 
    
    printf("Hasil Nmp = %i\n", Nmp);
    
    Nmg = (Nmp - 1) * (Nmp / 2 );
    printf("Hasil Nmg = %.0f\n", Nmg);
    
    Nmi = (Ns + Nd - 2) * ( Nmp /2)  ;
    printf("Hasil Nmi = %.f\n", Nmi);
    
    P1 =  Nmi / Nmg ;
    printf("Hasil P_1 = %.2f\n", P1 );
    
    goto start;
    
    return 0;
}
