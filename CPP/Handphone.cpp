#include <iostream>
#include <string>
using namespace std;

class Handphone{

    private:
    int id;
    string merek;
    string jenis;
    string harga;
    string spesifikasi;

    public:
    Handphone(){}

    Handphone(int id, string merek, string jenis, string harga, string spesifikasi){
        this->id = id;
        this->merek = merek;
        this->jenis = jenis;
        this->harga = harga;
        this->spesifikasi = spesifikasi;
    }

    //Set Get
    int getId(){
        return id;
    }

    void setMerek(string merek){
        this->merek = merek;
    }
    string getMerek(){
        return merek;
    }

    void setJenis(string jenis){
        this->jenis = jenis;
    }
    string getJenis(){
        return jenis;
    }

    void setHarga(string harga){
        this->harga = harga;
    }
    string getHarga(){
        return harga;
    }

    void setSpesifikasi(string spesifikasi){
        this->spesifikasi = spesifikasi;
    }
    string getSpesifikasi(){
        return spesifikasi;
    }

    void ingfoHandphone(){
        cout << "ID: " << id
             << " | Merek: " << merek
             << " | Jenis: " << jenis
             << " | Harga: Rp" << harga
             << " | Spesifikasi: " << spesifikasi << endl;
    }

    //Destruktor
    ~Handphone(){}
};

/*CRUD*/
Handphone daftar[100];
int jumlahData = 0;

int aturId(){
    int i;
    for(i = 1; i <= jumlahData + 1; i++){
        int ketemu = 0;
        for(int k = 0; k < jumlahData; k++){
            if(daftar[k].getId() == i){
                ketemu++;
            }
        }
        if(ketemu == 0){
            return i;
        }
    }
    return jumlahData + 1;
}

void tambahData(){
    int id = aturId();
    string merek, jenis, harga, spesifikasi;

    cout << "Merek: "; getline(cin, merek);
    cout << "Jenis: "; getline(cin, jenis);
    cout << "Harga: "; getline(cin, harga);
    cout << "Spesifikasi: "; getline(cin, spesifikasi);

    daftar[jumlahData] = Handphone(id, merek, jenis, harga, spesifikasi);
    jumlahData++;
    cout << "Data Ditambahkan\n";
}

void tampilkanData(){
    if(jumlahData == 0){
        cout << "Data Belum Ada\n";
        return;
    }

    for(int i = 0; i < jumlahData - 1; i++){
        for(int j = 0; j < jumlahData - i - 1; j++){
            if(daftar[j].getId() > daftar[j + 1].getId()){
                Handphone temp = daftar[j];
                daftar[j] = daftar[j + 1];
                daftar[j + 1] = temp;
            }
        }
    }

    cout << "\n___ Daftar Handphone ___\n";
    for(int i = 0; i < jumlahData; i++){
        daftar[i].ingfoHandphone();
    }
}

void updateData(){
    int id;
    cout << "ID Handphone Yang Ingin Diupdate: "; cin >> id; cin.ignore();

    for(int i = 0; i < jumlahData; i++){
        if(daftar[i].getId() == id){
            string merek, jenis, harga, spesifikasi;
            cout << "Update Merek: "; getline(cin, merek);
            cout << "Update Jenis: "; getline(cin, jenis);
            cout << "Update Harga: "; getline(cin, harga);
            cout << "Update Spesifikasi: "; getline(cin, spesifikasi);

            daftar[i].setMerek(merek);
            daftar[i].setJenis(jenis);
            daftar[i].setHarga(harga);
            daftar[i].setSpesifikasi(spesifikasi);

            cout << "Data Diupdate\n";
            return;
        }
    }
    cout << "ID " << id << " Tidak Ditemukan\n";
}

void hapusData(){
    int id;
    cout << "ID Handphone Yang Ingin Dihapus: "; cin >> id; cin.ignore();

    for(int i = 0; i < jumlahData; i++){
        if(daftar[i].getId() == id){
            for(int j = i; j < jumlahData - 1; j++){
                daftar[j] = daftar[j + 1];
            }
            jumlahData--;
            cout << "Data Dihapus\n";
            return;
        }
    }
    cout << "ID " << id << " Tidak Ditemukan\n";
}

void cariData(){
    int id;
    cout << "ID Yang Ingin Dicari: "; cin >> id; cin.ignore();

    for(int i = 0; i < jumlahData; i++){
        if(daftar[i].getId() == id){
            cout << "Data Ditemukan:\n";
            daftar[i].ingfoHandphone();
            return;
        }
    }
    cout << "ID " << id << " Tidak Ditemukan\n";
}