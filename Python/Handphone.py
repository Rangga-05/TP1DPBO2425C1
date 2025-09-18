#kelas handphone untuk simpan data handphone
class Handphone:

    #konstruktor dengan parameter untuk inisialisasi objek
    def __init__(self, id: int, merek: str, jenis: str, harga: str, spesifikasi: str):
        self._id = int(id)                      #id unik handphone
        self._merek = str(merek)                #merek handphone
        self._jenis = str(jenis)                #jenis atau tipe handphone
        self._harga = str(harga)                #harga handphone
        self._spesifikasi = str(spesifikasi)    #spesifikasi handphone

    #Getter Setter
    def getId(self) -> int:
        return self._id
    def setId(self, id: int) -> None:
        self._id = int(id)

    def getMerek(self) -> str:
        return self._merek
    def setMerek(self, merek: str) -> None:
        self._merek = str(merek)

    def getJenis(self) -> str:
        return self._jenis
    def setJenis(self, jenis: str) -> None:
        self._jenis = str(jenis)

    def getHarga(self) -> str:
        return self._harga
    def setHarga(self, harga: str) -> None:
        self._harga = str(harga)

    def getSpesifikasi(self) -> str:
        return self._spesifikasi
    def setSpesifikasi(self, spesifikasi: str) -> None:
        self._spesifikasi = str(spesifikasi)