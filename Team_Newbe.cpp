#include <iostream>
#include <iomanip>
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
};

class StatusKelulusan {
public:
    string cekStatus(char nilai) {
        if (nilai == 'E' || nilai == 'e') {
            return "Wajib Mengulang";
        }
        return "Lulus";
    }
};

// eyja : Multiple inheritance dan tampilan KHS 
class CetakKHS : public MataKuliah, public StatusKelulusan {
public:
    void tampilkanSemuaData() {
        cout << "\n=============================================\n";
        cout << "         KARTU HASIL STUDI (KHS)             \n";
        cout << "=============================================\n";
        
        // getNama() dan getNim() berasal dari parent class yang dibuat Ayas lewat Class matakuliah yang dibuat oleh Raihan parsha
        cout << "Nama Mahasiswa : " << getNama() << endl;
        cout << "NIM            : " << getNim() << endl;
        cout << "---------------------------------------------\n";
        cout << "Daftar Mata Kuliah:\n";
        
        cout << left << setw(4)  << "No" 
             << setw(18) << "| Nama MK" 
             << setw(8)  << "| SKS" 
             << setw(10) << "| Nilai" 
             << "| Status" << endl;
        cout << "-------------------------------------------------------\n"; 

        // Mengakses data array yang ada di class MataKuliah
       for(int i = 0; i < jumlahMK; i++) {
            cout << left << setw(4)  << i+1
                 << "| " << setw(16) << namaMK[i]
                 << "| " << setw(6)  << sks[i]
                 << "| " << setw(8)  << nilaiHuruf[i]
                 << "| " << cekStatus(nilaiHuruf[i]) << endl;
        }
        cout << "=======================================================\n";
    }
};

// --- FUNGSI MAIN ---
int main() {
    // Tipe data diganti ke class anak yang baru (CetakKHS) agar bisa memakai semua fitur
    CetakKHS mk; 
    string namaInput, nimInput;
    int jmlInput;

    cout << "----- Program Pendataan Nilai -----\n";
    cout << "Masukkan Nama Mahasiswa : ";
    getline(cin, namaInput);
    cout << "Masukkan NIM Mahasiswa  : ";
    cin >> nimInput;

    // pakai fungsi dari Yazira
    mk.setData(namaInput, nimInput);

    cout << "Masukkan jumlah Mata Kuliah : ";
    cin >> jmlInput;
    cout << "\n==================================\n";

    // Menjalankan fungsi dari class Raihan Parsa
    mk.inputDataMK(jmlInput);

    // Menjalankan fungsi cetak tampilan yang ada di Multiple Inheritance
    mk.tampilkanSemuaData();

    return 0;
}