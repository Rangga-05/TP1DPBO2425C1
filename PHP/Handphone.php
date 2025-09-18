<?php

//kelas untuk simpan data handphone
class Handphone{
    //atribut private hanya bisa diakses getter setter
    private int $id;
    private string $merek;
    private string $jenis;
    private string $harga;
    private string $spesifikasi;
    private string $foto;

    //Constructor untuk inisialisasi objek Handphone baru
    public function __construct(int $id, string $merek, string $jenis, string $harga, string $spesifikasi, string $foto){
        $this->id = $id;
        $this->merek = $merek;
        $this->jenis = $jenis;
        $this->harga = $harga;
        $this->spesifikasi = $spesifikasi;
        $this->foto = $foto;
    }

    //Getter Setter
    public function getId(): int{
        return $this->id;
    }
    public function setId(int $id): void{
        $this->id = $id;
    }

    public function getMerek(): string{
        return $this->merek;
    }
    public function setMerek(string $merek): void{
        $this->merek = $merek;
    }

    public function getJenis(): string{
        return $this->jenis;
    }
    public function setJenis(string $jenis): void{
        $this->jenis = $jenis;
    }

    public function getHarga(): string{
        return $this->harga;
    }
    public function setHarga(string $harga): void{
        $this->harga = $harga;
    }

    public function getSpesifikasi(): string{
        return $this->spesifikasi;
    }
    public function setSpesifikasi(string $spesifikasi): void{
        $this->spesifikasi = $spesifikasi;
    }

    public function getFoto(): string{
        return $this->foto;
    }
    public function setFoto(string $foto): void{
        $this->foto = $foto;
    }
}