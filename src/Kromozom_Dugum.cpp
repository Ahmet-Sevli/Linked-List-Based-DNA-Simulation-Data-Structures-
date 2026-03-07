/**
* @file Kromozom_Dugum.cpp
* @description 

 her bir satırı tutan düğüm kodu

* @course 2.öğretim B grubu
* @assignment veri yapıları 1. ödev
* @date 10.11.2024
* @author Ahmet Sevli      ahmet.sevli@ogr.sakarya.edu.tr
*/


#include "Kromozom_Dugum.hpp"
#include "DNA_Liste.hpp"
Kromozom_Dugum::Kromozom_Dugum()
{
	
	
	this->dna=new DNA_Liste();
	
    sonraki_dna=nullptr;
}