#ifndef Kromozom_Liste_hpp
#define Kromozom_Liste_hpp
#include "Kromozom_Dugum.hpp"
#include <iostream>

class Kromozom_Liste
{
	public:
	
	Kromozom_Liste(); // kurucu
	~Kromozom_Liste(); // yok edici
	void dna_olustur(); // olusturma
	DNA_Liste * dna_dondur(); // en son oluşan dna yı return ile döndüerek üstünde işlem sağlayacak
	
	void kromozom_yazdir();// bütün dosyayı yani listeyi
	
	void kromozom_caprazlama(int dna1,int dna2); // verilen iki sıradaki dna yı çaprazlar
	void kromozom_oto_islem(Kromozom_Liste*liste); // dosyadaki işlemleri yapacak 
	void kromozom_ekranaYaz(); // her dna daki en küçüğü ekrana yazdıracağımız için parametreye gerek yok sanırım
	
    void kromozom_mutasyon(int dna_sira, int gen_sira);// ilk değişken hangi satırdaki dna olduğu ikinci değişken o satırdaki hangi geni x yapacağımız
	
	
	Kromozom_Dugum *ilk_dna;
	
	int dna_adet;
	
	

};

#endif
