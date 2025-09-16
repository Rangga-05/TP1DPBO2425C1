#include <bits/stdc++.h>
#include "Handphone.cpp"
using namespace std;

vector<Handphone> listHandphone;

void tambahData(){
    int id;
    string merek, jenis, harga, spesifikasi;

    cout << "ID: "; cin >> id; cin.ignore();

    int i;
    for(i = 0; i < listHandphone.size(); i++){
        if(listHandphone[i].getId() == id){
            cout << "ID Sudah Dipakai\n";
            return;
        }
    }

    cout << "Merek: "; getline(cin, merek);
    cout << "Jenis: "; getline(cin, jenis);
    cout << "Harga: "; getline(cin, harga);
    cout << "Spesifikasi: "; getline(cin, spesifikasi);

    Handphone Hp(id, merek, jenis, harga, spesifikasi);
    listHandphone.push_back(Hp);
    cout << "Data Ditambahkan\n";
}

void tampilkanData(){
    cout << "\n___ Daftar Handphone Rangga Store___\n";
    if(listHandphone.size() == 0){
        cout << "Data Belum Ada\n";
    }
    else{
        for(int i = 0; i < listHandphone.size(); i++){
            cout << "ID: " << listHandphone[i].getId()
                 << " | Merek: " << listHandphone[i].getMerek()
                 << " | Jenis: " << listHandphone[i].getJenis()
                 << " | Harga: " << listHandphone[i].getHarga()
                 << " | Spesifikasi: " << listHandphone[i].getSpesifikasi() << endl;
        }
    }
}

void updateData(){
    if(listHandphone.size() == 0){
        cout << "Data Belum Ada\n";
        return;
    }

    int id;
    cout << "ID Handphone Yang Ingin Diupdate: "; cin >> id; cin.ignore();

    int ketemu = 0;
    for(int i = 0; i < listHandphone.size(); i++){
        if(listHandphone[i].getId() == id){
            string merek, jenis, harga, spesifikasi;
            cout << "Update Merek: "; getline(cin, merek);
            cout << "Update Jenis: "; getline(cin, jenis);
            cout << "Update Harga: "; getline(cin, harga);
            cout << "Update Spesifikasi: "; getline(cin, spesifikasi);

            listHandphone[i].setMerek(merek);
            listHandphone[i].setJenis(jenis);
            listHandphone[i].setHarga(harga);
            listHandphone[i].setSpesifikasi(spesifikasi);

            ketemu++;
        }
    }
    if(ketemu > 0){
        cout << "Data Diupdate\n";
    }
    else{
        cout << "ID Tidak Ditemukan\n";
    }
}

void hapusData(){
    if(listHandphone.size() == 0){
        cout << "Data Belum Ada\n";
        return;
    }

    int id;
    cout << "ID Handphone Yang Ingin Dihapus: "; cin >> id;

    int hitung = listHandphone.size();
    for(int i = 0; i < listHandphone.size(); i++){
        if(listHandphone[i].getId() == id){
            listHandphone.erase(listHandphone.begin() + i);
            i--;
        }
    }
    if(listHandphone.size() < hitung){
        cout << "Data Dihapus\n";
    }
    else{
        cout << "ID Tidak Ditemukan\n";
    }
}

void cariData(){
    if(listHandphone.size() == 0){
        cout << "Data Belum Ada\n";
        return;
    }

    int id;
    cout << "ID Yang Ingin Dicari: "; cin >> id; cin.ignore();

    int ketemu = 0;
    for(int i = 0; i < listHandphone.size(); i++){
        if(listHandphone[i].getId() == id){
            cout << "ID: " << listHandphone[i].getId()
                 << " | Merek: " << listHandphone[i].getMerek()
                 << " | Jenis: " << listHandphone[i].getJenis()
                 << " | Harga: " << listHandphone[i].getHarga()
                 << " | Spesifikasi: " << listHandphone[i].getSpesifikasi() << endl;
            ketemu++;
        }
    }
    if(ketemu == 0){
        cout << "ID Tidak Ditemukan\n";
    }
}

int main(){
    int menu;
    
    do{
        cout << "\n___ Menu Rangga Store ___\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Update Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Cari Data\n";
        cout << "0. Keluar Menu\n";
        cout << "Pilih Menu: ";
        cin >> menu; cin.ignore();

        if(menu == 1){
            tambahData();
        }
        else if(menu == 2){
            tampilkanData();
        }
        else if(menu == 3){
            updateData();
        }
        else if(menu == 4){
            hapusData();
        }
        else if(menu == 5){
            cariData();
        }
        else if(menu == 0){
            cout << "Terima Kasih Sudah Berkunjung\n";
        }
        else{
            cout << "Tidak Ada Pilihan Menu\n";
        }
    }while(menu != 0);

    return 0;
}