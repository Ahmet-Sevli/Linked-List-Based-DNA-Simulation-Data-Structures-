/**
* @file Kromozom_Dugum.cpp
* @description 

 her bir satırın içindeki harfleri tutan düğüm kodu

* @course 2.öğretim B grubu
* @assignment veri yapıları 1. ödev
* @date 10.11.2024
* @author Ahmet Sevli      ahmet.sevli@ogr.sakarya.edu.tr
*/


#include "Gen_Dugum.hpp"

Gen_Dugum::Gen_Dugum(char veri_gen)
{
	
	this->veri_gen=veri_gen;
	
	onceki_gen=sonraki_gen=nullptr;
}