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
#include "List.hpp"

//listenin basindan sonuna kadar giderek son dugumu bulan bir fonksiyon yazdim
Node* List::FindLastNode(){
	Node *prev=head;
	int i=1;
	//itr ve prev pointerlarini head'e esitledim
	//itr head'e esit oldugundan listenin basindan baslayarak, itr'nin nexti null olmadigi
	//surece donguye girecek ve prev'i bir sonraki dugume ilerletecek boylece son dugumu bulacagiz.
	for(Node *itr=head;itr->next!=NULL;itr=itr->next,i++){
		prev=prev->next;
	}
	return prev;  //en sonda da buldugumuz dugumu tutan pointeri dondururuz.
}
	
//girilen indexteki dugumun adresini donduren bir fonksiyon yazdim.	
Node* List::FindPresentNode(int index){
	Node *presentNODE=head;
	int i=0;
	//presentNODE ve itr isimleri pointerlari head'e esitledigimden, i degeri index'e esit olmadigi surece
	//presentNODE'u bir sonraki dugume ilerlettim.
	for(Node *itr=head;i!=index;itr->next,i++){
		presentNODE=presentNODE->next;
	}
	return presentNODE; //en son da buldugumuz degeri dondurdum.
}

List::List(){
	head=NULL;
	size=0;
}

bool List::isEmpty()const{
	return size==0;
}
	
void List::add(int index,const string& item){

	//ilk kez veri ekleniyorsa
	//ilk kez veri ekleniyorsa head null'a esit olacagindan if bloguna girer ve burada da yeni bir dugum
	//olusup listenin size'i bir arttirilir.
	if(head==NULL){
		head=new Node(item,head,NULL);
		size++;
	}
	//zaten bir dugum varsa else icine girer
	else{
		Node *sonuncu=FindLastNode();
		//sona dugum ekleniyorsa, bulunmayan bir index giriliyorsa veya girilen index eksili bir degerse bu bloga
		//girecek ve sonuncuBir isimli pointer'a son dugumun gosterdigi yer aktarilacak. Daha sonra son dugumu gosteren yerin
		//nextine de yeni bir dugum eklenecek ve size bir arttirilacak.
		if(index==size||index>size||index<0){
			Node *sonuncuBir=sonuncu;
			sonuncuBir->next=new Node(item,sonuncuBir->next,sonuncuBir);
			size++;
		}
		//daha onceden en az bir dugum varsa ve sona degil de araya veya basa vs eklenecekse bu else bloguna girer 
		//yine son dugumun adresi sonuncuİki pointerina atanir ve onun nextine yeni olusturulan dugumun adresi atanir.size bir arttirilir
		//son dugumun icindeki veri degeri, sondan bir sonraki dugumun icindeki veriye aktarilir.
		else{
			Node *sonuncuIki=sonuncu;
			sonuncuIki->next=new Node(item,sonuncuIki->next,sonuncuIki);
			size++;
			int i=size-2;
			sonuncuIki->next->data=sonuncuIki->data;
			//itr findLastNode fonksiyonu ile bulunan son dugumu gosterir,ve i degeri girilen indexe esit olmadigi surece for dongusune 
			//girerek o dugumun bir oncesindeki datayi, o dugumun icindeki dataya kopyalayarak dugumler uzerinde geri geri gider.
			for(Node *itr=sonuncuIki;i!=index;itr=itr->prev,i--){	
				sonuncuIki->data=sonuncuIki->prev->data;
				sonuncuIki=sonuncuIki->prev;
			}
			sonuncuIki->data=item;  //en sonda gelinen dugumun datasina da dosyada girilen item'i aktarir.
		}
	}
}
		
void List::remove(int index){

	//verilen index yoksa veya index eksili degerse listenin sonundan eleman silecek
	if(index>size||index==size||index<0){
		//listedeki geriye kalan son dugum siliniyorsa head'in nexti null olacagindan bu bloga girer
		if(head->next==NULL){
			Node *silinecek;
			silinecek=head;
			head=head->next; //head=NULL
			delete silinecek;
			size--;			
		}else{ //listedeki silinen dugum geriye kalan son dugum degilse, son dugumu bulur ve onun gosterdigi dugumu,bir onceki dugumun
		//gostermesini saglayip o dugumu sileriz ve size'i bir eksiltiriz.
			Node *sondanSilDugum=FindLastNode();
			sondanSilDugum->prev->next=sondanSilDugum->next;
			delete sondanSilDugum;
			size--;
		}
	}//verilen index varsa ve uygunsa
	else{
		//listedeki geriye kalan son dugum siliniyorsa bu bloga girer
		if(head->next==NULL){
			Node *silinecek;
			silinecek=head;
			head=head->next; //head=NULL oldu
			delete silinecek;
			size--;			
		}
		//verilen index varsa ve geriye kalan son dugum degilse bu bloga girer
		else{
			Node *present=FindPresentNode(index);
			Node *presentN=present;
			int i=0;
			//verilen indexteki node'u FindPresentNode fonksiyonu ile bulup degeri present isimli pointera atayip onu da presentN isimli
			//pointera atadiktan sonra itryi de onlara esitledim ve itr'nin next'i null olana kadar 
			//present'i dugumde bir ilerlettim ve ardindan present'in datasini bir onceki dugumun datasina atadim. boylece bilgiyi sola kopyalarken
			//dugumde saga dogru ilerledim.
			for(Node *itr=presentN;itr->next!=NULL;itr=itr->next,i++){
				present=present->next;
				present->prev->data=present->data;			
			}
			 //itr'nin next'i null oldugunda son dugume gelmis oluyoruz. Burda da son dugumun next'ini yani null'i ondan bir onceki dugumun
			 //next'ine atayarak onu da son dugum haline getirdim ve present isimli pointerin tuttuğu adresi iade ettim ve size'i bir azalttim.
			present->prev->next=present->next; 
			delete present;
			size--;		
		}
	}					
}
	
	//ekrana yazma 
ostream& operator<<(ostream& screen,List& right){
	//itrnin gosterdigi adres null degilse 
	for(Node *itr=right.head;itr!=NULL;itr=itr->next){
		//son dugumse ekrana o dugumun datasini yaz ve sembolu yazma
		if(itr->next==NULL){
			screen<<itr->data;
		}else{ //son dugum degilse ekrana datayi yazdiktan sonra sembolu de yaz.
			screen<<itr->data<<" <-> ";
		}
	}
	screen<<endl;
	return screen;
}
		
void List::clear(){
	//liste bos olmayana kadar dugumleri remove fonksiyonunu kullanarak en bastan sil. Liste hala kullanilabilir
	while(!isEmpty())
	remove(0);
}
	
//listeyi tamamen yikmak icin clear fonksiyonunu cagirir ve listenin hayatina son verir.
List::~List(){
	clear();
}