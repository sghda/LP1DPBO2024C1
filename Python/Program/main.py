class DPR:
    def __init__(self, id=0, nama="", bidang="", partai=""):
        self.id = id
        self.nama = nama
        self.bidang = bidang
        self.partai = partai

class CRUD:
    def __init__(self):
        self.anggota_dpr = []

    def tambah_anggota_dpr(self, nama, bidang, partai):
        id = len(self.anggota_dpr) + 1
        self.anggota_dpr.append(DPR(id, nama, bidang, partai))

    def hapus_anggota_dpr(self):
        id = int(input(">> Masukkan ID anggota yang akan dihapus: "))
        for anggota in self.anggota_dpr:
            if anggota.id == id:
                self.anggota_dpr.remove(anggota)
                print(f"<!> Data anggota DPR dengan ID {id} berhasil dihapus <!>")
                return
        print(f"<!> Data anggota DPR dengan ID {id} tidak ditemukan <!>")

    def edit_anggota_dpr(self):
        id = int(input(">> Masukkan ID anggota yang akan diedit: "))
        for anggota in self.anggota_dpr:
            if anggota.id == id:
                anggota.nama = input(">> Masukkan Nama: ")
                anggota.bidang = input(">> Masukkan Nama Bidang: ")
                anggota.partai = input(">> Masukkan Nama Partai: ")
                print(f"<!> Data anggota DPR dengan ID {id} berhasil diedit <!>")
                return
        print(f"<!> Data anggota DPR dengan ID {id} tidak ditemukan <!>")

    def tampilkan_anggota_dpr(self):
        # Menentukan lebar kolom
        max_id_length = max(len(str(anggota.id)) for anggota in self.anggota_dpr) +1
        max_nama_length = max(len(anggota.nama) for anggota in self.anggota_dpr)
        max_bidang_length = max(len(anggota.bidang) for anggota in self.anggota_dpr)
        max_partai_length = max(len(anggota.partai) for anggota in self.anggota_dpr)

        print("\n >>> Daftar Anggota DPR <<<")
        print(" +" + "-" * (max_id_length + 2) + "+" + "-" * (max_nama_length + 2) + "+" + "-" * (max_bidang_length + 2) + "+" + "-" * (max_partai_length + 2) + "+")
        # Menampilkan header tabel
        print(" | {:<{id_width}} | {:<{nama_width}} | {:<{bidang_width}} | {:<{partai_width}} |".format("ID", "Nama", "Bidang", "Partai",
                id_width=max_id_length, nama_width=max_nama_length, bidang_width=max_bidang_length, partai_width=max_partai_length))
        # Menampilkan baris pemisah
        print(" +" + "-" * (max_id_length + 2) + "+" + "-" * (max_nama_length + 2) + "+" + "-" * (max_bidang_length + 2) + "+" + "-" * (max_partai_length + 2) + "+")
        
        # Menampilkan data anggota DPR
        for anggota in self.anggota_dpr:
            print(" | {:<{id_width}} | {:<{nama_width}} | {:<{bidang_width}} | {:<{partai_width}} |".format(anggota.id, anggota.nama, anggota.bidang, anggota.partai,
                id_width=max_id_length, nama_width=max_nama_length, bidang_width=max_bidang_length, partai_width=max_partai_length))

        print(" +" + "-" * (max_id_length + 2) + "+" + "-" * (max_nama_length + 2) + "+" + "-" * (max_bidang_length + 2) + "+" + "-" * (max_partai_length + 2) + "+")


# Membuat objek CRUD
crud = CRUD()

# Menambahkan data anggota DPR secara hardcode
crud.tambah_anggota_dpr("Anggota 1", "Pendidikan", "Partai A")
crud.tambah_anggota_dpr("Anggota 2", "Pertahanan", "Partai B")
crud.tambah_anggota_dpr("Anggota 3", "Pendidikan", "Partai C")

# Main loop
while True:
    print("\nDaftar Fitur: ")
    print("1. Tambah Anggota DPR")
    print("2. Hapus Anggota DPR")
    print("3. Edit Anggota DPR")
    print("4. Tampilkan Anggota DPR")
    print("5. Keluar")

    choice = int(input("Pilihan Anda: "))
    if choice == 1:
        nama = input("Masukkan Nama: ")
        bidang = input("Masukkan Nama Bidang: ")
        partai = input("Masukkan Nama Partai: ")
        crud.tambah_anggota_dpr(nama, bidang, partai)
    elif choice == 2:
        crud.hapus_anggota_dpr()
    elif choice == 3:
        crud.edit_anggota_dpr()
    elif choice == 4:
        crud.tampilkan_anggota_dpr()
    elif choice == 5:
        print("Program selesai.")
        break
    else:
        print("Pilihan tidak valid.")
