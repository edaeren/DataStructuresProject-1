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

#ifndef LIST_HPP
#define LIST_HPP
#include <string>
#include "Node.hpp"

class List{
	private:
		Node *head;
		int size;
		Node* FindLastNode();
		Node* FindPresentNode(int);
	
	public:
		List();
		bool isEmpty()const;	
		void add(int,const string&);
		void remove(int);		
		friend ostream& operator<<(ostream&,List&);
		void clear();	
		~List();
};

#endif