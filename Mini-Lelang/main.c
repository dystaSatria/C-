#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Untuk setlocale

typedef struct {
    int no;
    double teklif;
} Kazanan;

typedef struct {
    int no;
    double teklif;
} Teklif;

typedef struct {
    int teklifveren_sayisi;
    Teklif *teklifler;
    double enyuksek_teklif;
    int kazanan_no;
} Artirma;

Artirma artirma_olustur(int teklifveren_sayisi) {
    Artirma a;
    a.teklifveren_sayisi = teklifveren_sayisi;
    a.teklifler = (Teklif *)malloc(teklifveren_sayisi * sizeof(Teklif));
    for (int i = 0; i < teklifveren_sayisi; i++) {
        a.teklifler[i].no = i;
        a.teklifler[i].teklif = 0.0;
    }
    a.enyuksek_teklif = 0;
    a.kazanan_no = -1;
    return a;
}

void teklif_ver(Artirma *a, int teklifveren_no, double teklif) {
    if (teklifveren_no >= 0 && teklifveren_no < a->teklifveren_sayisi) {
        a->teklifler[teklifveren_no].teklif = teklif;
        if (teklif > a->enyuksek_teklif) {
            a->enyuksek_teklif = teklif;
            a->kazanan_no = teklifveren_no;
        }
    }
}

Kazanan kazanan_belirle(Artirma a) {
    Kazanan k;
    k.no = a.kazanan_no;
    k.teklif = a.enyuksek_teklif;
    return k;
}

double odemeyi_hesapla(Artirma a, int kazanan_no) {
    double odeme = 0.0;
    for (int i = 0; i < a.teklifveren_sayisi; i++) {
        if (i != kazanan_no) {
            odeme += a.teklifler[i].teklif;
        }
    }
    return odeme;
}

void odemeyi_goster(double odeme) {
    printf("Hesaplanan odeme: %.2f\n", odeme);
}

int main() {
    setlocale(LC_ALL, "Turkish"); // Menyiapkan pengaturan lokal untuk bahasa Turkish

    // Memulai program lelang
    Artirma artirma;
    int teklifveren_sayisi;
    printf("Selamat datang di Program Lelang!\n");
    printf("Silakan masukkan jumlah penawar: ");
    scanf("%d", &teklifveren_sayisi);

    artirma = artirma_olustur(teklifveren_sayisi);

    // Memasukkan contoh penawaran
    printf("Masukkan penawaran:\n");
    for (int i = 0; i < teklifveren_sayisi; i++) {
        double teklif;
        printf("Masukkan penawaran dari penawar %d: ", i);
        scanf("%lf", &teklif);
        teklif_ver(&artirma, i, teklif);
    }

    Kazanan kazanan = kazanan_belirle(artirma);
    printf("Penawar pemenang: %d\n", kazanan.no);
    printf("Penawaran tertinggi: %.2f\n", kazanan.teklif);

    double odeme = odemeyi_hesapla(artirma, kazanan.no);
    odemeyi_goster(odeme);

    return 0;
}
