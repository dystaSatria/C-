#include <stdio.h>
#include <locale.h>

#define MAX_TEKLIF 100

typedef struct {
    double BaslangicFiyati[MAX_TEKLIF];
    int TeklifSayisi;
    double SonFiyat;
} Muzayede;

// Fiyat hesaplama fonksiyonu
double FiyatHesapla(Muzayede *Urun);

// Müzayede başlatma fonksiyonu
void MuzayedeBaslat(Muzayede *Urun) {
    printf("Müzayedeyken Teklif Miktarı 0 olsa , müzayede sonlandırılacak\n");
    double fiyat;
    Urun->TeklifSayisi = 0;
    do {
        printf("Güncel Fiyat: %.2lf\n", FiyatHesapla(Urun));
        printf("Lütfen Teklif Miktarını Giriniz:\n");
        if (scanf("%lf", &fiyat) != 1) {
            printf("Lütfen Geçerli Bir Sayı Giriniz!\n");
            fflush(stdin);
        }
        if (fiyat < 0) {
            printf("Negatif sayılar veya 0 dışında bir değer girmelisiniz.\n");
        } else {
            if (fiyat != 0) {
                Urun->BaslangicFiyati[Urun->TeklifSayisi] = fiyat;
                ++Urun->TeklifSayisi;
            } else {
                printf("Müzayede Sonlandırıldı\n");
            }
        }
    } while (fiyat != 0);
}

// Toplam fiyatı hesapla fonksiyonu
double FiyatHesapla(Muzayede *Urun) {
    int i;
    double toplamFiyat = 0.0;
    for (i = 0; i < Urun->TeklifSayisi; ++i) {
        toplamFiyat += Urun->BaslangicFiyati[i];
    }
    return toplamFiyat;
}

// Kazanan teklifin indeksini bulan fonksiyon
int PemenangIndeks(Muzayede *Urun) {
    double maksimum = 0.0;
    int indeks = -1;
    for (int i = 0; i < Urun->TeklifSayisi; ++i) {
        if (Urun->BaslangicFiyati[i] > maksimum) {
            maksimum = Urun->BaslangicFiyati[i];
            indeks = i;
        }
    }
    return indeks;
}

int main() {
    Muzayede Urun;
    setlocale(LC_ALL, "Turkish");
    printf("*****************************\n");
    printf("*   C Müzayede Programı     *\n");
    printf("*****************************\n");

    // Müzayede başlatma fonksiyonunu çağırma
    MuzayedeBaslat(&Urun);

    // Eğer herhangi bir teklif yapılmışsa
    if (FiyatHesapla(&Urun) != 0) {
        printf("Toplam ödemesi: %.2lf\nToplam Teklif Sayısı: %d\n", FiyatHesapla(&Urun), Urun.TeklifSayisi);
        int pemenangIndex = PemenangIndeks(&Urun);
        // Eğer kazanan teklif varsa
        if (pemenangIndex != -1) {
            printf("Müzayedeyi kazanan: Teklif Numarası %d, Miktar: %.2lf\n", pemenangIndex + 1, Urun.BaslangicFiyati[pemenangIndex]);
        } else {
            printf("Herhangi Bir Teklif Yapılmadı\n");
        }
    } else {
        printf("Herhangi Bir Teklif Yapılmadı\n");
    }

    return 0;
}
