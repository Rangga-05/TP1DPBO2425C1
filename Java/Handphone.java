//kelas Handphone untuk simpan data handphone
public class Handphone{
    private int id;             //id unik setiap handphone
    private String merek;       //merek handphone
    private String jenis;       //jenis atau tipe handphone
    private String harga;       //harga handphone
    private String spesifikasi; //spesifikasi handphone

    //konstruktor kosong
    public Handphone(){
        this.id = 0;
        this.merek = "";
        this.jenis = "";
        this.harga = "";
        this.spesifikasi = "";
    }

    //konstruktor dengan parameter untuk inisialisasi
    public Handphone(int id, String merek, String jenis, String harga, String spesifikasi){
        this.id = id;
        this.merek = merek;
        this.jenis = jenis;
        this.harga = harga;
        this.spesifikasi = spesifikasi;
    }

    /*Getter Setter*/
    public int getId(){
        return id;
    }
    public void setId(int id){
        this.id = id;
    }

    public String getMerek(){
        return merek;
    }
    public void setMerek(String merek){
        this.merek = merek;
    }

    public String getJenis(){
        return jenis;
    }
    public void setJenis(String jenis){
        this.jenis = jenis;
    }

    public String getHarga(){
        return harga;
    }
    public void setHarga(String harga){
        this.harga = harga;
    }

    public String getSpesifikasi(){
        return spesifikasi;
    }
    public void setSpesifikasi(String spesifikasi){
        this.spesifikasi = spesifikasi;
    }
}