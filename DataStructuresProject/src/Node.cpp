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

#include "Node.hpp"

//dugum olusturdum. ilk parametrede girilen datayi, ikinci parametrede dugumun gosterdigi sonraki adresi, ucuncu parametrede de 
//dugumun kendinden once gosterdigi adresi aliyoruz. 
Node::Node(const string data,Node* nx=NULL,Node* pr=NULL){
	this->data=data;
	next=nx;
	prev=pr;
}