#pragma once
#include"struct.h"
/// <summary>
///======ham chuan hoa chu=============
/// </summary>
/// <param name="a"></param>
void chuan_hoa_chu(string &a) {
	//....an...toan
	//An Toan
	//xu li space đầu
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);

	}
	//xu li cuoi
	while (a[a.length()-1] == ' ') {
		a.erase(a.begin() + a.length() - 1);
	}
	//xu li giua
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ' && a[i + 1] == ' ') {
			a.erase(a.begin() + i);
			i--;
		}
	}
	//chuan hoa ki tu
	if (a[0] >= 97 && a[0] <= 122) {
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++) {
		if (a[i] == ' ') {
			i++;
			if (a[i] >= 97 && a[i] <= 122) {
				a[i] -= 32;
			}
		}
		else
		{
			if (a[i] >= 65 && a[i] <= 90) {
				a[i] += 32;
			}
		}
	}
}