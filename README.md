# 🧬 DNA ve Kromozom İşlemleri (Bağlı Liste Uygulaması)

Bu proje, C++ kullanılarak geliştirilmiş ve standart şablon kütüphaneleri (STL) veya hazır veri yapıları kullanılmadan **tamamen özel bağlı liste (Linked List)** mimarisiyle tasarlanmış bir genetik algoritma simülasyonudur. Proje, metin dosyalarından okunan DNA dizilimleri üzerinde çaprazlama (crossover) ve mutasyon gibi işlemleri bellek yönetimine dikkat ederek gerçekleştirir.

## 🚀 Özellikler

- **Özel Veri Yapıları:** `std::list`, `std::vector` vb. hazır yapılar kullanılmamıştır. Düğümler (Node) arası pointer yönetimi manuel olarak sağlanmıştır.
- **Dinamik Bellek Yönetimi:** Çöp oluşumunu (memory leak) önlemek için destructor'lar (yıkıcı metotlar) ile bellek temizliği yapılır.
- **Çaprazlama (Crossover):** Seçilen iki kromozom ortadan bölünerek genetik materyal takası yapılır ve yeni kromozomlar popülasyona eklenir.
- **Mutasyon:** Belirtilen satır ve sütundaki gen `X` karakteri ile mutasyona uğratılır.
- **Toplu/Otomatik İşlem:** `Islemler.txt` dosyasındaki komut seti okunarak işlemler sırasıyla otomatik olarak uygulanır.

## 🛠️ Teknolojiler ve Araçlar

- **Dil:** C++
- **Derleyici:** MinGW (GCC)
- **Derleme Aracı:** Make (Makefile)

## 📁 Proje Hiyerarşisi

Proje, düzenli bir derleme süreci için standart C++ klasör yapısına uygundur:

```text
├── bin/          # Derlenmiş çalıştırılabilir (.exe) dosya
├── doc/          # Proje raporları ve dokümantasyon
├── include/      # Başlık dosyaları (.hpp / .h)
├── lib/          # Derlenmiş nesne dosyaları (.o)
├── src/          # Kaynak kod dosyaları (.cpp)
├── Dna.txt       # Başlangıç popülasyonunu içeren veri dosyası
├── Islemler.txt  # Otomatik çalıştırılacak komut dosyası
└── makefile      # Derleme kurallarını içeren dosya
```

## ⚙️ Kurulum ve Çalıştırma

Projeyi kendi bilgisayarınızda derleyip çalıştırmak için sisteminizde **MinGW** kurulu olmalı ve ortam değişkenlerine eklenmiş olmalıdır.

1. Repoyu klonlayın:
   ```bash
   git clone https://github.com/kullaniciadiniz/proje-adi.git
   ```
2. Proje dizinine gidin ve `make` komutunu çalıştırın:
   ```bash
   mingw32-make
   ```
3. Oluşan `.exe` dosyasını çalıştırın:
   ```bash
   ./bin/program.exe
   ```

*(Not: Girdi dosyaları olan `Dna.txt` ve `Islemler.txt` dosyalarının ana dizinde bulunduğundan emin olun.)*

## 📝 Lisans ve Kredi

Bu proje, Sakarya Üniversitesi Veri Yapıları dersi kapsamında bir akademik ödev olarak geliştirilmiştir. İzinsiz akademik kopyalanması tavsiye edilmez.
