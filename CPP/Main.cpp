#include <iostream>
#include "Handphone.cpp"
using namespace std;

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