#include "AgacIslem.hpp"
#include "Node.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include  <conio.h>
using namespace std;
AgacIslem::AgacIslem()
{
	root_benim = NULL;
	root_rakip = NULL;
	sayac = 0;
	temp_toplam_soy = 0;
	rakip_skor = 0;
	benim_skor = 0;
	tur_sayisi = 0;
	benim_txt_eleman = 0;
	rakip_txt_eleman = 0;
}
bool AgacIslem::benimtxtKontrol()
{
	ifstream benim;
	benim.open("benim.txt");
	string gecici;
	while (benim >> gecici)
	{
		benim_txt_eleman++;
	}
	if (gecici != "")
	{
		benim.close();
		return true;
	}
	else
	{
		benim.close();
		return false;
	}
}
bool AgacIslem::rakiptxtKontrol()
{
	ifstream rakip;
	rakip.open("rakip.txt");
	string gecici;
	while(rakip >> gecici)
	{
		rakip_txt_eleman++;
	}
	if (gecici != "")
	{
		rakip.close();
		return true;
	}
	else
	{
		rakip.close();
		return false;
	}
}
void AgacIslem::benim_agac_olustur(Node*&_benim)
{
	ifstream benim;
	benim.open("benim.txt");
	string gecici;
	while (benim >> gecici)
	{
		dugumEkle(atoi(gecici.c_str()),_benim);
	}
	benim.close();
}
void AgacIslem::rakip_agac_olustur(Node*&_rakip)
{
	ifstream rakip;
	rakip.open("rakip.txt");
	string gecici;
	while (rakip >> gecici)
	{
		dugumEkle(atoi(gecici.c_str()), _rakip);
	}
	rakip.close();
}
void AgacIslem::dugumEkle(int veri,Node*&root)
{
	if (root == NULL)
	{
		root = new Node(veri);
	}
	else
	{
		if (veri < root->getVeri())
		{
		dugumEkle(veri, root->getSol());
		}
		else if (veri > root->getVeri())
		{
		dugumEkle(veri, root->getSag());
		}
		else
		{
		dugumEkle(veri, root->getSol());
		}
	}
}
void AgacIslem::Postorder_soysayilari(Node*dugum){
	if (dugum != NULL) {
		Postorder_soysayilari(dugum->getSol());
		Postorder_soysayilari(dugum->getSag());

		if (dugum->getSag() == NULL && dugum->getSol() == NULL)
		{
			sayac = 0;
			dugum->setSoy_sayisi(sayac);
		}
		else if (dugum->getSag() != NULL && dugum->getSol() != NULL)
		{
			sayac = 2;
			dugum->setSoy_sayisi(dugum->getSag()->getSoy_sayisi() + dugum->getSol()->getSoy_sayisi() + sayac);
		}
		else
		{
			sayac = 1;
			if (dugum->getSag() == NULL)
			{
				dugum->setSoy_sayisi(dugum->getSol()->getSoy_sayisi() + sayac);
			}
			else
			{
				dugum->setSoy_sayisi(dugum->getSag()->getSoy_sayisi() + sayac);
			}
		}
		cout << "<"<<dugum->getVeri()<<"," << dugum->getSoy_sayisi() << ">" << " ";
		if (dugum->getSoy_sayisi() != 0) {
			temp_toplam_soy += dugum->getSoy_sayisi();
		}
	}
}
void AgacIslem::skorYaz()
{
	if (benim_toplam_soy < rakip_toplam_soy)
	{
		benim_skor++;
		cout << "-- TEBRIKLER TURU KAZANDINIZ --" << endl << endl;
		cout << "SKOR" << endl << "Benim : " << benim_skor << endl << "Rakip : " << rakip_skor << endl << endl;
	}
	else if (benim_toplam_soy > rakip_toplam_soy)
	{
		rakip_skor++;
		cout << "-- TURU RAKIP KAZANDI --" << endl << endl;
		cout << "SKOR" << endl << "Benim : " << benim_skor << endl << "Rakip : " << rakip_skor << endl << endl;
	}
	else
	{
		cout << "-- SOY SAYILARI ESIT --" << endl << endl;
		cout << "SKOR" << endl << "Benim : " << benim_skor << endl << "Rakip : " << rakip_skor << endl << endl;
	}
}
void AgacIslem::AraveSil(Node*&root,int veri)
{
			if (root->getVeri() == veri)
			{
				if (root->getSol() != NULL)
				{
					if (root->getSol()->getVeri() == veri)
					{
						DugumSil(root->getSol(),ust_dugum);
					}
					else
					{
						DugumSil(root,ust_dugum);
					}
				}
				else
				{
					DugumSil(root,ust_dugum);
				}
			}
			else if (veri < root->getVeri())
			{
				ust_dugum = root;
				AraveSil(root->getSol(), veri);
			}
			else {
				ust_dugum = root;
				AraveSil(root->getSag(), veri);
			}
}
void AgacIslem::DugumSil(Node*&dugum,Node*&ust_dugum)
{
		Node *silinecekDugum = dugum;
		if (dugum->getSag() == NULL && dugum->getSol() != NULL)
		{
			dugum = dugum->getSol();
			delete silinecekDugum;
		}
		else if (dugum->getSol() == NULL && dugum->getSag() != NULL)
		{
			dugum = dugum->getSag();
			delete silinecekDugum;
		}
		else if (dugum->getSag() == NULL && dugum->getSol() == NULL)
		{
			if (ust_dugum->getSag()->getVeri() == silinecekDugum->getVeri())
			{
				ust_dugum->setSag(NULL);
				delete silinecekDugum;
			}
			else
			{
				ust_dugum->setSol(NULL);
				delete silinecekDugum;
			}
		}
		else 
		{
			silinecekDugum = dugum->getSol();
			Node*ebeveynDugum = dugum;
			while (silinecekDugum->getSag() != NULL) {
				ebeveynDugum = silinecekDugum;
				silinecekDugum = silinecekDugum->getSag();
			}
			dugum->setVeri(silinecekDugum->getVeri());
			if (ebeveynDugum == dugum)
			{
				dugum->getSol() = silinecekDugum->getSol();
			}
			else
			{
				ebeveynDugum->getSag() = silinecekDugum->getSol();
			}
			delete silinecekDugum;
		}
}
int AgacIslem::enBuyuk(Node*root)
{
	Node*temp;
	temp = root;
	int enBuyukdeger;
	while (temp->getSag() != NULL)
	{
		temp = temp->getSag();
	}
	enBuyukdeger = temp->getVeri();
	return enBuyukdeger;
}
void AgacIslem::Postorder_temizle(Node*root)
{
	if (root != NULL) {
		Postorder_temizle(root->getSol());
		Postorder_temizle(root->getSag());
		delete root;
	}
}
void AgacIslem::Temizle()
{
	Postorder_temizle(root_benim);
	Postorder_temizle(root_rakip);
}
void AgacIslem::islemler()
{
	if (benimtxtKontrol() == true && rakiptxtKontrol() == true)
	{
		if (benim_txt_eleman == rakip_txt_eleman)
		{
			benim_agac_olustur(root_benim);
			rakip_agac_olustur(root_rakip);
			while (benim_skor != 5 && rakip_skor != 5 && tur_sayisi != 20)
			{
				cout << "--- " << tur_sayisi + 1 << ". TUR ---" << endl << endl;
				cout << "Benim Agac Postorder :" << endl;
				Postorder_soysayilari(root_benim);
				benim_toplam_soy = temp_toplam_soy;
				cout << endl << "Benim Agac Toplam Soy Sayisi : " << benim_toplam_soy << endl << "--------------" << endl << endl << endl;
				temp_toplam_soy = 0;
				cout << "Rakip Agac Postorder :" << endl;
				Postorder_soysayilari(root_rakip);
				rakip_toplam_soy = temp_toplam_soy;
				cout << endl << "Rakip Agac Toplam Soy Sayisi : " << rakip_toplam_soy << endl << "--------------" << endl << endl;
				temp_toplam_soy = 0;
				skorYaz();
				tur_sayisi++;
				_getch();
				if (tur_sayisi != 20)
				{
					if (benim_toplam_soy < rakip_toplam_soy)
					{
						dugumEkle(enBuyuk(root_rakip), root_benim);
						AraveSil(root_rakip, enBuyuk(root_rakip));
						dugumEkle(root_benim->getVeri(), root_rakip);
						AraveSil(root_benim, root_benim->getVeri());
					}
					else if (benim_toplam_soy > rakip_toplam_soy)
					{
						dugumEkle(enBuyuk(root_benim), root_rakip);
						AraveSil(root_benim, enBuyuk(root_benim));
						dugumEkle(root_rakip->getVeri(), root_benim);
						AraveSil(root_rakip, root_rakip->getVeri());
					}
					else
					{
						dugumEkle(root_rakip->getVeri(), root_benim);
						dugumEkle(root_benim->getVeri(), root_rakip);
						AraveSil(root_benim, root_benim->getVeri());
						AraveSil(root_rakip, root_rakip->getVeri());
					}
				}
				benim_toplam_soy = 0;
				rakip_toplam_soy = 0;
			}

			if (benim_skor == 5)
			{
				cout << endl << "******* TEBRIKLER OYUNU KAZANDINIZ *******" << endl << endl;
			}
			else if (rakip_skor == 5)
			{
				cout << endl << "******* RAKIP OYUNU KAZANDI *******" << endl << endl;
			}
			else
			{
				cout << endl << "----- 20 TUR GECTI -----" << endl;
				if (benim_skor > rakip_skor)
				{
					cout << "******* TEBRIKLER OYUNU KAZANDINIZ *******" << endl << endl;
				}
				else if (rakip_skor > benim_skor)
				{
					cout << "******* RAKIP OYUNU KAZANDI *******" << endl << endl;
				}
				else
				{
					cout << "******* OYUN BERABERE *******" << endl << endl;
				}
			}		
		}
		else
		{
			cout << "txt dosyalarindaki eleman sayilari farkli ! " << endl;
		}
	}
	else if (benimtxtKontrol() == true && rakiptxtKontrol() == false)
	{
		cout << "rakip.txt dosyasi bos ! " << endl;
	}
	else if (benimtxtKontrol() == false && rakiptxtKontrol() == true)
	{
		cout << "benim.txt dosyasi bos ! " << endl;
	}
	else
		cout << "Iki txt dosyasi da bos ! " << endl;
}

AgacIslem::~AgacIslem()
{
	Temizle();
}
