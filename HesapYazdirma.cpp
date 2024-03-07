#include <iostream>
#include <fstream>

using namespace std;

void restaurantMenu(){
	cout << "---------- RESTAURANT MENU ----------\n" << endl;
	
	cout << "YEMEKLER           ICECEKLER           TATLILAR" << endl;
	cout << "---------          ----------          ---------" << endl;
	cout << "1-Manti   100TL    5-Su      5TL       9-Tulumba       30 TL" << endl;
	cout << "2-Kofte   150TL    6-Ayran   10TL      10-Kunefe       50 TL" << endl;
	cout << "3-Pilav   60TL     7-Fanta   12TL      11-Profiterol   30 TL" << endl;
	cout << "4-Doner   90TL     8-Kola    12TL      12-Pasta        40 TL" << endl;
}

int main() {
	ofstream hesap("fatura.txt");
	restaurantMenu();
	
	string urunler[] = {"Manti", "Kofte", "Pilav", "Doner", "Su", "Ayran", "Fanta", "Kola", "Tulumba", "Kunefe", "Profiterol", "Tulumba"};
	int fiyatlar[] = {100, 150, 60, 90, 5, 10, 12, 12, 30, 50, 30, 40};
	
	int toplamFiyat;
	
	while(true)
	{
		int secim;
		cout << "\n1 - Urun Secin\n2 - Sistemden Cikin\nSecimim : ";
		cin >> secim;
		
		
		while(secim < 1 || secim > 2)
		{
			cout << "Lutfen 1 veya 2 degerini seciniz: ";
			cin >> secim;
		}
		if(secim == 1)
		{
			int urunNo;
			cout << "Urun numarasini giriniz : ";
			cin >> urunNo;
			
			while(urunNo < 1 || urunNo > 12)
			{
				cout << "Urun bulunamadi. Lutfen belirtlilen araliklarda urun giriniz : ";
				cin >> urunNo;
			}
			
			hesap << urunler[urunNo - 1] << " : " << fiyatlar[urunNo - 1] << "TL" << endl;
			toplamFiyat += fiyatlar[urunNo - 1];
		}
		else
		{
			cout << "\nFATURANIZ OLUSTURULDU! AFIYET OLSUN!\nToplam Tutar: " << toplamFiyat << " TL" << endl;
			hesap << "\nToplam Tutar: " << toplamFiyat << " TL" << endl;
			break;
		}
	}
}
