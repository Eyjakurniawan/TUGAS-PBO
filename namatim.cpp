#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 1. Encapsulation: Yazira
// =========================================================================
class Mahasiswa {
protected: 
    string nama, nim;

public: 
    // Constructor untuk inisialisasi awal
    Mahasiswa(){
        nama = " ";
        nim = " ";
    }

    void setData(string namaMhs, string nimMhs){ // Setter
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

// 2. Inheritance Dasar: Raihan Parsa
// =========================================================================
// Class ini dibuat berdiri sendiri agar bisa digabung di class Nilai
class MataKuliah {
protected: 
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

// 3. Multi-Inheritance & Main: Eyja
// =========================================================================
// DI SINI LETAK MULTIPLE INHERITANCE (Mewarisi Mahasiswa DAN MataKuliah)
class Nilai : public Mahasiswa, public MataKuliah {
private:
    float ipk;

public:
    Nilai() {
        ipk = 0.0;
    }

    // Mengolah data dari Mahasiswa dan MataKuliah untuk menghitung IPK otomatis
    void hitungIPK() {
        float totalBobot = 0;
        int totalSKS = 0;

        for(int i = 0; i < jumlahMK; i++) {
            totalBobot += (ipPerMK[i] * sks[i]);
            totalSKS += sks[i];
        }

        if (totalSKS > 0) {
            ipk = totalBobot / totalSKS;
        } else {
            ipk = 0.0;
        }
    }

    // Cetak KHS Akhir yang rapi
    void cetakKHS() {
        cout << "\n\n=========================================================\n";
        cout << "               KARTU HASIL STUDI (KHS)                   \n";
        cout << "=========================================================\n";
        cout << "Nama Mahasiswa : " << getNama() << endl; // Mengambil dari Mahasiswa
        cout << "NIM            : " << getNim() << endl;  // Mengambil dari Mahasiswa
        cout << "---------------------------------------------------------\n";
        cout << left << setw(20) << "Mata Kuliah" 
             << setw(10) << "SKS" 
             << setw(12) << "Nilai Huruf" 
             << "IP MK" << endl;
        cout << "---------------------------------------------------------\n";
        
        // Mengambil data array dari MataKuliah
        for(int i = 0; i < jumlahMK; i++) {
            cout << left << setw(20) << namaMK[i]
                 << setw(10) << sks[i]
                 << setw(12) << nilaiHuruf[i]
                 << fixed << setprecision(2) << ipPerMK[i] << endl;
        }
        cout << "---------------------------------------------------------\n";
        cout << "IPK GABUNGAN   : " << fixed << setprecision(2) << ipk << endl;
        cout << "=========================================================\n";
    }
};

// --- FUNGSI MAIN UTAMA ---
int main() {
    Nilai mhsNilai; // Menggunakan class Nilai yang memegang semua data
    string namaInput, nimInput;
    int jmlInput;

    cout << "===========================================\n";
    cout << "       PROGRAM PENDATAAN NILAI KAMPUS      \n";
    cout << "===========================================\n";
    cout << "Masukkan Nama Mahasiswa : ";
    getline(cin, namaInput);
    cout << "Masukkan NIM Mahasiswa  : ";
    cin >> nimInput;

    // Set data identitas mahasiswa (Fungsi Yazira)
    mhsNilai.setData(namaInput, nimInput);

    cout << "Masukkan jumlah Mata Kuliah : ";
    cin >> jmlInput;

    // Input data krs mata kuliah (Fungsi Raihan)
    mhsNilai.inputDataMK(jmlInput);

    // Proses hitung & cetak hasil akhir (Fungsi Eyja)
    mhsNilai.hitungIPK();
    mhsNilai.cetakKHS();

    return 0;
}