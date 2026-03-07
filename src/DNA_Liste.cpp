/**
* @file DNA_Liste.cpp
* @description 

 her bir satırın içini  tutan ve  üzerlerinde  işlem yapan kaynak kod

* @course 2.öğretim B grubu
* @assignment veri yapıları 1. ödev
* @date 10.11.2024
* @author Ahmet Sevli      ahmet.sevli@ogr.sakarya.edu.tr
*/


#include "DNA_Liste.hpp"
#include <iomanip>


DNA_Liste::DNA_Liste()
{
	
	ilk_gen =nullptr;
	
	gen_sayisi=0; // hiç gen yokken gen sayısı sıfırdır
	
	
}//

 DNA_Liste::~DNA_Liste()
 {
	 //  amac ilk başta ilk düğüme gelmemiz gerek
	 // sonra son düğüme kadar gidip her geçtiğimizi silmek
	 // bunu yaparken arada yardımcı bir pointer (sil) kullanarak adresleri kybetmeden doğru bi şekilde son düğüme kadar ulaşmak gerek
	 
	 Gen_Dugum* gec=ilk_gen;
	 
	 while(gec!=nullptr)
	 {
		Gen_Dugum* sil=gec;
		gec=gec->sonraki_gen;
		
		delete sil;
		 
	 }
	 
	 
	 
	 
 }//

void DNA_Liste::gen_ekle(char veri_gen)
{
	Gen_Dugum * yeni_gen=new Gen_Dugum(veri_gen);
	
	if(ilk_gen==nullptr) // hiç düğüm yoksa yeni eklenen ilk düğüm olurn
	{
		ilk_gen= yeni_gen;
		
	}
	
	else // düğüm var demek en az 1 tane de olsa
	{
		Gen_Dugum *gec=ilk_gen;
		
		while(gec->sonraki_gen!=nullptr)
		{
			gec=gec->sonraki_gen;
		} // son düğüme geldik
		
		gec->sonraki_gen=yeni_gen;
		yeni_gen->onceki_gen=gec;
		
}
	// gen sayisini arttır
	  gen_sayisi++;
	
	
}//


char DNA_Liste::gen_getir()
{
	// ilk başta hiç gen var mı diye kontrol etmemiz gerek 
	
	if(ilk_gen==nullptr) // hiç düğüm yoksa orayı atlamalı
	{
		return ' '; // bu satırda hiç gen yok demek o yüzden orayı boş bırakmalı
		
	}
	
	// eğer en az 1 düğüm varsa;
	// ilk başta düğümdeki ilk harften en sona gitmeliyiz en sondan başa doğru karşılaştırma yapmalıyız
	
	Gen_Dugum* gec=ilk_gen;
	while (gec->sonraki_gen!=nullptr)
	{
		  gec=gec->sonraki_gen;
	}
	
	// en son gene geldik şimdi karşılaştırma zamanı
	
	
	char kucuk_gen;// geri döndürülecek olan gen
	 kucuk_gen=ilk_gen->veri_gen;  // ilk başta en küçüğü en baştaki gibi düşünüyorum
	
	while(gec!=ilk_gen)
	{
		if(gec->veri_gen<kucuk_gen)
		{
			kucuk_gen=gec->veri_gen;
			return kucuk_gen; // eger sondan başa doğru gelirken ilk genden daha küçük bir gene rastlarsak onu döndürecek
			
		}
		
		gec=gec->onceki_gen; // daha küçük gelmediği durumda son kaldığı genden bir önceki genle karşılaştırma yapmak için while a dönecek
	}
	
	
	return kucuk_gen;// eger sadece bir gen varsa veya en küçük gen ilk gense direk o harfi dönderecek
	
	
	
	
}//


void DNA_Liste::dna_yazdir()
{
	
	
	// amacımız bir geçici pointer ile dna nın sonuna giderken yazdırmak
	
	Gen_Dugum* gec=ilk_gen;
	
	while(gec!=nullptr)
	{
		
		cout<<gec->veri_gen<<" ";
		gec=gec->sonraki_gen;
	}
	
	// satırda hiç gen yoksa zaten buraya girdiği gibi çıkacağı için o satırı boş gösterecek ve doğru olacak
	
	
}//

