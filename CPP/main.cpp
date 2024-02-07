#include "DPR.cpp"
#include <vector>

using namespace std;

int main(){
    int i, n = 0;
    int id;
    string nama, namaBidang, namaPartai;
    vector<DPR> anggota_dpr;

    // anggota saat ini
    anggota_dpr.push_back(DPR(1, "Rain", "Pendidikan", "Partai A"));
    anggota_dpr.push_back(DPR(2, "Techi", "Kesehatan", "Partai B"));
    anggota_dpr.push_back(DPR(3, "Sala", "Pertanian", "Partai C"));

    // print anggota saat ini
    cout << "Anggota DPR saat ini" << endl;
    for(i = 0; i < anggota_dpr.size(); i++){
        cout << anggota_dpr[i].get_id() << ". " << anggota_dpr[i].get_nama() << " | " << anggota_dpr[i].get_namaBidang() << " | " << anggota_dpr[i].get_namaPartai() << endl;
    }

    // menu fitur
    cout << "\n>> Menu Fitur <<" << endl;
    cout << "1. Tambah data Anggota DPR" << endl;
    cout << "2. Hapus data Anggota DPR" << endl;
    cout << "3. Edit data Anggota DPR" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih nomor fitur : ";

    int fitur;
    cin >> fitur;

    int find = 0;
    switch (fitur)
    {
        case 1:
            id = anggota_dpr.size() + 1;
            cout << "Masukan Nama, Bidang, dan Partai : ";
            cin >> nama >> namaBidang >> namaPartai;
            anggota_dpr.push_back(DPR(id, nama, namaBidang, namaPartai));
            break;
        case 2:
            cout << "Masukan ID anggota yang akan dihapus : ";
            cin >> id;
            for(i = 0; i < anggota_dpr.size(); i++){
                if(anggota_dpr[i].get_id() == id && find == 0){
                    anggota_dpr.erase(anggota_dpr.begin() + i);
                    find = 1;
                }
            }
            break;
        case 3:
            cout << "Masukan ID anggota yang akan diedit : ";
            cin >> id;
            for(i = 0; i < anggota_dpr.size(); i++){
                if(anggota_dpr[i].get_id() == id && find == 0){
                    cout << "Masukan ID, Nama, Bidang dan Partai baru : ";
                    cin >> id >> nama >> namaBidang >> namaPartai;
                    anggota_dpr[i].set_id(id);
                    anggota_dpr[i].set_nama(nama);
                    anggota_dpr[i].set_namaBidang(namaBidang);
                    anggota_dpr[i].set_namaPartai(namaPartai);
                    find = 1;
                }
            }
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "Fitur tidak ditemukan" << endl;
            return 0;
            break;
    }

    // print anggota terbaru
    cout << "\nAnggota DPR terbaru" << endl;
    for(i = 0; i < anggota_dpr.size(); i++){
        cout << anggota_dpr[i].get_id() << ". " << anggota_dpr[i].get_nama() << " | " << anggota_dpr[i].get_namaBidang() << " | " << anggota_dpr[i].get_namaPartai() << endl;
    }

    return 0;
}