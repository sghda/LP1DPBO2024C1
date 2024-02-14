import java.util.ArrayList;
import java.util.Scanner;

class DPR {
    private int id;
    private String nama;
    private String namaBidang;
    private String namaPartai;

    public DPR() {
        this.id = 0;
        this.nama = "";
        this.namaBidang = "";
        this.namaPartai = "";
    }

    public DPR(int id, String nama, String namaBidang, String namaPartai) {
        this.id = id;
        this.nama = nama;
        this.namaBidang = namaBidang;
        this.namaPartai = namaPartai;
    }

    public int getId() {
        return this.id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNama() {
        return this.nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getNamaBidang() {
        return this.namaBidang;
    }

    public void setNamaBidang(String namaBidang) {
        this.namaBidang = namaBidang;
    }

    public String getNamaPartai() {
        return this.namaPartai;
    }

    public void setNamaPartai(String namaPartai) {
        this.namaPartai = namaPartai;
    }
}

class CRUD {
    private ArrayList<DPR> anggotaDPR;

    public CRUD() {
        this.anggotaDPR = new ArrayList<>();
    }

    public int getAnggotaDPR() {
        return anggotaDPR.size();
    }

    public void tambahAnggotaDPR(String nama, String namaBidang, String namaPartai) {
        int id = anggotaDPR.size() + 1;
        anggotaDPR.add(new DPR(id, nama, namaBidang, namaPartai));
    }

    public void hapusAnggotaDPR() {
        Scanner scanner = new Scanner(System.in);
        System.out.print(">> Masukkan ID anggota yang akan dihapus : ");
        int id = scanner.nextInt();

        int indexToDelete = -1;
        boolean found = false;
        for (int i = 0; i < anggotaDPR.size(); ++i) {
            if (anggotaDPR.get(i).getId() == id && !found) {
                indexToDelete = i;
                found = true;
            }
        }

        if (indexToDelete != -1) {
            anggotaDPR.remove(indexToDelete);
            System.out.println("<!> Data anggota DPR dengan ID " + id + " berhasil dihapus <!>");
        } else {
            System.out.println("<!> Data anggota DPR dengan ID " + id + " tidak ditemukan <!>");
        }
    }

    public void editAnggotaDPR() {
        Scanner scanner = new Scanner(System.in);
        System.out.print(">> Masukkan ID anggota yang akan diedit : ");
        int id = scanner.nextInt();

        int indexToEdit = -1;
        boolean found = false;
        for (int i = 0; i < anggotaDPR.size(); ++i) {
            if (anggotaDPR.get(i).getId() == id && !found) {
                indexToEdit = i;
                found = true;
            }
        }

        if (indexToEdit != -1) {
            System.out.print(">> Masukkan ID: ");
            int newId = scanner.nextInt();
            System.out.print(">> Masukkan Nama: ");
            scanner.nextLine();
            String nama = scanner.nextLine();
            System.out.print(">> Masukkan Nama Bidang: ");
            String namaBidang = scanner.nextLine();
            System.out.print(">> Masukkan Nama Partai: ");
            String namaPartai = scanner.nextLine();
            anggotaDPR.get(indexToEdit).setId(newId);
            anggotaDPR.get(indexToEdit).setNama(nama);
            anggotaDPR.get(indexToEdit).setNamaBidang(namaBidang);
            anggotaDPR.get(indexToEdit).setNamaPartai(namaPartai);
            System.out.println("<!> Data anggota DPR dengan ID " + id + " berhasil diedit <!>");
        } else {
            System.out.println("<!> Data anggota DPR dengan ID " + id + " tidak ditemukan <!>");
        }
    }

    // public void tampilkanAnggotaDPR() {
    //     System.out.println("\n >> Daftar Anggota DPR << ");
    //     System.out.println("ID \t Nama \t\t Bidang \t\t Partai");
    //     for (DPR anggota : anggotaDPR) {
    //         System.out.println(anggota.getId() + " \t " + anggota.getNama() + " \t\t " + anggota.getNamaBidang() + " \t " + anggota.getNamaPartai());
    //     }
    // }

    public void tampilkanAnggotaDPR() {
        // Menentukan panjang maksimal untuk setiap kolom
        int maxIdLength = 2; // Minimal panjang ID
        int maxNamaLength = 4; // Minimal panjang Nama
        int maxBidangLength = 6; // Minimal panjang Bidang
        int maxPartaiLength = 6; // Minimal panjang Partai
        
        for (DPR anggota : anggotaDPR) {
            maxIdLength = Math.max(maxIdLength, String.valueOf(anggota.getId()).length());
            maxNamaLength = Math.max(maxNamaLength, anggota.getNama().length());
            maxBidangLength = Math.max(maxBidangLength, anggota.getNamaBidang().length());
            maxPartaiLength = Math.max(maxPartaiLength, anggota.getNamaPartai().length());
        }

        System.out.print(" \n >>> Daftar Anggota DPR <<<\n");

        System.out.print(" +");
        for (int i = 0; i < maxIdLength + 2; i++) {
            System.out.print("-");
        }
        System.out.print("+");
        for (int i = 0; i < maxNamaLength + 2; i++) {
            System.out.print("-");
        }
        System.out.print("+");
        for (int i = 0; i < maxBidangLength + 2; i++) {
            System.out.print("-");
        }
        System.out.print("+");
        for (int i = 0; i < maxPartaiLength + 2; i++) {
            System.out.print("-");
        }
        System.out.println("+");

        System.out.printf(" | %-" + maxIdLength + "s | %-" + maxNamaLength + "s | %-" + maxBidangLength + "s | %-" + maxPartaiLength + "s |\n", "ID", "Nama", "Bidang", "Partai");

        System.out.print(" +");
        for (int i = 0; i < maxIdLength + 2; i++) {
            System.out.print("-");
        }
        System.out.print("+");
        for (int i = 0; i < maxNamaLength + 2; i++) {
            System.out.print("-");
        }
        System.out.print("+");
        for (int i = 0; i < maxBidangLength + 2; i++) {
            System.out.print("-");
        }
        System.out.print("+");
        for (int i = 0; i < maxPartaiLength + 2; i++) {
            System.out.print("-");
        }
        System.out.println("+");


        for (DPR anggota : anggotaDPR) {
            System.out.printf(" | %-" + maxIdLength + "d | %-" + maxNamaLength + "s | %-" + maxBidangLength + "s | %-" + maxPartaiLength + "s |\n", anggota.getId(), anggota.getNama(), anggota.getNamaBidang(), anggota.getNamaPartai());
        }

        System.out.print(" +");
        for (int i = 0; i < maxIdLength + 2; i++) {
            System.out.print("-");
        }
        System.out.print("+");
        for (int i = 0; i < maxNamaLength + 2; i++) {
            System.out.print("-");
        }
        System.out.print("+");
        for (int i = 0; i < maxBidangLength + 2; i++) {
            System.out.print("-");
        }
        System.out.print("+");
        for (int i = 0; i < maxPartaiLength + 2; i++) {
            System.out.print("-");
        }
        System.out.println("+");
    }


}

public class Main {
    public static void main(String[] args) {
        CRUD crud = new CRUD();
        Scanner scanner = new Scanner(System.in);
        int choice;

        //tambah 3 data
        crud.tambahAnggotaDPR("Anggota 1", "Pendidikan", "Partai A");
        crud.tambahAnggotaDPR("Anggota 2", "Pertahanan", "Partai B");
        crud.tambahAnggotaDPR("Anggota 3", "Pendidikan", "Partai C");

        do {
            System.out.println("\nDaftar Fitur: ");
            System.out.println("1. Tambah Anggota DPR");
            System.out.println("2. Hapus Anggota DPR");
            System.out.println("3. Edit Anggota DPR");
            System.out.println("4. Tampilkan Anggota DPR");
            System.out.println("5. Keluar");
            System.out.print("Pilihan Anda: ");
            choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice) {
                case 1:
                    System.out.print("Masukkan Nama: ");
                    // scanner.nextLine();
                    String nama = scanner.nextLine();
                    System.out.print("Masukkan Nama Bidang: ");
                    String namaBidang = scanner.nextLine();
                    System.out.print("Masukkan Nama Partai: ");
                    String namaPartai = scanner.nextLine();
                    crud.tambahAnggotaDPR(nama, namaBidang, namaPartai);
                    break;
                case 2:
                    crud.hapusAnggotaDPR();
                    break;
                case 3:
                    crud.editAnggotaDPR();
                    break;
                case 4:
                    crud.tampilkanAnggotaDPR();
                    break;
                case 5:
                    System.out.println("Program selesai.");
                    break;
                default:
                    System.out.println("Pilihan tidak valid.");
                    break;
            }
        } while (choice != 5);
    }
}
