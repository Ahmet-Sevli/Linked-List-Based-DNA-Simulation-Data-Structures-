Bu program, metin belgelerinden okunan DNA sekansları (Kromozom ve Genler) üzerinde bağlı listeler (Linked List) kullanarak çeşitli genetik işlemleri simüle eden bir C++ uygulamasıdır. Hazır veri yapıları (ArrayList, std::list vb.) ve şablon (generic) sınıflar kullanılmadan, tamamen özel bağlı liste düğümleri tasarlanarak geliştirilmiştir. 



Özellikler:

1. Çaprazlama (Crossover): İki farklı kromozomun ortadan bölünerek çapraz birleştirilmesiyle yeni kromozomlar üretilir.

2. Mutasyon (Mutation): İstenen kromozom ve gen indeksine gidilerek ilgili gen 'X' karakterine dönüştürülür.

3. Otomatik İşlemler: "Islemler.txt" dosyasından okunan komutlar (Örn: C13, M51) sırasıyla toplu olarak işletilir.

4. Ekrana Yaz: Her kromozom için sağdan sola tarama yapılarak ödev föyünde belirtilen kurala uygun gen tespit edilir ve ekrana yazdırılır.



DERLEME VE ÇALIŞTIRMA (MinGW):

Program, sağlanan "makefile" kullanılarak derlenmelidir. Komut satırında, ana proje dizinindeyken (makefile ile aynı dizinde) aşağıdaki komutu giriniz:



    mingw32-make



Bu komut, "src" klasöründeki kaynak kodları "include" klasöründeki başlık dosyalarıyla birlikte derleyecek, nesne (.o) dosyalarını "lib" klasörüne yerleştirecek ve son olarak çalıştırılabilir dosyayı "bin" klasöründe oluşturacaktır.



GEREKSİNİMLER VE GİRDİ DOSYALARI:

- Programın başarıyla çalışması ve verileri okuyabilmesi için dizinde geçerli bir "Dna.txt" dosyası bulunmalıdır.

- Otomatik işlemler seçeneğinin çalışabilmesi için komutların bulunduğu "Islemler.txt" dosyası gereklidir.



BELLEK YÖNETİMİ:

Projede dinamik olarak tahsis edilen bellek alanları (new ile oluşturulan düğümler), kromozomlar silindiğinde veya program sonlandığında yıkıcı metotlar (destructors) aracılığıyla temizlenmektedir. Herhangi bir bellek sızıntısına (memory leak / çöp oluşumuna) mahal verilmemiştir.
