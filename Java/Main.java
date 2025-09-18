import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    
    //arraylist untuk simpan daftar handphine
    static ArrayList<Handphone> listHandphone = new ArrayList<>();
    static Scanner input = new Scanner(System.in);

    //fungsi untuk tambah data handphone
    public static void tambahData(){
        System.out.print("ID: ");
        int id = input.nextInt();
        input.nextLine();//membersihkan karakter newline agar tidak kosong

        //looping untuk cek id apakah sudah dipakai
        for(int i = 0; i < listHandphone.size(); i++){
            if(listHandphone.get(i).getId() == id){
                System.out.println("ID Dipakai");
                return;
            }
        }

        //input data lain handphone
        System.out.print("Merek: ");
        String merek = input.nextLine();
        System.out.print("Jenis: ");
        String jenis = input.nextLine();
        System.out.print("Harga: ");
        String harga = input.nextLine();
        System.out.print("Spesifikasi: ");
        String spesifikasi = input.nextLine();

        //buat objek Handphone baru dan tambah ke arraylist
        Handphone Hp = new Handphone(id, merek, jenis, harga, spesifikasi);
        listHandphone.add(Hp);
        System.out.println("Data Ditambahkan");
    }

    //fungsi untuk tampilin semua data handphone
    public static void tampilkanData(){
        System.out.println("\n___ Daftar Handphone Rangga Store ___");
        if(listHandphone.size() == 0){//jika arraylist kosong
            System.err.println("Data Belum Ada");
        }
        else{
            //looping untuk tampilin semua data handphone
            for(int i = 0; i < listHandphone.size(); i++){
                Handphone Hp = listHandphone.get(i);//ambil objek handphone
                System.out.println("ID: " + Hp.getId()
                        + " | Merek: " + Hp.getMerek()
                        + " | Jenis: " + Hp.getJenis()
                        + " | Harga: " + Hp.getHarga()
                        + " | Spesifikasi: " + Hp.getSpesifikasi());
            }
        }
    }

    //fungsi untuk update data handphone berdasarkan id
    public static void updateData(){
        if(listHandphone.size() == 0){//cek arraylist apakah kosong
            System.out.println("Data Belum Ada");
            return;
        }

        System.out.print("ID Handphone Yang Ingin Diupdate: ");
        int id = input.nextInt();
        input.nextLine();//bersihin buffer

        int ketemu = 0;//flag id ketemu
        //looping cari id
        for(int i = 0; i < listHandphone.size(); i++){
            if(listHandphone.get(i).getId() == id){
                //input data baru
                System.out.print("Update Merek: ");
                listHandphone.get(i).setMerek(input.nextLine());
                System.out.print("Update Jenis: ");
                listHandphone.get(i).setJenis(input.nextLine());
                System.out.print("Update Harga: ");
                listHandphone.get(i).setHarga(input.nextLine());
                System.out.print("Update Spesifikasi: ");
                listHandphone.get(i).setSpesifikasi(input.nextLine());
                ketemu++;
            }
        }
        if(ketemu > 0){
            System.out.println("Data Diupdate");
        }
        else{
            System.out.println("ID Tidak Ditemukan");
        }
    }

    //fungsi untuk hapus data handphone berdasarkan id
    public static void hapusData(){
        if(listHandphone.size() == 0){
            System.out.println("Data Belum Ada");
            return;
        }

        System.out.print("ID Handphone Yang Ingin Dihapus: ");
        int id = input.nextInt();
        input.nextLine();

        int hitung = listHandphone.size();//simpan jumlah awal
        for(int i = 0; i < listHandphone.size(); i++){
            if(listHandphone.get(i).getId() == id){
                listHandphone.remove(i);//hapus elemen dari arraylist
                i--;//sesuain indeks karena arraylist berkurang
            }
        }
        if(listHandphone.size() < hitung){
            System.out.println("Data Dihapus");
        }
        else{
            System.out.println("ID Tidak Ditemukan");
        }
    }

    //fungsi untuk cari data handphone berdasarkan id
    public static void cariData(){
        if(listHandphone.size() == 0){
            System.out.println("Data Belum Ada");
            return;
        }

        System.out.print("ID Yang Ingin Dicari: ");
        int id = input.nextInt();
        input.nextLine();

        int ketemu = 0;
        for(int i = 0; i < listHandphone.size(); i++){
            if(listHandphone.get(i).getId() == id){
                Handphone Hp = listHandphone.get(i);
                System.out.println("ID: " + Hp.getId()
                        + " | Merek: " + Hp.getMerek()
                        + " | Jenis: " + Hp.getJenis()
                        + " | Harga: " + Hp.getHarga()
                        + " | Spesifikasi: " + Hp.getSpesifikasi());
                ketemu++;
            }
        }
        if(ketemu == 0){
            System.out.println("ID Tidak Ditemukan");//jika id tidak ketemu
        }
    }

    public static void main(String[] args){
        int menu;

        do{
            //menampilkan menu pilihan yang ada
            System.out.println("\n___ Menu Rangga Store ___");
            System.out.println("1. Tambah Data");
            System.out.println("2. Tampilkan Data");
            System.out.println("3. Update Data");
            System.out.println("4. Hapus Data");
            System.out.println("5. Cari Data");
            System.out.println("0. Keluar Menu");
            System.out.print("Pilih Menu: ");
            menu = input.nextInt();
            input.nextLine();//bersihin buffer

            //pilihan menu pakai if else
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
                System.out.println("Terima Kasih Sudah Berkunjung");
            }
            else{
                System.out.println("Tidak Ada Pilihan Menu");//menu invalid
            }
        } while(menu != 0);//looping sampai pilih menu 0
    }
}