/** 
* G201210085
* 	Programim okutulan dosyadaki verilerdeki islem ekleme ise, sonda bir dugum olusturup girilen indexe kadar
* geri geri giderken uzerindeki dugumun datasini bir sagindakine kopyalamami ve son gelinen dugume girilen datayi girmemi; islem
* silme ise de belirtilen indexi bulup dugumler uzerinde ileri dogru giderken, dugum uzerindeki datayi bir oncekine kopyalamami
* ve en sonda da sonda kalan dugumu silmemi saglar.
*  2A
*  ODEV 1
*  10.11.2021
*  Eda Eren eda.eren@ogr.sakarya.edu.tr
*/


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "List.hpp"
using namespace std;
int main(){
	List *isimler=new List();
	string girilenVeri;
	char command;
	int index;
	string girilenIsim;
	size_t position; //isaretlerin yerini tutacak degisken
	string temporary;
	ifstream dosyaOku(".\\doc\\veri.txt",ios::in);	
	 
	 //dosya acilamadiysa "dosya acilamadi" cumlesini ekrana yazdirttim ki sorun oldugu anlasilsin
	if(!dosyaOku.is_open()){
		cout<<"File failed to open"<<endl;
		return 0;
	}

	//dosya basariyla acildiysa getline ile dosya nesnesini ve dosyadaki verileri aldim
	while(getline(dosyaOku,girilenVeri)){
		//txt dosyasindaki ilk harf degerini command isimli degiskene atadim.
		command=girilenVeri[0];
		//ilk harf e ise ekleme yapilacak. 
		if(command=='E'){
			int lengthOfVeri=girilenVeri.length();		
			position=girilenVeri.find("#");
			temporary=girilenVeri.substr(2,position-2);
			index=stoi(temporary);
			girilenIsim=girilenVeri.substr(position+1,lengthOfVeri-position-2);
			isimler->add(index,girilenIsim);
		}
		//ilk harf s ise silme yapilacak.
		else //(command=='S')
		{
			position=girilenVeri.find(")");
			temporary=girilenVeri.substr(2,position-2);
			index=stoi(temporary);
			isimler->remove(index);
		}
	}
	cout<< *isimler;
	delete isimler;
	dosyaOku.close();
}