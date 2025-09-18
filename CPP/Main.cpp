#include <bits/stdc++.h>
#include "Handphone.cpp"
using namespace std;

//vektor untuk menampung daftar handphone
vector<Handphone> listHandphone;

//fungsi untuk tambah data handphone
void tambahData(){
    int id;
    string merek, jenis, harga, spesifikasi;

    //input id
    cout << "ID: "; cin >> id; cin.ignore();

    int i;
    //cek id apakah sudah dipakai
    for(i = 0; i < listHandphone.size(); i++){
        if(listHandphone[i].getId() == id){
            cout << "ID Sudah Dipakai\n";
            return;
        }
    }

    //input data lain handphone
    cout << "Merek: "; getline(cin, merek);
    cout << "Jenis: "; getline(cin, jenis);
    cout << "Harga: "; getline(cin, harga);
    cout << "Spesifikasi: "; getline(cin, spesifikasi);

    //membuat objek Handphone baru dan tambah ke vector
    Handphone Hp(id, merek, jenis, harga, spesifikasi);
    listHandphone.push_back(Hp);
    cout << "Data Ditambahkan\n";
}

//fungsi untuk tampilkan semua data handphone
void tampilkanData(){
    cout << "\n___ Daftar Handphone Rangga Store___\n";

    //cek apakah ada data
    if(listHandphone.size() == 0){
        cout << "Data Belum Ada\n";
    }
    else{
        //looping menampilkan semua data handphone
        for(int i = 0; i < listHandphone.size(); i++){
            cout << "ID: " << listHandphone[i].getId()
                 << " | Merek: " << listHandphone[i].getMerek()
                 << " | Jenis: " << listHandphone[i].getJenis()
                 << " | Harga: " << listHandphone[i].getHarga()
                 << " | Spesifikasi: " << listHandphone[i].getSpesifikasi() << endl;
        }
    }
}

//fungsi untuk update data handphone berdasarkan id
void updateData(){
    if(listHandphone.size() == 0){
        cout << "Data Belum Ada\n";
        return;
    }

    int id;
    cout << "ID Handphone Yang Ingin Diupdate: "; cin >> id; cin.ignore();

    int ketemu = 0;//flag apakah data ketemu
    //looping mencari id
    for(int i = 0; i < listHandphone.size(); i++){
        if(listHandphone[i].getId() == id){
            //jika ketemu input data baru
            string merek, jenis, harga, spesifikasi;
            cout << "Update Merek: "; getline(cin, merek);
            cout << "Update Jenis: "; getline(cin, jenis);
            cout << "Update Harga: "; getline(cin, harga);
            cout << "Update Spesifikasi: "; getline(cin, spesifikasi);

            //set data baru ke objek
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

//fungsi untuk hapus data berdasarkan id
void hapusData(){
    if(listHandphone.size() == 0){
        cout << "Data Belum Ada\n";
        return;
    }

    int id;
    cout << "ID Handphone Yang Ingin Dihapus: "; cin >> id;

    int hitung = listHandphone.size();//simpan jumlah awal
    //looping cari id
    for(int i = 0; i < listHandphone.size(); i++){
        if(listHandphone[i].getId() == id){
            //hapus elemen di vector
            listHandphone.erase(listHandphone.begin() + i);
            i--;//mengurangi indeks karena vector berkurang
        }
    }
    if(listHandphone.size() < hitung){//jika jumlah berkurang
        cout << "Data Dihapus\n";
    }
    else{
        cout << "ID Tidak Ditemukan\n";
    }
}

//fungsi untuk cari data handphone berdasarkan id
void cariData(){
    if(listHandphone.size() == 0){
        cout << "Data Belum Ada\n";
        return;
    }

    int id;
    cout << "ID Yang Ingin Dicari: "; cin >> id; cin.ignore();

    int ketemu = 0;
    //looping cari id
    for(int i = 0; i < listHandphone.size(); i++){
        if(listHandphone[i].getId() == id){
            //tampilkan data handphone jika ketemu
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
        //menampilkan menu pilihan yang tersedia
        cout << "\n___ Menu Rangga Store ___\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Update Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Cari Data\n";
        cout << "0. Keluar Menu\n";
        cout << "Pilih Menu: ";
        cin >> menu; cin.ignore();

        //kondisi untuk tiap menu
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
    }while(menu != 0);//looping sampai milih menu 0

    return 0;
}