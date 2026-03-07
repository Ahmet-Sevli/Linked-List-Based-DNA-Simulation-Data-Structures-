/**
* @file main
* @description 

 dosyadan okuduğu her satırda,
 satırlardaki her harfi bir iki yönlü bağlı listeye atan,
 bu oluşan listelerin işaretçisini de bir tek yönlü bağlı listede tutan
 ve bu bağlı listelerde işlemler yapan bir otomasyon

* @course 2.öğretim B grubu
* @assignment veri yapıları 1. ödev
* @date 10.11.2024
* @author Ahmet Sevli      ahmet.sevli@ogr.sakarya.edu.tr
*/



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Kromozom_Liste.hpp"

using namespace std;


void DosyaOku(Kromozom_Liste* hucre){
    ifstream file("Dna.txt");

    if (!file.is_open()) {
        cout << "Dosya açma başarısız." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
       hucre->dna_olustur();
        istringstream ss(line);
        char ch;
        while (ss >> ch) {
            hucre->dna_dondur()->gen_ekle(ch);
			
        }
                   
    }

    file.close();
}

int main()
{
    Kromozom_Liste* hucre = new Kromozom_Liste();
    DosyaOku(hucre);
  
   cout<<endl;
   
   //hucre->kromozom_yazdir();
   
   cout<<endl;
   
   int secim;
   
   
   
    do {
        // Kullanıcıya seçenekler sunuluyor
        cout << "1 - Caprazlama" << endl;
        cout << "2 - Mutasyon" << endl;
        cout << "3 - Otomatik Islemler" << endl;
        cout << "4 - Ekrana Yaz" << endl;
        cout << "5 - Cikis" << endl;
        cout << "Bir secenek girin (1-5): ";
        cin >> secim;
         
		 system("cls"); 
		 
        // switch-case yapısı ile işlemler yapılır
        switch (secim) {
            case 1:
			
			//hucre->kromozom_yazdir();
			
			int dna1;
			int dna2;
			cout<<endl;
			cout<<"Caprazlanacak olan iki kromozomu secin "<<endl;
			cout<<"ilk kromozom: "; cin>>dna1;
			cout<<endl;
			cout<<"ikinci kromozom: "; cin>>dna2;
			cout<<endl<<endl;
			
            hucre->kromozom_caprazlama(dna1,dna2);
			//cout<<"ISLEM SONUCU:"<<endl;
		    //hucre->kromozom_yazdir();
			
			cout<<endl<<endl;
				
                break;
				
				
            case 2:
			
			//hucre->kromozom_yazdir();
			int dna_sira;
			int gen_sira;
			cout<<endl;
			cout<<"Mutasyona ugrayacak olan kromozom sirasini secin "<<endl;
			cout<<"kromozom: "; cin>>dna_sira;
			cout<<endl;
			cout<<"Mutasyona ugrayacak olan gen sirasini secin "<<endl;
			cout<<"gen: "; cin>>gen_sira;
			cout<<endl<<endl;
			
			
            hucre->kromozom_mutasyon(dna_sira,gen_sira);
			//cout<<"ISLEM SONUCU:"<<endl;
		   // hucre->kromozom_yazdir();
		  
			cout<<endl<<endl;
				
                break;
				
				
            case 3:
			
			cout<<"Dosyadan otomatik islemler okunuyor...."<<endl;
            hucre->kromozom_oto_islem(hucre);
		    //hucre->kromozom_yazdir();
			cout<<" Islem tamamlandi...."<<endl;
			cout<<endl<<endl;
			
                break;
				
				
            case 4:
			
			//hucre->kromozom_yazdir();
			cout<<endl;
			cout<<"Ekrana yaz fonksiyonu calisiyor...."<<endl;
            hucre->kromozom_ekranaYaz(); 
			cout<<endl;
			cout<<"Islem tamamlandi...."<<endl;
			cout<<endl<<endl;
			
                break;
				
				
            case 5:
			
            cout << "Cikiliyor..." << endl;
			
                break;
				
				
            default:
			
            cout << "Gecersiz secenek! Lutfen 1 ile 5 arasinda bir secenek girin." << endl;
		    cout<<endl<<endl;
        }

    } while (secim != 5); // Çıkış seçeneği seçilene kadar döngü devam eder

  

       delete hucre; // tüm listeler silinecek (kendi içerisinde ilk önce bir satırın içi sonra o satırın işaretçisi çünkü new ile almıştık .bunu bütün satırlar için yaptıktan sonra da kendisi)
   
   
 
   
     return 0;
}