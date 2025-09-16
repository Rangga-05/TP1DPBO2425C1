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
    Handphone(){
        this->id = 0;
        this->merek = "";
        this->jenis = "";
        this->harga = "";
        this->spesifikasi = "";
    }

    Handphone(int id, string merek, string jenis, string harga, string spesifikasi){
        this->id = id;
        this->merek = merek;
        this->jenis = jenis;
        this->harga = harga;
        this->spesifikasi = spesifikasi;
    }

    //Set Get
    void setID(int id){
        this->id = id;
    }
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

    //Destruktor
    ~Handphone(){}
};