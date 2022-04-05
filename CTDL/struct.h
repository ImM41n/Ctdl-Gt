///BAI TAP CUOI KI MON CTDL&GT//
//DE TAI: TRUNG TAM TIENG ANH//
//NAME: NGUYEN QUANG CHINH//
//ID: N19DCAT011
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>// rand , srand
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;
//==========Diem========
//danh sach lien ket======
struct Diem {
	//data
	int ky_nang;//=0: nghe; =1:noi; =2 doc; =3 viet;
	float nghe;
	float noi;
	float doc;
	float viet;
	//pointer
	Diem* pNext;
};
typedef struct Diem DIEM;
struct ds_diem {
	DIEM* pHead = NULL;
	int sl = 0;
};
typedef struct ds_diem DS_DIEM;
//=======danh sach hoc vien========
//====cay nhi phan tim kiem========
struct hoc_vien {
	//data
	int ma_hoc_vien;//la so ngay nhien tu dong
	string ho;
	string ten;
	string phai;
	//*point diem
	DS_DIEM danh_sach_diem;
	//pointer
	hoc_vien* pLeft;
	hoc_vien* pRight;
};
typedef struct hoc_vien* tree;
struct ds_hoc_vien {
	tree ds=NULL;
	int sl = 0;

};
typedef struct ds_hoc_vien DS_HOC_VIEN;
//===========danh sach lop===========
//===========danh sach lien ket=========
struct lop {
	//data
	string ma_lop;
	int trang_thai;//co 1 ma duy nhat;0:cb mo; 1:lop dg hc; 2: lop finish
	string phong_hoc;
	//point -> ds hoc vien
	DS_HOC_VIEN danh_sach_hv;
	//pointer
	lop* pNext;
};
typedef struct lop LOP;
struct ds_lop {
	LOP* pHead=NULL;
	int sl = 0;
};
typedef struct ds_lop DS_LOP;
//============danh sach cap lop==========
//====mang con tro==============
struct cap_lop{
	//data
	string ma_cap_lop;
	string so_tiet;
	int hoc_phi;
	//point-> ds_lop
	DS_LOP danh_sach_lop;
};
typedef struct cap_lop CAP_LOP;
struct ds_cap_lop {
	CAP_LOP* ds[100];//max=100 cap lop
	int sl = 0;
};
typedef struct ds_cap_lop DS_CAP_LOP;