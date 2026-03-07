#ifndef DNA_Liste_hpp
#define DNA_Liste_hpp
#include <iostream>
#include "Gen_Dugum.hpp"
using namespace std;


class DNA_Liste
{
	public:
	
	DNA_Liste(); // kurucu
	~DNA_Liste(); // yok edici
	void gen_ekle(char veri_gen); // gen ekleme
	char gen_getir(); // en küçük ilk geni döndüren 
	void dna_yazdir();// bir satırı yani bir kromozomu yazdıran 
	
	

	
	
	Gen_Dugum *ilk_gen; // ilk genin adresini tutan
	
	int gen_sayisi; // bir kromozomda kaç gen olduğunu tutan


};







#endif