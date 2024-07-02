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

#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

#include <string>
#include <fstream>
using namespace std;

class Node{
	public:
		string data;
		Node *next;
		Node *prev;
		Node(const string,Node*,Node*);
};
#endif