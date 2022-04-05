///BAI TAP CUOI KI MON CTDL&GT//
//DE TAI: TRUNG TAM TIENG ANH//
//NAME: NGUYEN QUANG CHINH//
//ID: N19DCAT011
#pragma once
#include "struct.h";
#include"chuc_nang_phu.h"
#include"doc_ghi_file.h"
//=========them cap lop===========
int ktr_trung_cl(string a, DS_CAP_LOP ds_cl);
string tao_ma_cap_lop(DS_CAP_LOP ds_cl);
void them_cap_lop(DS_CAP_LOP& ds_cl);
//=======xuat danh sach cap lop============
void xuat_ds_cap_lop(DS_CAP_LOP ds_cl);
//=======xoa cap lop==============
void xoa_cl(DS_CAP_LOP& ds_cl);
//============Hieu chinh cap lop========
void hieu_chinh_cl(DS_CAP_LOP& ds_cl);
//======Danh sach lop============
LOP* khoi_tao_node_lop();
LOP* tao_node_lop();
void them_1_node(LOP*& pHead, LOP* p);
void tao_ds_lop(DS_LOP& ds_lop);
void them_lop(DS_LOP& ds_lop);
//==============xuat danh sach lop===========
void xuat_ds_lop(DS_LOP ds_lop);
//======xoa lop=====
void xoa_lop(DS_LOP &ds_l);
//===================== menu===========
void menu(){
	//==========khai bao bien=============
	DS_CAP_LOP ds_cl;
	DS_LOP ds_l;
	ds_l.pHead = khoi_tao_node_lop();//khoi tao 
	bool ktr = true;
	//==========doc file ds cap lop =========
	doc_file_ds_cl(ds_cl);
	//==========xu ly menu=============
	while (ktr==true) {
		system("cls");
		cout << "1. Them cap lop." << endl;
		cout << "2. Xuat danh sach cap lop"<<endl;
		cout << "3. Xoa cap lop" << endl;
		cout << "4. Chinh sua cap lop" << endl;
		cout << "5. Them lop" << endl;
		cout << "6. xuat danh sach lop" << endl;
		cout << "7.Xoa lop" << endl;
		cout << "0. Ket thuc." << endl;
		int luachon;
		cout << "Nhap lua chon: ";cin >> luachon;
		switch (luachon)
		{
		case 1: {
			//them cap lop
			them_cap_lop(ds_cl);
			break;
		}
		case 2: {
			xuat_ds_cap_lop(ds_cl);
			system("pause");
			break;
		}
		case 3: {
			if (ds_cl.sl == 0) {
				cout << "\nDanh sach rong !! Khong xoa duoc!!"<<endl;
			}
			else
			{
				xoa_cl(ds_cl);
			}
		}
		case 4: {
			if (ds_cl.sl == 0) {
				cout << "\nDanh sach rong !! Khong xoa duoc!!" << endl;
			}
			else
			{
				hieu_chinh_cl(ds_cl);
			}
			break;
		}
		case 5: {
			
			them_lop(ds_l);
			break;
		}
		case 6: {
			xuat_ds_lop(ds_l);
			break;
		}
		case 7: {
			xoa_lop(ds_l);
			break;
		}
		case 0: {
			ktr == false;
			break;
		}
		default:
			break;
		}
		
	}
}
//==========them cap lop==========
void them_cap_lop(DS_CAP_LOP& ds_cl) {
	CAP_LOP* p = new CAP_LOP;string macl;
	do {
		cout << "\nNhap ma cap lop: ";
		cin.ignore();
		getline(cin, macl);
		if (ktr_trung_cl(macl, ds_cl) >= 0) {
			cout << "\nMa vat tu da ton tai!! Moi nhap lai!! "<<endl;
		}
		else
		{
			p->ma_cap_lop = macl;
		}
	} while(ktr_trung_cl(macl, ds_cl) >= 0);
	cout << "Nhap so tiet: ";
	cin >> p->so_tiet;
	cout << "Nhap hoc phi: ";
	cin >> p->hoc_phi;
	ds_cl.ds[ds_cl.sl] = p;
	ds_cl.sl++;
}
//tao ma cap lop tu dong
string tao_ma_cap_lop(DS_CAP_LOP ds_cl) {
	string a = "CL000";
	do {
		for (int i = 2; i < a.length(); i++) {
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (ktr_trung_cl(a, ds_cl) >= 0);
	return a;	
}
int ktr_trung_cl(string a,DS_CAP_LOP ds_cl){
	for (int i = 0; i < ds_cl.sl; i++) {
		if (ds_cl.ds[i]->ma_cap_lop == a) {
			return i;
		};
	}
	return -1;
}
//=======xuat danh sach cap lop============
void xuat_ds_cap_lop(DS_CAP_LOP ds_cl) {
	for (int i = 0; i < ds_cl.sl; i++) {
		cout << "\n===========Cap lop thu: " << i + 1 << "===========";
		cout << "\nMa cap lop: " <<ds_cl.ds[i]->ma_cap_lop<< endl;
		cout << "So tiet hoc: " << ds_cl.ds[i]->so_tiet<< endl;
		cout << "Tien hoc phi: " << ds_cl.ds[i]->hoc_phi << endl;
	}
}
//=======xoa cap lop==============
void xoa_cl(DS_CAP_LOP& ds_cl) {
	string a;
	cout << "\nNhap ma cap lop can xoa: ";
	cin.ignore();
	getline(cin, a);
	//xu li
	int vt = ktr_trung_cl(a, ds_cl);
	if (vt < 0) {
		cout << "\nKhong co ma cap lop tuong ung!!";
		system("pause");
	}
	else
	{
		for (int i = vt; i < ds_cl.sl - 1; i++) {
			ds_cl.ds[i]->ma_cap_lop = ds_cl.ds[i + 1]->ma_cap_lop;
			ds_cl.ds[i]->so_tiet = ds_cl.ds[i + 1]->so_tiet;
			ds_cl.ds[i]->hoc_phi = ds_cl.ds[i + 1]->hoc_phi;
		}
		CAP_LOP* tam = ds_cl.ds[ds_cl.sl - 1];
		ds_cl.sl--;
		cout << "\nDa xoa thanh cong!!"<<endl;
		system("pause");
	}
	
}
//============Hieu chinh cap lop========
void hieu_chinh_cl(DS_CAP_LOP& ds_cl) {
	string a;
	cout << "\nNhap ma cap lop can hieu chinh: ";
	cin >> a;
	int vt = ktr_trung_cl(a, ds_cl);
	if (vt < 0) {
		cout << "\nKhong co ma cap lop tuong ung!!";
		system("pause");
	}
	else
	{
		//hieu chinh
		cout << "\nNhap so tiet: "; cin >> ds_cl.ds[vt]->so_tiet;
		cout << "\nNhap hoc phi: "; cin >> ds_cl.ds[vt]->hoc_phi;
		cout << "\nDa hieu chinh thanh cong!!";
		system("pause");
	}
}
//======Danh sach lop============
//=====danh sach tuyen tinh==========
LOP* khoi_tao_node_lop() {
	LOP* p = new LOP;
	p->pNext = NULL;
	return p;
}
LOP* tao_node_lop() {
	LOP* p = khoi_tao_node_lop();
	cout << "\nNhap ma lop: ";
	cin >> p->ma_lop;
	cout << "Nhap trang thai: ";
	cin >> p->trang_thai;
	cout << "Nhap phong hoc: ";
	cin >> p->phong_hoc;
	return p;
}
void them_1_node(LOP*& pHead, LOP* p) {
	if (pHead == NULL) {
		pHead = p;
	}
	else {
		p->pNext = pHead;
		pHead = p;
	}
}
void tao_ds_lop(DS_LOP& ds_lop) {
	ds_lop.pHead = khoi_tao_node_lop();
	cout << "\nNhap so luong lop can nhap: ";
	cin >> ds_lop.sl;
	for (int i = 0; i < ds_lop.sl; i++) {
		LOP* p = tao_node_lop();
		them_1_node(ds_lop.pHead, p);
	}
	cout << "\nTao danh sach lop thanh cong!!";
	system("pause");
}
void them_lop(DS_LOP& ds_lop) {
	LOP* p = tao_node_lop();
	them_1_node(ds_lop.pHead, p);
	ds_lop.sl++;
	cout << "\nThem lop thanh cong!!";
	system("pause");
}
bool ktr_trung_l(string a, LOP* pHead) {
	for (LOP* k = pHead; k != NULL; k = k->pNext) {
		if (k->ma_lop == a) {
			return true;
		};
	}
	return false;
}
//==============xuat danh sach lop===========
void xuat_ds_lop(DS_LOP ds_lop) {
	LOP* p = ds_lop.pHead;
	if (ds_lop.pHead == NULL) {
		cout << "\nDanh sach rong!!";
		system("pause");
	}
	else {
		int i = 1;
		while (p->pNext != NULL) {
			cout << "\nLop thu: " << i;
			cout << "\nMa lop: " << p->ma_lop << endl;
			cout << "Trang thai: " << p->trang_thai << endl;
			cout << "Phong hoc: " << p->phong_hoc<<endl;
			p = p->pNext;
			i++;
		}
	}
	system("pause");
}
//======xoa lop=====
void xoa_lop(DS_LOP &ds_l) {
	string a;
	cout << "\nNhap ma lop can xoa: ";
	cin >> a;
	LOP* pDel = ds_l.pHead;
	if (pDel == NULL) {
		cout << "\nDanh sach rong!!";
		system("pause");
	}
	else
	{
		LOP* pPre = NULL;
		while (pDel!=NULL)
		{
			if (pDel->ma_lop == a) {
				break;
			}
			pPre = pDel;
			pDel = pDel->pNext;
		}
		if (pDel == NULL) {
			cout << "\nKhong tim thay lop can xoa!!";
			system("pause");
		}
		else {
			if (pDel == ds_l.pHead) {
				//o dau ds
				ds_l.pHead = ds_l.pHead->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
			else if (pDel->pNext == NULL) {
				//o cuoi
				LOP* p = ds_l.pHead;
				while (p->pNext->pNext==NULL)
				{
					p = p->pNext;
				}
				delete(p->pNext);
				p->pNext = NULL;
			}
			else {
				//nam giua danh sach
				pPre->pNext = pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
		}
	}
}