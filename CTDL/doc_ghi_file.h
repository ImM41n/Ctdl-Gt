#pragma once
#include"struct.h"
//===========doc ghi file============
void doc_file_ds_cl(DS_CAP_LOP& ds_cl) {
	ifstream filein;
	filein.open("ds_cap_lop.txt", ios_base::in);
	while (filein.eof()!=true) {
		CAP_LOP *p= new CAP_LOP;
		getline(filein, p->ma_cap_lop,',');
		getline(filein, p->so_tiet, ',');
		filein >> p->hoc_phi;
		filein.ignore();
		ds_cl.ds[ds_cl.sl] = p;
		ds_cl.sl++;
	}
	filein.close();
}