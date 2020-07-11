/*
Autor: Damian Raczkowski
numer indeksu: 252695
Temat: Lista numer 6 
Grupa: Czw 9:15-11:00 TP
Data: 23.01.2020r.

*/
#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

struct Towar//a
{
	char Nazwa[20];
	float cena;
	int ilosc;
};
void create_tab();//b
void Show_Tab();//c
void Get_bigger();//d
void clean_your_mess();//g
void Erase_onebase();
Towar *Tab= NULL;
int Rozmiar =0;


int main()
{ 
	bool work=true;
	int N;
	
	
	while(work)
	{
	printf("-------Menu-------\n[1]Stworz tablice struktur\n[2]Pokaz tablice struktur\n[3]Powieksz tablice struktur\n[4]Usun jedno pole z tablicy\n[5]Wyczysc tablice\n[0]Wylacz\n");
	cout<<" Ktora funkcje chcesz wywolac?";
	cin>> N;
	printf("Rozmiar tablicy %d\n", Rozmiar);
	printf("Aktualny adres tablicy dynamicznej %d\n", Tab);
	switch(N)
		{
		case 1:
			create_tab();
			system("cls");
			break;
		case 2:
			Show_Tab();
			break;
		case 3:
			Get_bigger();
			system("cls");
			break;
		case 4:
			Erase_onebase();
			system("cls");
			break;
		case 5:
			clean_your_mess();
			system("pause");
			system("cls");
			break;
		default:
			work=false;
			break;
		}
	}

		
	
	
	return 0;
}
void create_tab() // tworzenie tablicy dynamicznej i
// uzupelnianie przez uzytkownika
{

	if(Tab!=NULL)
	{
		delete Tab;
	}
	printf("Podaj rozmiar bazy danych\n");
	scanf("%d", &Rozmiar);
	
	Tab=  (Towar*)calloc(Rozmiar, sizeof (Towar));
	for(int i=0; i<Rozmiar; i++)
	{
		cout<<"Nazwa produktu"<< endl;
		cin>> (Tab+i)->Nazwa;
		cout<<"Cena produktu"<<endl;
		cin>> (Tab+i)->cena;
		cout<<"Jego ilosc" << endl;
		cin>> (Tab+i)->ilosc;
	}
}
void Show_Tab() // wydruk tablicy
{

	if(Tab==NULL) printf("Brak tablicy do wyswietlenia");
	else
	{
	printf("| LP |  Nazwa  |   Cena   |  Ilosc  |\n");
	for(int i=0; i<Rozmiar; i++)
		printf("| %2d |%8s | %8.2f | %7d |\n", i+1, (Tab+i)->Nazwa, (Tab+i)->cena, (Tab+i)->ilosc );
	}
}
void Get_bigger()//powiekszanie struktury
{

	int addition;
	
	printf("Napisz ile chcesz dodatkowych towarow wpisac\n");
	scanf("%d", &addition);
	Rozmiar+=addition;
	realloc(Tab, (Rozmiar)*sizeof(Towar) );
	
	for (int i=Rozmiar-addition; i<Rozmiar; i++)
	{
		cout<<"Nazwa produktu"<< endl;
		cin>> (Tab+i)->Nazwa;
		cout<<"Cena produktu"<<endl;
		cin>> (Tab+i)->cena;
		cout<<"Jego ilosc" << endl;
		cin>> (Tab+i)->ilosc;
	}

}
void clean_your_mess()
{
	if(Tab!=NULL)
	{
	free(Tab); 
	Rozmiar=0;
	Tab=NULL;
	cout<<"Tablica zostala wyczyszczona"<<endl;
	}
	else printf("Tablica nie zostala utworzona\n");

}
void Erase_onebase()
{
	if(Tab!=NULL)
	{
		int erase_number=0;
		cout<<"Napisz numer towaru, ktory  chcesz usunac ";
		cin>> erase_number;
		erase_number--;
		if(erase_number<0 || erase_number>=Rozmiar)
		{
			cout<< "Zle podany numer Towaru"<<endl;
		}
		else
		{
			Towar *pomTab=NULL;
			pomTab= (Towar*)calloc(Rozmiar-1, sizeof (Towar));;
			int j=0;
			for(int i=0; i<Rozmiar; i++)
			{
				if(i!=erase_number)
				{
					*(pomTab+j)=*(Tab+i);
				j++;
				}
			}
			free(Tab);
			Tab=NULL;
			Tab=pomTab;
			Rozmiar=Rozmiar - 1;
			realloc(Tab, (Rozmiar)*sizeof(Towar) );
			
		}
	}
	else
	{
		cout<<" Tablica nie zosta³a stworzona" <<endl;
	}
		system("PAUSE");
}