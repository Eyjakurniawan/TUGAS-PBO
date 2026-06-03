#include <iostream>
using namespace std;

//Encapsulation: Ayas
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