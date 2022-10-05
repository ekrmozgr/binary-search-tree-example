#ifndef AgacIslem_HPP
#define AgacIslem_HPP
#include "Node.hpp"
class AgacIslem
{
public:
	AgacIslem();
	~AgacIslem();
	void benim_agac_olustur(Node*&);
	void rakip_agac_olustur(Node*&);
	void dugumEkle(int,Node*&);
	bool benimtxtKontrol();
	bool rakiptxtKontrol();
	void Postorder_soysayilari(Node*);
	void islemler();
	void skorYaz();
	void AraveSil(Node*&,int);
	void DugumSil(Node*&,Node*&);
	int enBuyuk(Node*);
	void Temizle();
	void Postorder_temizle(Node*);
private:
	int tur_sayisi;
	int sayac;
	int temp_toplam_soy;
	int benim_toplam_soy;
	int rakip_toplam_soy;
	int benim_skor;
	int rakip_skor;
	Node *root_benim;
	Node *root_rakip;
	Node *ust_dugum;
	int benim_txt_eleman;
	int rakip_txt_eleman;
};
#endif

