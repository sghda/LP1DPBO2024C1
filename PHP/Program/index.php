<?php

class DPR {
    public $id;
    public $nama;
    public $bidang;
    public $partai;
    public $foto;

    function __construct($id=0, $nama="", $bidang="", $partai="", $foto="") {
        $this->id = $id;
        $this->nama = $nama;
        $this->bidang = $bidang;
        $this->partai = $partai;
        $this->foto = $foto;
    }
}

class CRUD {
    public $anggota_dpr;

    function __construct() {
        $this->anggota_dpr = [];
    }

    function tambah_anggota_dpr($nama, $bidang, $partai, $foto) {
        $id = count($this->anggota_dpr) + 1;
        array_push($this->anggota_dpr, new DPR($id, $nama, $bidang, $partai, $foto));
    }

    function hapus_anggota_dpr($id) {
        foreach ($this->anggota_dpr as $key => $anggota) {
            if ($anggota->id == $id) {
                unset($this->anggota_dpr[$key]);
                echo "<br> <!> Data anggota DPR dengan ID $id berhasil dihapus <!><br>";
                return;
            }
        }
        echo "<br> <!> Data anggota DPR dengan ID $id tidak ditemukan <!><br>";
    }

    function edit_anggota_dpr($id, $nama, $bidang, $partai, $foto) {
        foreach ($this->anggota_dpr as $anggota) {
            if ($anggota->id == $id) {
                $anggota->nama = $nama;
                $anggota->bidang = $bidang;
                $anggota->partai = $partai;
                $anggota->foto = $foto;
                echo "<br> <!> Data anggota DPR dengan ID $id berhasil diedit <!><br>";
                return;
            }
        }
        echo "<br> <!> Data anggota DPR dengan ID $id tidak ditemukan <!><br>";
    }

    function tampilkan_anggota_dpr() {
        echo"<br> >>> Data Anggota DPR <<< <br>";
        // Menampilkan header tabel
        echo " +-----+----------------------+------------+------------+---------------------+<br>";
        printf(" | %-3s | %-20s | %-10s | %-10s | %-20s |<br>", "ID", "Nama", "Bidang", "Partai", "Foto");

        // Menampilkan baris pemisah
        echo " +-----+----------------------+------------+------------+---------------------+<br>";
        
        // Menampilkan data anggota DPR
        foreach ($this->anggota_dpr as $anggota) {
            printf(" | %-3d | %-20s | %-10s | %-10s | <img src='%s' alt='%s' width='100' height='100'> <br> |<br>", $anggota->id, $anggota->nama, $anggota->bidang, $anggota->partai, $anggota->foto, $anggota->nama);
        }

        // Menampilkan baris pemisah
        echo " +-----+----------------------+------------+------------+---------------------+<br>";
    }
}

// Membuat objek CRUD
$crud = new CRUD();

echo "<br>Menambahkan data anggota DPR<br>";
// Menambahkan data anggota DPR secara hardcode
$crud->tambah_anggota_dpr("Anggota 1", "Bidang 1", "Partai 1", "foto1.png");
$crud->tambah_anggota_dpr("Anggota 2", "Bidang 2", "Partai 2", "foto2.png");
$crud->tambah_anggota_dpr("Anggota 3", "Bidang 3", "Partai 3", "foto3.png");

// Menampilkan data anggota DPR
$crud->tampilkan_anggota_dpr();

//edit
$crud->edit_anggota_dpr(2, "Anggota B", "Bidang B", "Partai B", "foto_b.png");

// Menampilkan data anggota DPR
$crud->tampilkan_anggota_dpr();

//hapus
$crud->hapus_anggota_dpr(2);

// Menampilkan data anggota DPR
$crud->tampilkan_anggota_dpr();

?>
