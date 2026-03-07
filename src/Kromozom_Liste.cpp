/**
* @file Kromozom_Liste.cpp
* @description 

 her bir satırı tutan ve  üzerlerinde  işlem yapan kaynak kod

* @course 2.öğretim B grubu
* @assignment veri yapıları 1. ödev
* @date 10.11.2024
* @author Ahmet Sevli      ahmet.sevli@ogr.sakarya.edu.tr
*/


#include "Kromozom_Liste.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Kromozom_Liste::Kromozom_Liste()
{
	
	ilk_dna =nullptr;
	
	dna_adet=0;
	
	
}//

 Kromozom_Liste::~Kromozom_Liste()
 {
	 
	 // amacımız ilk başta satırlardaki genleri yok etmek // bunu dna nın kendi yok edicisi yapabilir eğer ilgili dna ya ulaşırsam
	 // ardından kromozomun kendi düğümlerini yok etmek
	 
	 // bunu dna nın yok edicisini kullanarak yapabiliriz
	 
	 
	 Kromozom_Dugum* gec_dna=ilk_dna;
	 
	 while(gec_dna!=nullptr)
	 {
		 Kromozom_Dugum* sil_dna=gec_dna;
		 
		 gec_dna=gec_dna->sonraki_dna;
		 
		 // burda ilk başta dna nın içini silmem lazım sonra dna nın bulunduğu kromozom düğümünü yani satırı
		 
		 delete sil_dna->dna; // new ile aldığımız için düğümde kendimiz silmemiz gerek (bu kısım satırın içi için)
		
		 delete sil_dna; // bu kısım satırları tutan işaretçilerin silinmesi için
		
	 }
	 
	 
	 
	 
 }//
 

void Kromozom_Liste::dna_olustur()
{
	
	// bir satır okunduğu zaman kromozomun listesinde içinde bir dna bağlı listesi oluşan bir düğüm üreterek bize dna yı bağlayabileceğimiz bir uç verecek
	
	Kromozom_Dugum * yeni_dna=new Kromozom_Dugum();
	
	if(ilk_dna==nullptr) // hiç düğüm yoksa yeni eklenen ilk düğüm olurn
	{
		ilk_dna= yeni_dna;
		
		
	}
	
	else // düğüm var demek en az 1 tane de olsa
	{
		Kromozom_Dugum *gec=ilk_dna;
		
		while(gec->sonraki_dna!=nullptr)
		{
			gec=gec->sonraki_dna;
		} // son düğüme geldik
		
		gec->sonraki_dna=yeni_dna;
		
		 
   }
	dna_adet++;
	
	
	
}//



DNA_Liste* Kromozom_Liste::dna_dondur() 
{
	
	// bir satır okunduğunda bir düğüm oluşacak ve bu düğümdeki dna pointerini döndürerek işlem yapacaz
	// yer yerni satıra geçildiğinde aslında kromozomun en son düğümündeki dna pointeriyle işlem yapılır mantıken
	// yani o zaman biz hep en son pointeri döndürerek onun üstünde işlem yapabiliriz
	// tek düğüm varsa zaten ilk düğüm son düğümdür aynı şey
	
	//amacımız son dğüme gitmek ve düğümdeki dna bağlı listesinin pointerini döndürmek döndürmek
	
	 Kromozom_Dugum * gec=ilk_dna;
	 
	 while(gec->sonraki_dna!=nullptr)
	 {
		 
		 gec=gec->sonraki_dna;
	 }

	
   
	return gec->dna; // dna DNA_Liste türünden bir pointer
	 
	
}//






void  Kromozom_Liste::kromozom_yazdir()
{
	
	// dosyadaki her şeyi yazabilmemiz için olustur_dondur fonksiyonu ile dna bağlı listelerine ulaşıp
	// dna bağlı listesi pointerının bir fonksiyonu olan dna yazdır fonksiyonuna erişecem
	
	
	int sira=0;
	
	Kromozom_Dugum* gec=ilk_dna;
	
	while(gec!=nullptr)
	{
		cout<<sira<<"-) ";
		gec->dna->dna_yazdir();
		cout<<endl;
		gec=gec->sonraki_dna;
		sira++;
	}
	
  
}



void Kromozom_Liste::kromozom_caprazlama(int dna1,int dna2)
{
	// amacım parametrde verilen sıradaki dna lara ulaşmak
	// çaprazlamadan oluşacak olann yeni iki dna için kromozomda düğüm oluşturmak
	// ulaştığım dna ların gen sayılarının tek mi çift mi olduğuna karar vermek
	// birinci çaprazlanacak dna nın ön yarısı ile ikincinin yarısında olan genleri kopyalayıp yeni oluşan dna pointerine atamak
	// bunu ikinci oluşacak çapraz dna için birincinin arka yarısı ile ikincinin ön yarısındaki genlerin kopyasını ikinci çapraza atmak
	
	
	// dna1 e ulaşmak
	
	if(dna1>=dna_adet || dna1<0)  // eğer satır numaralarından fazla veya 0 dan küçük değer girilirse 
	 {
		 cout<<"mevcut kromozom listesinin disina ciktiniz lutfen tekrar deneyin...."<<endl<<endl;
		return;
		 
	 }
	
	
	Kromozom_Dugum *gec1=ilk_dna;
	
	
	for(int i=0;i<dna1;i++)
	{
		gec1=gec1->sonraki_dna;
	}
	
	// dna2 ye ulaşmak
	
	if(dna2>=dna_adet || dna2<0)  // eğer satır numaralarından fazla veya 0 dan küçük değer girilirse 
	 {
		 cout<<"mevcut kromozom listesinin disina ciktiniz lutfen tekrar deneyin...."<<endl<<endl;
		return;
		 
	 }
	
	Kromozom_Dugum* gec2=ilk_dna;
	
	
	for(int i=0;i<dna2;i++)
	{
		gec2=gec2->sonraki_dna;
	}
	
	// çaprazlamadan doğacak olan birinci yeni dna düğümünü oluşturmak
	
	dna_olustur();
	
	// dna1 in ön dna2 nin arka yarısını yeni oluşan dna ya kopyalamak
	// tek çift durumu göz önüne alınacak
	
	// dna1 den okunan değerleri for döngüsü ile birinci yeniyi döndürme fonksyonu ile ulaşıp genleri ekleme işlemi
	
	Gen_Dugum*gecici1 =gec1->dna->ilk_gen; // düğümlerde olan dna ların içine girip içindeki harf verilerine ulaşabilmek için
	Gen_Dugum*gecici2 =gec2->dna->ilk_gen;
	
		for(int i=0;i<(gec1->dna->gen_sayisi)/2;i++)
		{
			dna_dondur()->gen_ekle(gecici1->veri_gen);
			gecici1=gecici1->sonraki_gen;
			
		} // dna1 in  ön yarısı kopyalandı
		
		
	
	
	if(gec2->dna->gen_sayisi%2!=0) // ikinci genin sayısı tek ise
	{
		
		// ilk başta yarısından iki sonraki gene gitmek gerek çünkü bir tanesini atlayıp bir tane daha ileri gimek gerek
		
		for(int i=0;i< ((gec2->dna->gen_sayisi)/2) + 1 ;i++)
		{
			gecici2=gecici2->sonraki_gen;
			
		}
		
		
		
	}
	
	else // ikinci dna nın gen sayısı çiftse yarısından bir sonraki gene gitmek gerek
	{
		
		for(int i=0;i< ((gec2->dna->gen_sayisi)/2) + 0 ;i++)
		{
			gecici2=gecici2->sonraki_gen;
			
		}
		
	}
	
	// şuan gecici2  yarısının arka kısımdan eklenecek genin düğümüne ulaştı şimdi bunu en son oluşan dna düğümünün gen düğümlerine ekleme zamanı
	
	
	for(int i=0;i<(gec2->dna->gen_sayisi)/2;i++)
		{
			dna_dondur()->gen_ekle(gecici2->veri_gen);
			gecici2=gecici2->sonraki_gen;
			
		} // dna2 in  arka yarısı kopyalandı
	
	
	// şimdi sırada dna1 nin arka kısmı ile dna2 in ön kısmı kopyalanmalı
	// bunun için yeni bir dna daha oluşmalı
	dna_olustur();
	
	// artık dna döndür  en son dna yı döndürdüğü için bu yeni oluşan dna yı döndürür yani çaprazlamadan oluşması gereken 2. dna oluştu
	// geri döndürülüp içine gen yazılabilir
	
	Gen_Dugum*gecici1_2 =gec1->dna->ilk_gen; // düğümlerde olan dna ların içine girip içindeki harf verilerine ulaşabilmek için
	Gen_Dugum*gecici2_2=gec2->dna->ilk_gen;
	
	
		
	
	
	if(gec1->dna->gen_sayisi%2!=0) // birinci genin sayısı tek ise
	{
		
		// ilk başta yarısından bir sonraki gene gitmek gerek çünkü bir tanesini atlayıp bir tane daha ileri gimek gerek
		
		for(int i=0;i< ((gec1->dna->gen_sayisi)/2) + 1 ;i++)
		{
			gecici1_2=gecici1_2->sonraki_gen;
			
		}
		
		
		
	}
	
	
	
	else // birinci dna nın gen sayısı çiftse yarısından bir sonraki gene gitmek gerek
	{
		
		for(int i=0;i< ((gec1->dna->gen_sayisi)/2) + 0 ;i++)
		{
			gecici1_2=gecici1_2->sonraki_gen;
			
		}
		
	}
	
	
	for(int i=0;i<(gec1->dna->gen_sayisi)/2;i++)
		{
			dna_dondur()->gen_ekle(gecici1_2->veri_gen);
			gecici1_2=gecici1_2->sonraki_gen;
			
		} // dna1 in  arka yarısı kopyalandı
		
		
		
		for(int i=0;i<(gec2->dna->gen_sayisi)/2;i++)
		{
			dna_dondur()->gen_ekle(gecici2_2->veri_gen);
			gecici2_2=gecici2_2->sonraki_gen;
			
		} // dna2 in  ön yarısı kopyalandı
	
}//








void Kromozom_Liste::kromozom_ekranaYaz()
{
	// amacımız her satırdaki en küçük geni yazdırmak
	//dna hpp sinde bir satırdaki en küçük geni döndüren fonksiyonu yazmıştım
	// o zaman  düğümlerdeki her bir dna bağlı listesinden en küçük geni getirme fonksiyonuna ulaşıp yazdırmalıyım
	
	
	Kromozom_Dugum *gec=ilk_dna;
	
	while(gec!=nullptr)
	{
		
		cout<<gec->dna->gen_getir()<<" "; // gecici düğümle ilk dna pointerine ulaştım onun genini getirdim
		
		gec=gec->sonraki_dna; // bunu sonra bütün dna lar için yapabilmek için  en büyük düğümde ilerledim
	}
	
	
	
}//



 void  Kromozom_Liste::kromozom_mutasyon(int dna_sira, int gen_sira)
 {
	 
	 // ilk başta kaçıncı satıra gideceğimi bulmam lazım
	 // sonra o satırdaki istenen sıradaki gene gitmem lazım
	 // genin veri_genini x olarak değiştirmem lazım
	 
	 // ilk önce girilen sayıda satır var mı onu kontrol etmeliyim
	 // ve girilen sıra 0 dan küçük olmamalı
	 
	 // ve numaralandırma 0 dan başladığı göz önünde bulundurulmalı
	 
	 if(dna_sira>=dna_adet || dna_sira<0) 
	 {
		 cout<<"mevcut kromozom listesinin disina ciktiniz lutfen tekrar deneyin...."<<endl<<endl;
		return;
		 
	 }
	 

	 // eğer ilk durumda sorun yoksa şimdi de satırdaki gen sayisinin sınırları dışına çıkmamalı
	 
	 
	 Kromozom_Dugum *gec_dna=ilk_dna;
	
	 
	
	
	for(int i=0;i<dna_sira;i++)
	{
		gec_dna=gec_dna->sonraki_dna;
	}
	
	// sıraya ulaştık
	
	if(gen_sira>=gec_dna->dna->gen_sayisi || gen_sira<0) 
	 {
		 cout<<"secilen kromozom numarasinda mevcut gen sayisinin disina ciktiniz lutfen tekrar deneyin..."<<endl<<endl;
		return;
		 
	 }
	
	 Gen_Dugum *gec_gen=gec_dna->dna->ilk_gen;
	
	
	for(int i=0;i<gen_sira;i++)
	{
		gec_gen=gec_gen->sonraki_gen;
	}
	 
	 // ilgini gene geldik
	 
	 gec_gen->veri_gen='X'; 
	
	 // genin verisini X ile değiştirdik
	 
	 
 }//






void Kromozom_Liste::kromozom_oto_islem(Kromozom_Liste*liste)
{
	// amacımız dosyadan yapmamız gereken fonksiyonu anlayıp işlem yapmak
	// örneğin c 1 2 okunduğu zaman dosyadan anlamalıyız ki c demek caprazlama 1 ve 2 de 1. ve 2. satırdaki dna lar çaprazlanacak
	
	ifstream dosya("Islemler.txt");
    string satir;
	int islem_sirasi=0;

    if (!dosya.is_open()) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    while (getline(dosya, satir)) {
        istringstream ss(satir);
        char komut;
        ss >> komut;

        if (komut == 'C') {
            int x;
         	int y;
            ss >> x >> y;
           liste->kromozom_caprazlama(x,y);
        }
        else if (komut == 'M') {
            int x;
			int y;
            ss >> x >>y;
             liste->kromozom_mutasyon(x,y);
        }
        else {
            cerr << "Bilinmeyen komut: " << komut << endl;
        }
    }

    dosya.close();
	
	
}//








