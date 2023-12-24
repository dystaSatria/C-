# Basit Açık Artırma Programı Algoritması (Müzayede Programı)

<br>

## Açıklama

Bu program, basit bir açık artırma sistemini simüle eder. Kullanıcıdan belirli bir ürün için tekliflerini belirtmesi istenir ve bu tekliflerin miktarı girilir.

## Özellikler

- **Açık Artırmayı Başlatma:** Program, kullanıcının nominal tekliflerini girmesini isteyerek açık artırma işlemini başlatır.
- **Açık Artırmayı Sonlandırma:** Kullanıcı 0 değerini girdiğinde, açık artırma işlemi sona erer ve program kazananı ve toplam teklifi görüntüler.
- **Kazananın Seçimi:** Program, en yüksek teklife dayanarak kazananı belirler.

##  Tekniksel Açıklaması

<br>

### Veri Yapısının Başlatılması

- `Muzayede` veri yapısı, açık artırma ile ilgili bilgileri saklamak için kullanılır.
- `BaslangicFiyati`, katılımcılar tarafından girilen teklifleri saklar.
- `TeklifSayisi`, girilen toplam teklif sayısını izlemek için kullanılır.
- `SonFiyat`, tüm tekliflerin toplam değerini saklar.

### `FiyatHesapla` Fonksiyonu

- `FiyatHesapla`, girilen tüm tekliflerin toplam değerini hesaplamakla sorumludur.
- Bir döngü aracılığıyla, tüm teklif değerleri toplam değere eklenir.

### `MuzayedeBaslat` Fonksiyonu

- `MuzayedeBaslat`, kullanıcıdan teklif girişi yapmalarını ister ve açık artırmayı başlatır.
- Sonsuz bir döngü içinde, kullanıcıdan teklif girmesi istenir.
- Kullanıcı negatif veya sıfır değerleri girdiğinde hata mesajı verilir.
- Kullanıcı sıfır değeri girdiğinde, açık artırma işlemi sona erer.

### `KazananIndeks` Fonksiyonu

- `KazananIndeks`, en yüksek teklifin indeksini bulmak için kullanılır.
- Tüm teklifler üzerinde bir döngü ile en yüksek teklifin indeksi belirlenir.


### Ana Fonksiyon (Main)

- `Muzayede` veri yapısının başlatılması ve Türkçe mesajların gösterilmesi için yerel ayarların yapılması.
- Açık artırma programına hoş geldiniz mesajının gösterilmesi.
- Açık artırma işlemini başlatmak için `MuzayedeBaslat` fonksiyonunun çağrılması.
- Açık artırma işlemi bittikten sonra, aşağıdaki sonuçların gösterilmesi:
    - Toplam teklif miktarı.
    - Eğer teklif varsa, en yüksek değere sahip olanın gösterilmesi.
 
## Notlar

- **Giriş Doğrulaması**: Program, sadece teklif girişlerinde negatif veya sıfır değerlerini kontrol eder.
- **Girişlerin İşlenmesi**: Kullanıcı girişleri, sayısal değerler için `scanf` fonksiyonu kullanılarak alınır.
- **Döngü**: Açık artırma süreci, kullanıcı sıfır değeri girene kadar sonsuz bir döngü içinde devam eder.

 
### Kodu

```c
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
int KazananIndeks(Muzayede *Urun) {
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
        int kazananIndex = KazananIndeks(&Urun);
        // Eğer kazanan teklif varsa
        if (kazananIndex != -1) {
            printf("Müzayedeyi kazanan: Teklif Numarası %d, Miktar: %.2lf\n", kazananIndex + 1, Urun.BaslangicFiyati[kazananIndex]);
        } else {
            printf("Herhangi Bir Teklif Yapılmadı\n");
        }
    } else {
        printf("Herhangi Bir Teklif Yapılmadı\n");
    }

    return 0;
}



```

### Console Ekran Görüntüsünü

![resim](https://github.com/dystaSatria/C-/blob/main/M%C3%BCzayede%20Program%C4%B1/Screenshot%202023-12-24%20at%2022.14.34.png)


