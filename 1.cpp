/*
Nama Program	: Soal 1 UTS
Nama			: Rahma Batari
NPM				: 140810180051
Tanggal Buat	: 23 April 2019
Deskripsi		: Single Linked List
*/

#include <iostream>
#include <conio.h>
using namespace std;


struct ElemtList{
	char no[3];
	char nama[20];
	char asal[20];
	int gol;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer list;

void banyakData(int& n){
	cout<<"Banyak data : "; cin>>n;
}

void createList(list& first){
	first = NULL;
}

void createElmt(pointer& pBaru){
	pBaru = new ElemtList;		
	cout<<"Masukkan No : "; cin>>pBaru->no;
	cout<<"Masukkan Nama Tim : "; cin.ignore(); cin.getline(pBaru->nama, 18);
	cout<<"Masukkan Asal Daerah Tim : "; cin.ignore(); cin.getline(pBaru->nama, 18);
	cout<<"Masukkan Gol : "; cin>>pBaru->gol;
	pBaru->next = NULL;
}

void insertFirst(list& first, pointer pBaru){

	
	if(first==NULL)		
		first = pBaru;
	
	else{		
		pBaru->next = first;
		first = pBaru;
	}
}

void traversal(list first){
	pointer pBantu;
	if (first==NULL) {
		cout<<"List kosong"<<endl;
	}
	else {
		pBantu = first;		
		do {
			cout<<"No : "<<pBantu->no<<endl;
			cout<<"Nama Tim : "<<pBantu->nama<<endl;
			cout<<"Asal Tim : "<<pBantu->asal<<endl;
			cout<<"Gol : "<<pBantu->gol<<endl; 
			pBantu = pBantu->next;	
		} while(pBantu != NULL);
	}
}

int main(){
	int n, pilih;
	char jawab;
	pointer p;
	list listTim;
	
	createList(listTim);		
	do{
		system("cls");
		cout<<"============================================\n";
		cout<<"\t\tProgram\n";
		cout<<"============================================\n";
		cout<<"1.\tInput dengan Insert First\n";
		cout<<"2.\tShow data dengan Traversal\n\n";
		
		cout<<"Pilihan (1-2) : "; cin>>pilih;
		switch(pilih){
			case 1:
				system("cls");
				cout<<"Insert First\n";
				cout<<"============================================\n";
				banyakData(n);
				for(int i=0; i<n; i++){
					createElmt(p);
					insertFirst(listTim, p);
					cout<<endl;
				}
				traversal(listTim);
				break;
				
			case 2:
				system("cls");
				cout<<"============================================\n";
				cout<<"\t\tCetak Data\n";
				cout<<"============================================\n";
				traversal(listTim);
				break;
				
			default:
				cout<<"Pilihan tidak tersedia";
				getch();
				system("cls");
				break;
		};
		cout<<"Kembali ke menu utama? (Y/N)"; cin>>jawab;
	} while(jawab == 'y' || jawab == 'Y');
	cout<<"Selesai";
	
}
