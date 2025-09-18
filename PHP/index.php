<?php
require_once "Handphone.php";//panggil class Handphone
session_start();//mulai session untuk simpan data Handphone

//inisialisasi array listhandphone di session jika belum ada
if(!isset($_SESSION['listHandphone'])){
    $_SESSION['listHandphone'] = [];
}
//referensi agar perubahan list langsung tersimpan di session
$listHandphone = &$_SESSION['listHandphone'];
//variabel untuk menampilkan pesan suskes atau tidak
$pesan = "";

//fungsi untuk tambah data
if(isset($_POST['tindakan']) && $_POST['tindakan'] === 'tambah'){
    $id = intval($_POST['id']); //ambil id dari input
    $merek = ($_POST['merek']);
    $jenis = ($_POST['jenis']);
    $harga = ($_POST['harga']);
    $spesifikasi = ($_POST['spesifikasi']);
    $foto = $_POST['foto'];

    //looping cek id apakah sudah ada
    $adaId = false;
    foreach($listHandphone as $Hp){
        if($Hp->getId() === $id){
            $adaId = true;
        }
    }

    if($adaId == false){
        //jika id belum ada, buat objek dan tambah ke list
        $Hp = new Handphone($id, $merek, $jenis, $harga, $spesifikasi, $foto);
        $listHandphone[] = $Hp;
        $pesan = "Data Ditambahkan";
    }
    else{
        $pesan = "ID Sudah Dipakai";
    }
}

//fungsi untul update data
if(isset($_POST['tindakan']) && $_POST['tindakan'] === 'update'){
    $id = intval($_POST['id']);
    $ketemu = false;//flag untuk cek apakah id ketemu

    foreach($listHandphone as $Hp){
        if($Hp->getId() === $id){
            //jika input tidak kosong, update atribut
            if(!empty($_POST['merek'])) $Hp->setMerek($_POST['merek']);
            if(!empty($_POST['jenis'])) $Hp->setJenis($_POST['jenis']);
            if(!empty($_POST['harga'])) $Hp->setHarga($_POST['harga']);
            if(!empty($_POST['spesifikasi'])) $Hp->setSpesifikasi($_POST['spesifikasi']);
            if(!empty($_POST['foto'])) $Hp->setFoto($_POST['foto']);
            $ketemu = true;
        }
    }
    //pesan hasil update
    if($ketemu){
        $pesan = "Data Diupdate";
    }
    else{
        $pesan = "ID Tidak Ditemukan";
    }
}

//fungsi untuk hapus data
if(isset($_POST['tindakan']) && $_POST['tindakan'] === 'hapus'){
    $id = intval($_POST['id']);
    $hitung = count($listHandphone);//hitung jumlah sebelum hapus

    //looping untuk hapus elemen berdasarkan id
    foreach($listHandphone as $i => $Hp){
        if($Hp->getId() === $id){
            unset($listHandphone[$i]);
        }
    }
    //sesuain index setelah unset
    $listHandphone = array_values($listHandphone);

    //pesan sesuai hasil hapus
    if(count($listHandphone) < $hitung){
        $pesan = "Data Dihapus";
    }
    else{
        $pesan = "ID Tidak Ditemukan";
    }
}

//fungsi untuk reset data
if(isset($_POST['tindakan']) && $_POST['tindakan'] === 'reset'){
    $_SESSION['listHandphone'] = [];//kosongkan semua data di session
    $pesan = "Data Direset";
}

//fungsi untuk cari data
$cariData = null;
if(isset($_POST['tindakan']) && $_POST['tindakan'] === 'cari'){
    $id = intval($_POST['id']);
    //looping untuk cari id di listHandphone
    foreach($listHandphone as $Hp){
        if($Hp->getId() === $id){
            $cariData = $Hp;
        }
    }
    if($cariData === null){
        $pesan = "ID Tidak Ditemukan";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Rangga Store</title>
    <!-- style css -->
    <style>
        body{
            margin: 0;
            padding: 0;
            background-color: rgba(223, 235, 234, 0.94);
            font-family: "Gill Sans", "Gill Sans MT", sans-serif;
        }
        h2{
            text-align: center;
            padding: 10px;
            border-bottom: 10px solid grey;
            background-color: rgba(156, 215, 210, 0.94);
            margin-top: 0;
            font-size: 35px;
        }
        .tempatForm{
            width: 400px;
            margin: 30px auto;
            padding: 20px;
            background: #fff;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
        }
        .tempatForm label{
            font-weight: bold;
            display: block;
        }
        .tempatForm input{
            width: 100%;
            padding: 5px;
            margin-bottom: 15px;
            box-sizing: border-box;
        }
        .tombolForm{
            display: flex;
            justify-content: center;
            gap: 10px;
            flex-wrap: wrap;
        }
        .tombolForm button{
            padding: 8px 15px;
            border: none;
            cursor: pointer;
        }
        .tombolForm button[type="submit"][value="reset"]{
            background-color: red;
            color: white;
        }
        h3{
            text-align: center;
            background-color: #82b5dfff;
        }
        .tabelData{
            width: 80%;
            margin: 20px auto;
            border-collapse: collapse;
            text-align: center;
            background-color: #82b5dfff;
        }
        .tabelData th, .tabelData td{
            border: 1px solid black;
            padding: 8px;
        }
    </style>
</head>
<body>
    <h2>Menu Rangga Store</h2>

    <!-- Form Input -->
    <div class="tempatForm">
        <form method="post">
            <label>ID:</label><br>
            <input type="number" name="id" required><br>

            <label>Merek:</label><br>
            <input type="text" name="merek" <?=(isset($_POST['tindakan']) && $_POST['tindakan']=='tambah') ? 'required' : '' ?>><br>

            <label>Jenis:</label><br>
            <input type="text" name="jenis" <?=(isset($_POST['tindakan']) && $_POST['tindakan']=='tambah') ? 'required' : '' ?>><br>

            <label>Harga:</label><br>
            <input type="text" name="harga" <?=(isset($_POST['tindakan']) && $_POST['tindakan']=='tambah') ? 'required' : '' ?>><br>

            <label>Spesifikasi:</label><br>
            <input type="text" name="spesifikasi" <?=(isset($_POST['tindakan']) && $_POST['tindakan']=='tambah') ? 'required' : '' ?>><br>

            <label>Foto:</label><br>
            <input type="text" name="foto" <?=(isset($_POST['tindakan']) && $_POST['tindakan']=='tambah') ? 'required' : '' ?>><br><br>

            <p style="color: rgb(0, 128, 0); text-align: center; font-size: 25px;"><?= $pesan ?></p><br>

            <!-- Button CRUD -->
            <div class="tombolForm">
                <button type="submit" name="tindakan" value="tambah">Tambah Data</button>
                <button type="submit" name="tindakan" value="update" formnovalidate>Update Data</button>
                <button type="submit" name="tindakan" value="hapus" formnovalidate>Hapus Data</button>
                <button type="submit" name="tindakan" value="cari" formnovalidate>Cari Data</button>
                <button type="submit" name="tindakan" value="reset" formnovalidate style="background-color:red; color:white;">Reset Data</button>
            </div>
        </form>
    </div>
    
    <br>

    <!-- Tampilin Data Handphone -->
    <h3>Daftar Handphone Rangga Store</h3>
    <table class="tabelData">
        <tr>
            <th>ID</th>
            <th>Merek</th>
            <th>Jenis</th>
            <th>Harga</th>
            <th>Spesifikasi</th>
            <th>Foto</th>
        </tr>
        <?php if(count($listHandphone) === 0): ?>
            <tr><td colspan="6">Data Belum Ada</td></tr> 
        <?php else: ?>
            <?php foreach($listHandphone as $Hp): ?>
                <tr>
                    <td><?= $Hp->getId() ?></td>
                    <td><?= $Hp->getMerek() ?></td>
                    <td><?= $Hp->getJenis() ?></td>
                    <td><?= $Hp->getHarga() ?></td>
                    <td><?= $Hp->getSpesifikasi() ?></td>
                    <td><img src="<?= $Hp->getFoto() ?>" width="100"></td>
                </tr>
            <?php endforeach; ?>
        <?php endif; ?>
    </table>

    <?php if($cariData !== null): ?>
        <h3>Hasil Pencarian</h3>
        <p>
            ID: <?= $cariData->getId() ?> |
            Merek: <?= $cariData->getMerek() ?> |
            Jenis: <?= $cariData->getJenis() ?> |
            Harga: <?= $cariData->getHarga() ?> |
            Spesifikasi: <?= $cariData->getSpesifikasi() ?> |
            <img src="<?= $cariData->getFoto() ?>" width="100">
        </p>
    <?php endif; ?>
</body>
</html>