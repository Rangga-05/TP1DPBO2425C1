from Handphone import Handphone

#list global untuk simpan semua handphone
list_Handphone = []

#fungsi untuk tambah data handphone
def tambahData():
    id = int(input("ID: "))

    #looping untuk cek id apakah sudah dipakai
    for Hp in list_Handphone:
        if Hp.getId() == id:
            print("ID Sudah Dipakai")
            return #hentikan fungsi jika id sudah ada
        
    #input data handphone lain jika id belum dipakai
    merek = input("Merek: ")
    jenis = input("Jenis: ")
    harga = input("Harga: ")
    spesifikasi = input("Spesifikasi: ")

    #buat objek handphone baru dan tambah ke list
    Hp = Handphone(id, merek, jenis, harga, spesifikasi)
    list_Handphone.append(Hp)
    print("Data Ditambahkan")

#fungsi untuk tampilin semua data handphone
def tampilkanData():
    print("\n___ Daftar Handphone Rangga Store ___")
    if len(list_Handphone) == 0: #cek list kosong atau tidak
        print("Data Belum Ada")
    else:
        #looping untuk tampilin data handphone
        for i in range(len(list_Handphone)):
            Hp = list_Handphone[i]
            print(f"ID: {Hp.getId()} | Merek: {Hp.getMerek()} | Jenis: {Hp.getJenis()} | Harga: {Hp.getHarga()} | Spesifikasi: {Hp.getSpesifikasi()}")

#fungsi untuk update data handphone berdasarkan id
def updateData():
    if len(list_Handphone) == 0:
        print("Data Belum Ada")
        return
    
    id = int(input("ID Handphone Yang Ingin Diupdate: "))
    ketemu = 0 #flag id ketemu

    #looping cari id
    for i in range(len(list_Handphone)):
        if list_Handphone[i].getId() == id:
            #input data baru
            merek = input("Update Merek: ")
            jenis = input("Update Jenis: ")
            harga = input("Update Harga: ")
            spesifikasi = input("Update Spesifikasi: ")

            #set data baru ke objek
            list_Handphone[i].setMerek(merek)
            list_Handphone[i].setJenis(jenis)
            list_Handphone[i].setHarga(harga)
            list_Handphone[i].setSpesifikasi(spesifikasi)

            ketemu += 1

    if ketemu > 0:
        print("Data Diupdate")
    else:
        print("ID Tidak Ditemukan")

#fungsi untuk hapus data handphone berdasarkan id
def hapusData():
    if len(list_Handphone) == 0:
        print("Data Belum Ada")
        return
    
    id = int(input("ID Handphone Yang Ingin Dihapus: "))
    hitung = len(list_Handphone) #simpan jumlah awal

    i = 0
    #looping pakai while karena hapus elemen
    while i < len(list_Handphone):
        if list_Handphone[i].getId() == id:
            list_Handphone.pop(i) #hapus elemen dari list
            i -= 1 #sesuaikan indeks karena list berkurang
        i += 1

        #cek apakah ada data yang dihapus
        if len(list_Handphone) < hitung:
            print("Data Dihapus")
        else:
            print("ID Tidak Ditemukan")

#fungsi untuk cari data handphone berdasarkan id
def cariData():
    if len(list_Handphone) == 0:
        print("Data Belum Ada")
        return
    
    id = int(input("ID Yang Ingin Dicari: "))
    ketemu = 0 #flag id ketemu

    for i in range(len(list_Handphone)):
        if list_Handphone[i].getId() == id:
            Hp = list_Handphone[i]
            print(f"ID: {Hp.getId()} | Merek: {Hp.getMerek()} | Jenis: {Hp.getJenis()} | Harga: {Hp.getHarga()} | Spesifikasi: {Hp.getSpesifikasi()}")
            ketemu += 1

        if ketemu == 0:
            print("ID Tidak Ditemukan") #jika id tidak ketemu

def main():
    menu = -1
    while menu != 0: #looping sampai pilih menu 0
        #menampilkan menu pilihan yang ada
        print("\n___ Menu Rangga Store ___")
        print("1. Tambah Data")
        print("2. Tampilkan Data")
        print("3. Update Data")
        print("4. Hapus Data")
        print("5. Cari Data")
        print("0. Keluar Menu")
        menu = int(input("Pilih Menu: "))

        #pilihan menu pakai if elif else
        if menu == 1:
            tambahData()
        elif menu == 2:
            tampilkanData()
        elif menu == 3:
            updateData()
        elif menu == 4:
            hapusData()
        elif menu == 5:
            cariData()
        elif menu == 0:
            print("Terima Kasih Sudah Berkunjung")
        else:
            print("Tidak Ada Pilihan Menu") #menu invalid

#menjalankan program
if __name__ == "__main__":
    main()