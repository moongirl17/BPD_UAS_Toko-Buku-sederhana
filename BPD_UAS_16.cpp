// BPD_UAS_16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Nama       : Widiya Marin
NIM        : 202004560016
Tujuan     : Membuat Toko Buku sederhana dengan menginput judul buku, jumlah buku , dan harga buku.
Ketentuan  : Menggunakan algoritma selection sorting untuk mengurutkan dari harga terendah sampai tertinggi,
			 dan mengurutkan nama barang sesuai dengan alpabet , function dan prosedur, array of structur.
		 
*/

#include <iostream>
#include <string>
using namespace std;

struct Buku {
	int jumlah16, harga16, totalkeseluruhan16;
	string judulbuku16;
};

int Total(int x, int y) {
	int z = x - y;
	return z;
}

void Daftar(struct Buku bku16[], int jumlahbuku16, int jumlahharga16) {
	cout << " =======================================================================" << endl;
	cout << " \t\t\tDaftar Belanja Anda" << endl;
	cout << " =======================================================================" << endl;
	cout << " \tNama Buku \t|\tJumlah Buku \t|\tTotal harga\t  \n";
	cout << "========================================================================" << endl;
	for (int i = 0; i < jumlahbuku16; i++) {
		cout << bku16[i].judulbuku16 << "\t\t\t\t";
		cout << bku16[i].jumlah16 << "\t\t\t";
		cout << bku16[i].totalkeseluruhan16;
		cout << endl;
	}
	cout << "========================================================================";
	cout << "\nTotal Keseluruhan  Buku  Anda: Rp. " << jumlahharga16 << endl;
}

int main() {
	struct Buku bku16[50];
	string nama16, temp16;
	int uang16, jumlahbuku16, totalharga16 = 0, kembalian16, tempp16 = 0;
	cout << "========================================================================" << endl;
	cout << " \t\tSelamat Datang Di  Toko Buku Kami \n";
	cout << "=========================================================================" << endl << endl;

	do {
		cout << "Masukkan jumlah Buku yang ingin dibeli : ";
		cin >> jumlahbuku16;

		if (jumlahbuku16 < 0) {
			cout << "Angka tidak boleh negatif, silahkan coba lagi ! " << endl;
			continue;
		}
		else if (jumlahbuku16 > 50) {
			cout << "Angka tidak boleh lebih dari 20, silahkan coba lagi ! " << endl;
			continue;
		}
		else
			break;
	} while (jumlahbuku16 < 0 || jumlahbuku16 > 50);

	for (int i = 0; i < jumlahbuku16; i++) {
		cout << endl;
		cout << "Masukkan nama buku ke -  " << i + 1 << " : ";
		cin.ignore();
		getline(cin, bku16[i].judulbuku16);
		cout << "Jumlah " << bku16[i].judulbuku16 << " yang dibeli : ";
		cin >> bku16[i].jumlah16;
		cout << "Harga untuk 1 " << bku16[i].judulbuku16 << " : ";
		cin >> bku16[i].harga16;
		bku16[i].totalkeseluruhan16 = bku16[i].harga16 * bku16[i].jumlah16;

		totalharga16 += bku16[i].totalkeseluruhan16;
	}
	Daftar(bku16, jumlahbuku16, totalharga16);

	do {
		cout << "\nMasukkan uang anda : Rp.";
		cin >> uang16;
		if (uang16 < totalharga16) {
			cout << "\nMaaf uang anda kurang !" << endl;
			cout << "Silahkan masukkan uang anda dengan jumlah yang pas atau lebih !" << endl;
			continue;
		}
		else if (uang16 > totalharga16) {
			kembalian16 = Total(uang16, totalharga16);
			cout << "Kembalian Anda : Rp." << kembalian16 << endl << endl;
			cout << "\n\t\tTerimakasih telah berbelanja di toko kami ! " << endl;
			break;
		}
		else if (uang16 == totalharga16) {
			cout << "\t\tTerimakasih telah berbelanja di toko kami ! " << endl;
			break;
		}
	} while (true);
	cout << "=========================================================================" << endl << endl;
	cout << "\t\t\tDaftar sebelum Sorting: " << endl;
	cout << "\nNama buku : " << endl;
	for (int i = 0; i < jumlahbuku16; i++) {
		cout << bku16[i].judulbuku16;
		cout << bku16[i].jumlah16;
		cout << endl;
	}
	cout << "\nHarga buku  : " << endl;
	for (int i = 0; i < jumlahbuku16; i++) {
		cout << bku16[i].totalkeseluruhan16 << endl;
	}
	cout << "=========================================================================" << endl << endl;
	cout << "\t\t\tSesudah di Sorting : " << endl;
	for (int a = 0; a < jumlahbuku16 - 1; a++) {
		for (int b = a + 1; b < jumlahbuku16; b++) {
			if (bku16[a].judulbuku16 > bku16[b].judulbuku16) {
				temp16 = bku16[a].judulbuku16;
				bku16[a].judulbuku16 = bku16[b].judulbuku16;
				bku16[b].judulbuku16 = temp16;
			}
		}
	}
	for (int x = 0; x < jumlahbuku16 - 1; x++) {
		for (int y = x + 1; y < jumlahbuku16; y++) {
			if (bku16[x].totalkeseluruhan16 > bku16[y].totalkeseluruhan16) {
				tempp16 = bku16[x].totalkeseluruhan16;
				bku16[x].totalkeseluruhan16 = bku16[y].totalkeseluruhan16;
				bku16[y].totalkeseluruhan16 = tempp16;
			}
		}
	}

	cout << "\nNama buku secara alphabet: " << endl;
	for (int a = 0; a < jumlahbuku16; a++) {
		cout << bku16[a].judulbuku16 << endl;
	}
	cout << "\nHarga buku dari yang termurah : " << endl;
	for (int x = 0; x < jumlahbuku16; x++) {
		cout << bku16[x].totalkeseluruhan16 << endl;
	}
}
