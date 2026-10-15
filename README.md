# Bağlı Listeler ile DNA ve Kromozom Simülasyonu

Bu proje, C++ kullanılarak standart şablon kütüphaneleri (STL) kullanılmadan, tamamen özelleştirilmiş **Bağlı Liste (Linked List)** veri yapıları ile geliştirilmiş bir DNA, Kromozom ve Gen simülasyonudur.

Proje kapsamında `Dna.txt` dosyasından okunan kromozom dizilimleri üzerinde çaprazlama (crossover) ve mutasyon gibi genetik işlemler yapılmakta ve sonuçlar dinamik olarak yönetilmektedir.

## 🧬 Özellikler

Program, kullanıcıya interaktif bir menü sunar ve aşağıdaki işlemleri gerçekleştirir:

1. **Çaprazlama (Crossover):** 
   - Kullanıcıdan alınan iki kromozom satır indeksi üzerinden çaprazlama yapar.
   - İlk kromozomun sol yarısı ile ikinci kromozomun sağ yarısını birleştirir. Aynı işlemi diğer yarılar için de uygulayarak iki yeni kromozom üretir ve popülasyonun (bağlı listenin) sonuna ekler.
2. **Mutasyon:** 
   - Belirtilen satır (kromozom) ve sütun (gen) indeksindeki geni 'X' karakteri ile değiştirerek mutasyona uğratır.
3. **Otomatik İşlemler:** 
   - `Islemler.txt` dosyasındaki talimatları (Çaprazlama için 'C', Mutasyon için 'M') sırasıyla ve otomatik olarak tüm popülasyona uygular.
4. **Ekrana Yaz:** 
   - Popülasyondaki kromozomları belirli bir kurala göre ekrana basar: Her kromozomda sağdan sola doğru taranarak, kromozomun ilk geninden (en soldaki) alfabetik olarak daha küçük olan ilk gen ekrana yazdırılır. Eğer bulunamazsa ilk genin kendisi yazdırılır.

## 🛠️ Teknik Detaylar ve Kısıtlamalar

* **Dil ve Derleyici:** MinGW C++ ortamında derlenmiştir.
* **Veri Yapıları:** Hazır veri yapıları (`std::list`, `std::vector` vb.) veya C++ Şablon (Generic/Template) mimarisi **kullanılmamıştır**. Tüm bağlı liste yapıları sıfırdan implemente edilmiştir.
* **Bellek Yönetimi:** Dinamik bellek tahsisi işlemleri (pointer'lar) titizlikle yönetilmiş olup, bellek sızıntısını (memory leak/çöp oluşumu) önlemek için gerekli yıkıcı (destructor) metotlar yazılmıştır.
* **Mimari:** Her sınıfın `.hpp` (başlık) ve `.cpp` (kaynak) dosyaları ayrılarak Nesne Yönelimli Programlama (OOP) prensiplerine uygun tasarlanmıştır. Başlık dosyalarında metot gövdesi bulunmamaktadır.

## 📁 Klasör Hiyerarşisi

Proje, aşağıdaki dizin yapısına uygun olarak geliştirilmiştir:

```text
📂 Proje_Ana_Dizini
 ┣ 📂 bin        # Çalıştırılabilir dosya (.exe) burada oluşturulur
 ┣ 📂 doc        # Proje raporu (Odev1.pdf) vb. dokümanlar
 ┣ 📂 include    # Sınıflara ait başlık (.hpp / .h) dosyaları
 ┣ 📂 lib        # Derlenmiş nesne (.o) dosyaları
 ┣ 📂 src        # Kaynak (.cpp) dosyaları
 ┣ 📜 benioku.txt # Geliştirici notları
 ┣ 📜 Dna.txt     # Başlangıç popülasyonunu içeren girdi dosyası
 ┣ 📜 Islemler.txt# Otomatik işlemler için komut dosyası
 ┗ 📜 makefile    # Proje derleme talimatları
```

## 🚀 Kurulum ve Çalıştırma

Projeyi derlemek ve çalıştırmak için sisteminizde **MinGW** (ve `mingw32-make` komutu) kurulu olmalıdır.

1. Projeyi bilgisayarınıza klonlayın veya indirin.
2. Terminal (Komut İstemcisi) üzerinden projenin ana dizinine gidin.
3. Aşağıdaki komutu çalıştırarak projeyi derleyin:
   ```bash
   mingw32-make
   ```
   *(Eğer make sisteminiz farklı yapılandırıldıysa sadece `make` komutunu da kullanabilirsiniz.)*
4. Derleme işlemi başarıyla tamamlandıktan sonra programı çalıştırmak için:
   ```bash
   ./bin/program.exe
   ```
   *(Not: `program.exe` ismi makefile'ınızda belirlediğiniz çıktı ismine göre değişiklik gösterebilir.)*

## 📄 Girdi Dosyası Formatları

**1. Dna.txt Örneği:**
Kromozomlar satırlar halinde, genler ise aralarında boşluk bırakılarak yazılmalıdır.
```text
A C F Y U D K R
D E V U
O L Z E R Q W X A C
M U A D T R
```

**2. Islemler.txt Örneği:**
* `C <satır1> <satır2>` : Çaprazlama işlemi
* `M <satır> <sütun>` : Mutasyon işlemi (İndeksler 0'dan başlar)
```text
C 0 3
C 0 6
M 5 1
```

## 👤 Geliştirici

Bu proje, Sakarya Üniversitesi (veya ilgili kurum) Veri Yapıları dersi ödev isterleri doğrultusunda geliştirilmiştir.

* **Ad Soyad:** [Ahmet SEVLİ]
