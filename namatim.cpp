#include <iostream>
using namespace std;

// Encapsulation: Ayas
class Mahasiswa {
    protected: //Agar bisa diwariskan
    string nama, nim;

    public: //Constructor untuk inisialisasi awal
    Mahasiswa(){
        nama = " ";
        nim = " ";
    }

    void setData (string namaMhs, string nimMhs){ //Setter
        nama = namaMhs;
        nim = nimMhs;
    }

    string getNama(){
        return nama;
    }
    string getNim(){
        return nim;
    }
};

// Inheritance : Raihan Parsa
class MataKuliah : public Mahasiswa {
    protected: // Dibuat protected agar nanti bisa diwariskan lagi ke Eyja
    string namaMK[10];
    int sks[10];
    char nilaiHuruf[10];
    float ipPerMK[10];
    int jumlahMK;

    public:
    MataKuliah() {
        jumlahMK = 0;
    }

    void inputDataMK(int jml) {
        jumlahMK = jml;
        for(int i = 0; i < jumlahMK; i++) {
            cout << "\nData Mata Kuliah ke-" << i+1 << endl;
            cout << "Nama MK (Tanpa Spasi) : "; cin >> namaMK[i];
            cout << "SKS                   : "; cin >> sks[i];
            cout << "Nilai (A/B/C/D/E)     : "; cin >> nilaiHuruf[i];

            // Menghitung IP per MK secara otomatis
            if(nilaiHuruf[i] == 'A' || nilaiHuruf[i] == 'a') ipPerMK[i] = 4.0;
            else if(nilaiHuruf[i] == 'B' || nilaiHuruf[i] == 'b') ipPerMK[i] = 3.0;
            else if(nilaiHuruf[i] == 'C' || nilaiHuruf[i] == 'c') ipPerMK[i] = 2.0;
            else if(nilaiHuruf[i] == 'D' || nilaiHuruf[i] == 'd') ipPerMK[i] = 1.0;
            else ipPerMK[i] = 0.0;
        }
    }

    // Method untuk membuktikan Inheritance kamu berjalan sukses
    void cetakDataSementara() {
        cout << "\n=======================================\n";
        cout << "       DATA SEMENTARA (INHERITANCE)    \n";
        cout << "=======================================\n";
        // getNama() dan getNim() bisa dipakai karena class ini mewarisi class Mahasiswa
        cout << "Nama Mahasiswa : " << getNama() << endl; 
        cout << "NIM            : " << getNim() << endl;
        cout << "---------------------------------------\n";
        cout << "Rincian Mata Kuliah:\n";
        for(int i = 0; i < jumlahMK; i++) {
            cout << i+1 << ". " << namaMK[i] 
                 << " | SKS: " << sks[i] 
                 << " | Nilai: " << nilaiHuruf[i] 
                 << " | IP MK: " << ipPerMK[i] << endl;
        }
        cout << "=======================================\n";
    }
};

// --- FUNGSI MAIN (Untuk ngetes kode kamu) ---
int main() {
    MataKuliah mk; //
    string namaInput, nimInput;
    int jmlInput;

    cout << "--- PROGRAM PENDATAAN NILAI ---\n";
    cout << "Masukkan Nama Mahasiswa : ";
    getline(cin, namaInput);
    cout << "Masukkan NIM Mahasiswa  : ";
    cin >> nimInput;

    // Memakai fungsi dari Yazira
    mk.setData(namaInput, nimInput);

    cout << "Masukkan jumlah Mata Kuliah : ";
    cin >> jmlInput;

    // Menjalankan fungsi dari class Raihan Parsa
    mk.inputDataMK(jmlInput);

    // Mencetak hasil
    mk.cetakDataSementara();

    return 0;
}