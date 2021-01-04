#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include "Header/TextTable.h"
using namespace std;

struct musik {
    string penyanyi,judul,kode_album;
    int tahun;
};
void tambah (musik lagu[],int jml,int i,int n) {
    bool ulang;
    char lagi;
        
        for (int i=0; i <n; i++) {
            cout << "Lagu ke- " << i+1 << endl;
            cout << "Masukan Judul Lagu   : "; fflush(stdin);cin >> lagu[i].judul;
            cout << "Masukan Penyanyi     : "; fflush(stdin);cin >> lagu[i].penyanyi;
            cout << "Masukan Kode Album   : "; fflush(stdin);cin >> lagu[i].kode_album;
            cout << "Masukan Tahun Terbit : "; fflush(stdin);cin >> lagu[i].tahun;

            cout << "\n";
            cout << "Lagu ke- " << i+1 << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Judul Lagu   : " << lagu[i].judul << endl;
            cout << "Penyanyi     : " << lagu[i].penyanyi << endl;
            cout << "Kode Album   : " << lagu[i].kode_album << endl;
            cout << "Tahun Terbit : " << lagu[i].tahun << endl;
            cout << "-----------------------------------------------" << endl;
            // jml = jml +1;
            // i = i+1;
        }
        
}

void tabel_tampil (musik lagu[],int jml,int n) {
    cout << endl;
    string yearss =to_string(lagu->tahun); 
    TextTable t( '-', '|', '+' );
    
    t.add( "Judul Lagu   " );
    t.add( "Penyanyi Lagu" );
    t.add( "Kode Album   " );
    t.add( "Tahun Terbit " );
    t.endOfRow();

    for (int i=0; i<n; i++){
    t.add( lagu[i].judul);
    t.add( lagu[i].penyanyi );
    t.add( lagu[i].kode_album );
    t.add( yearss);
    t.endOfRow();
    }

    t.setAlignment( 2, TextTable::Alignment::RIGHT );
    cout << t;
    cout << "--------------------------------------------" << endl;

}

int main () {
    musik lagu[20];
    int jml =1 , i=0 ,n;
    bool ulang;
    char lagi;

    cout << "Program Input Data Lagu" << endl;
    cout << "-----------------------" << endl;
    do {
        cout << "Masukan Jumlah Data yang ingin di input : "; cin >> n;
        tambah(lagu,jml,i,n);

        cout << "Apakan ingin menginput data lagi ?y/n "; cin >>lagi;
        ulang = ((lagi == 'y' || lagi == 'Y'));
    }while (ulang);
    
    tabel_tampil(lagu,jml,n);
    cout << "\n Terimakasih \n";
    cout << "---------------------------------------------" << endl;

}

