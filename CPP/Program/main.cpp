#include "DPR.cpp"

using namespace std;

int main(){

CRUD dpr;
    dpr.tambahAnggotaDPR("Rain", "Pendidikan", "Partai A");
    dpr.tambahAnggotaDPR("Techi", "Kesehatan", "Partai B");
    dpr.tambahAnggotaDPR("Sala", "Pertanian", "Partai C");


    int fitur;
    do{
        cout << "\n >>> Program CRUD Anggota DPR <<<" << endl;
        cout << "       1. Tambah Anggota DPR" << endl;
        cout << "       2. Tampilkan Anggota DPR" << endl;
        cout << "       3. Hapus Anggota DPR" << endl;
        cout << "       4. Edit Anggota DPR" << endl;
        cout << "       5. Keluar" << endl;
        cout << "\n>> Pilih nomor fitur : ";
        cin >> fitur;

        string nama, namaBidang, namaPartai;
        int id = dpr.getAnggotaDPR() + 1;
        switch (fitur)
        {
        case 1:
            cout << ">> Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << ">> Masukkan Namam Bidang: ";
            getline(cin, namaBidang);
            cout << ">> Masukkan Nama Partai: ";
            getline(cin, namaPartai);
            dpr.tambahAnggotaDPR(nama, namaBidang, namaPartai);
            
            cout << "\n <!> Data anggota DPR dengan ID " << id << " berhasil ditambahkan <!>" << endl;
            break;
        case 2:
            dpr.tampilkanAnggotaDPR();
            break;
        case 3:
            dpr.hapusAnggotaDPR();
            break;
        case 4: 
            dpr.editAnggotaDPR();
            break;
        case 5:
            cout << ">> Program selesai." << endl;
            break;
        default:
            cout << ">> Fitur tidak ditemukan" << endl;
            break;
        } 
    }while (fitur != 5);
        
    return 0;
}