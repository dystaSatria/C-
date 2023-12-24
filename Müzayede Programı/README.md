# Basit Açık Artırma Programı Algoritması

## Veri Yapısının Başlatılması

- `Muzayede` veri yapısı, açık artırma ile ilgili bilgileri saklamak için kullanılır.
- `BaslangicFiyati`, katılımcılar tarafından girilen teklifleri saklar.
- `TeklifSayisi`, girilen toplam teklif sayısını izlemek için kullanılır.
- `SonFiyat`, tüm tekliflerin toplam değerini saklar.

## `FiyatHesapla` Fonksiyonu

- `FiyatHesapla`, girilen tüm tekliflerin toplam değerini hesaplamakla sorumludur.
- Bir döngü aracılığıyla, tüm teklif değerleri toplam değere eklenir.

## `MuzayedeBaslat` Fonksiyonu

- `MuzayedeBaslat`, kullanıcıdan teklif girişi yapmalarını ister ve açık artırmayı başlatır.
- Sonsuz bir döngü içinde, kullanıcıdan teklif girmesi istenir.
- Kullanıcı negatif veya sıfır değerleri girdiğinde hata mesajı verilir.
- Kullanıcı sıfır değeri girdiğinde, açık artırma işlemi sona erer.

## `KazananIndeks` Fonksiyonu

- `KazananIndeks`, en yüksek teklifin indeksini bulmak için kullanılır.
- Tüm teklifler üzerinde bir döngü ile en yüksek teklifin indeksi belirlenir.

## Ana Fonksiyon (Main)

- `Muzayede` veri yapısının başlatılması ve Türkçe mesajların gösterilmesi için yerel ayarların yapılması.
- Açık artırma programına hoş geldiniz mesajının gösterilmesi.
- Açık artırma işlemini başlatmak için `MuzayedeBaslat` fonksiyonunun çağrılması.
- Açık artırma işlemi bittikten sonra, aşağıdaki sonuçların gösterilmesi:
    - Toplam teklif miktarı.
    - Eğer teklif varsa, en yüksek değere sahip olanın gösterilmesi.

### Önemli Notlar

- **Giriş Doğrulaması**: Program, sadece teklif girişlerinde negatif veya sıfır değerlerini kontrol eder.
- **Girişlerin İşlenmesi**: Kullanıcı girişleri, sayısal değerler için `scanf` fonksiyonu kullanılarak alınır.
- **Döngü**: Açık artırma süreci, kullanıcı sıfır değeri girene kadar sonsuz bir döngü içinde devam eder.

Bu açıklama, açık artırma programınızın algoritmasını anlamak için detaylı bir rehber sunar ve gerektiğinde daha kapsamlı bir şekilde genişletilebilir.
