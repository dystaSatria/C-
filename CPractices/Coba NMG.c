// Kombinasi perkawinan pada tetua untuk menghasilkan generasi pertama pada sistem KA
//Kombinasi perkawinan pada generasi pertama pada sistem IB

#include <stdio.h>

int main()
{
	int n,d,i;
    int Jumlah;
    float P1=0;
	
	
	printf("NMP = NSTR\n");
	//Perhitungan NMP 
	printf("Jumlah pejantan :");
	scanf("%i", &n);
	int NMP = 0;
	int NMK=0;
  	for(i=1; i<=n; i++)
			{	
			printf("Masukkan nilai dosis : ");
			scanf("%i", &d);
			NMP += d;
			Jumlah = d*(d-1)*0.5;		 
			NMK += Jumlah;
			}
	  	
	printf("**************************************************************\n\n");
  	printf("Nilai NMP : %i\n\n", NMP);
  	printf("**************************************************************\n\n");
  	 	
  	printf("Nilai NMK : %i\n\n",NMK);
  	printf("**************************************************************\n\n");
  	
  	float NMG=0;
 	NMG= (NMP - 1) * (NMP * 0.5 );
    printf("Nilai Nmg = %.0f\n\n",NMG);
    
    printf("**************************************************************\n\n");
    
    P1 = NMK/NMG;
    printf("Nilai P1 = %.2f\n\n",P1);
   	return 0;
}
