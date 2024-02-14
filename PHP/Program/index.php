<?php

class DPR {
    public $id;
    public $nama;
    public $bidang;
    public $partai;

    function __construct($id=0, $nama="", $bidang="", $partai="") {
        $this->id = $id;
        $this->nama = $nama;
        $this->bidang = $bidang;
        $this->partai = $partai;
    }
}

class CRUD {
    public $anggota_dpr;

    function __construct() {
        $this->anggota_dpr = [];
    }

    function tambah_anggota_dpr($nama, $bidang, $partai) {
        $id = count($this->anggota_dpr) + 1;
        array_push($this->anggota_dpr, new DPR($id, $nama, $bidang, $partai));
    }

    function hapus_anggota_dpr($id) {
        foreach ($this->anggota_dpr as $key => $anggota) {
            if ($anggota->id == $id) {
                unset($this->anggota_dpr[$key]);
                echo "\n <!> Data anggota DPR dengan ID $id berhasil dihapus <!>\n";
                return;
            }
        }
        echo "\n <!> Data anggota DPR dengan ID $id tidak ditemukan <!>\n";
    }

    function edit_anggota_dpr($id, $nama, $bidang, $partai) {
        foreach ($this->anggota_dpr as $anggota) {
            if ($anggota->id == $id) {
                $anggota->nama = $nama;
                $anggota->bidang = $bidang;
                $anggota->partai = $partai;
                echo "\n <!> Data anggota DPR dengan ID $id berhasil diedit <!>\n";
                return;
            }
        }
        echo "\n <!> Data anggota DPR dengan ID $id tidak ditemukan <!>\n";
    }

    function tampilkan_anggota_dpr() {
        echo"\n >>> Data Anggota DPR <<<\n";
        // Menampilkan header tabel
        echo " +-----+----------------------+------------+------------+\n";
        printf(" | %-3s | %-20s | %-10s | %-10s |\n", "ID", "Nama", "Bidang", "Partai");

        // Menampilkan baris pemisah
        echo " +-----+----------------------+------------+------------+\n";
        
        // Menampilkan data anggota DPR
        foreach ($this->anggota_dpr as $anggota) {
            printf(" | %-3d | %-20s | %-10s | %-10s |\n", $anggota->id, $anggota->nama, $anggota->bidang, $anggota->partai);
        }

        // Menampilkan baris pemisah
        echo " +-----+----------------------+------------+------------+\n";
    }
}

// Membuat objek CRUD
$crud = new CRUD();

echo "Menambahkan data anggota DPR\n";
// Menambahkan data anggota DPR secara hardcode
$crud->tambah_anggota_dpr("Anggota 1", "Bidang 1", "Partai 1");
$crud->tambah_anggota_dpr("Anggota 2", "Bidang 2", "Partai 2");
$crud->tambah_anggota_dpr("Anggota 3", "Bidang 3", "Partai 3");

// Menampilkan data anggota DPR
$crud->tampilkan_anggota_dpr();

//edit
$crud->edit_anggota_dpr(2, "Anggota B", "Bidang B", "Partai B");

// Menampilkan data anggota DPR
$crud->tampilkan_anggota_dpr();

//hapus
$crud->hapus_anggota_dpr(2);

// Menampilkan data anggota DPR
$crud->tampilkan_anggota_dpr();


?>
