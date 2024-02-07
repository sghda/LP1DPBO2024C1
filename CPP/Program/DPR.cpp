#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DPR{
    private:
        int id;
        string nama, namaBidang, namaPartai;
    
    public:
        DPR(){
            this->id = 0;
            this->nama = "";
            this->namaBidang = "";
            this->namaPartai = "";
        }

        DPR(int id, string nama, string namaBidang, string namaPartai){
            this->id = id;
            this->nama = nama;
            this->namaBidang = namaBidang;
            this->namaPartai = namaPartai;
        }

        int get_id(){
            return this->id;
        }

        void set_id(int id){
            this->id = id;
        }

        string get_nama(){
            return this->nama;
        }

        void set_nama(string nama){
            this->nama = nama;
        }

        string get_namaBidang(){
            return this->namaBidang;
        }

        void set_namaBidang(string namaBidang){
            this->namaBidang = namaBidang;
        }

        string get_namaPartai(){
            return this->namaPartai;
        }

        void set_namaPartai(string namaPartai){
            this->namaPartai = namaPartai;
        }

        ~DPR(){
        }
};

class CRUD{
    private :
        vector<DPR> anggotaDPR;

    public :
        int getAnggotaDPR(){
            return anggotaDPR.size();
        }

        void tambahAnggotaDPR(const string& nama, const string& namaBidang, const string& namaPartai) {
            int id = anggotaDPR.size() + 1;
            anggotaDPR.push_back(DPR(id, nama, namaBidang, namaPartai));
        }
        
        void hapusAnggotaDPR() {
            int id;
            cout << "Masukkan ID anggota yang akan dihapus : ";
            cin >> id;
        
            int indexToDelete = -1, found = 0;
            for (size_t i = 0; i < anggotaDPR.size(); ++i) {
                if (anggotaDPR[i].get_id() == id && found == 0) {
                    indexToDelete = i;
                    found = 1;
                }
            }
        
            if (indexToDelete != -1) {
                anggotaDPR.erase(anggotaDPR.begin() + indexToDelete);
                cout << "<!> Data anggota DPR dengan ID " << id << " berhasil dihapus <!>" << endl;
            } else {
                cout << "<!> Data anggota DPR dengan ID " << id << " tidak ditemukan <!>" << endl;
            }
        }

        void editAnggotaDPR() {
            int id;
            cout << "Masukkan ID anggota yang akan diedit : ";
            cin >> id;
        
            int indexToEdit = -1, found = 0;
            for (size_t i = 0; i < anggotaDPR.size(); ++i) {
                if (anggotaDPR[i].get_id() == id && found == 0) {
                    indexToEdit = i;
                    found = 1;
                }
            }
        
            if (indexToEdit != -1) {
                string nama, namaBidang, namaPartai;
                cout << "Masukkan ID, Nama, Bidang dan Partai baru : ";
                cin >> id >> nama >> namaBidang >> namaPartai;
                anggotaDPR[indexToEdit].set_id(id);
                anggotaDPR[indexToEdit].set_nama(nama);
                anggotaDPR[indexToEdit].set_namaBidang(namaBidang);
                anggotaDPR[indexToEdit].set_namaPartai(namaPartai);
                cout << "<!> Data anggota DPR dengan ID " << id << " berhasil diedit <!>" << endl;
            } else {
                cout << "<!> Data anggota DPR dengan ID " << id << " tidak ditemukan <!>" << endl;
            }
        }

        void tampilkanAnggotaDPR() {
            cout << "Daftar Anggota DPR : " << endl;
            for (size_t i = 0; i < anggotaDPR.size(); ++i) {
                cout << "ID : " << anggotaDPR[i].get_id() << endl;
                cout << "Nama : " << anggotaDPR[i].get_nama() << endl;
                cout << "Bidang : " << anggotaDPR[i].get_namaBidang() << endl;
                cout << "Partai : " << anggotaDPR[i].get_namaPartai() << endl;
                cout << endl;
            }
        }

        ~CRUD(){
        }

};


