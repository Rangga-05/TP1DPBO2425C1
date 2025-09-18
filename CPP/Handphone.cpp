#include <iostream>
#include <string>
using namespace std;

//kelas Handphone untuk simpan data handphone
class Handphone{

    private:
    int id;             //id unik setiap handphone
    string merek;       //merek handphone
    string jenis;       //jenis atau tipe handphone
    string harga;       //harga handphone
    string spesifikasi; //spesifikasi handphone

    public:
    //konstruktor kosong
    Handphone(){
        this->id = 0;
        this->merek = "";
        this->jenis = "";
        this->harga = "";
        this->spesifikasi = "";
    }

    //konstruktor dengan parameter untuk inisialisasi
    Handphone(int id, string merek, string jenis, string harga, string spesifikasi){
        this->id = id;
        this->merek = merek;
        this->jenis = jenis;
        this->harga = harga;
        this->spesifikasi = spesifikasi;
    }

    //getter Setter untuk tiap atribut
    int getId(){
        return id;
    }
    void setID(int id){
        this->id = id;
    }

    string getMerek(){
        return merek;
    }
    void setMerek(string merek){
        this->merek = merek;
    }

    string getJenis(){
        return jenis;
    }
    void setJenis(string jenis){
        this->jenis = jenis;
    }

    string getHarga(){
        return harga;
    }
    void setHarga(string harga){
        this->harga = harga;
    }

    string getSpesifikasi(){
        return spesifikasi;
    }
    void setSpesifikasi(string spesifikasi){
        this->spesifikasi = spesifikasi;
    }

    //destruktor
    ~Handphone(){}
};