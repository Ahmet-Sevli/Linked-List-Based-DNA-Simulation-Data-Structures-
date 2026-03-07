#ifndef Kromozom_Dugum_hpp
#define Kromozom_Dugum_hpp
#include <iostream>
#include "DNA_Liste.hpp"
using namespace std;


class Kromozom_Dugum
{
	
	public:
	Kromozom_Dugum();
	
	
	
	
	
	Kromozom_Dugum *sonraki_dna;
	
   DNA_Liste *dna; // kromozom bağlı listesinin her düğümünün verisinde aslında bir iki yönlü bağlı listeyi tutan bir pointer olacak
	
	
	
};





#endif