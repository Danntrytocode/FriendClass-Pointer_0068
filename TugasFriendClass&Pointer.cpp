#include <iostream>
#include <cmath>
using namespace std;

// Forward declaration agar LayangLayang tahu ada class BelahKetupat
class BelahKetupat;

class LayangLayang {
private:
    double d1, d2;
    double sisi1, sisi2;

public:
    void inputData() {
        cout << "--- Input Layang-Layang ---" << endl;
        cout << "Diagonal 1 : "; cin >> d1;
        cout << "Diagonal 2 : "; cin >> d2;
        cout << "Sisi 1     : "; cin >> sisi1;
        cout << "Sisi 2     : "; cin >> sisi2;
    }

    double hitungLuas() {  
        return 0.5 * d1 * d2;  
    }  

    // Friend function untuk menghitung keliling (akses data private)
    friend void tampilkanKeliling(LayangLayang, BelahKetupat);
};

class BelahKetupat {
private:
    double d1, d2;
    double sisi;

public:
    void inputData() {
        cout << "\n--- Input Belah Ketupat ---" << endl;
        cout << "Diagonal 1 : "; cin >> d1;
        cout << "Diagonal 2 : "; cin >> d2;
        cout << "Sisi       : "; cin >> sisi;
    }

    double hitungLuas() {  
        return 0.5 * d1 * d2;  
    }  

    // Friend function yang sama dideklarasikan di sini juga
    friend void tampilkanKeliling(LayangLayang, BelahKetupat);
};

// Implementasi Friend Function
void tampilkanKeliling(LayangLayang l, BelahKetupat b) {
    double kelilingLayang = 2 * (l.sisi1 + l.sisi2);
    double kelilingBelah = 4 * b.sisi;

    cout << "\n--- Hasil Keliling ---" << endl;  
    cout << "Keliling Layang-Layang : " << kelilingLayang << endl;  
    cout << "Keliling Belah Ketupat : " << kelilingBelah << endl;
}

int main() {
    // Inisialisasi melalui Object
    LayangLayang ObjectLayang;
    BelahKetupat ObjectBelah;

    // Memanggil method input
    ObjectLayang.inputData();  
    ObjectBelah.inputData();  

    // Output Luas
    cout << "\n--- Hasil Luas ---" << endl;  
    cout << "Luas Layang-Layang     : " << ObjectLayang.hitungLuas() << endl;  
    cout << "Luas Belah Ketupat     : " << ObjectBelah.hitungLuas() << endl;  

    // Memanggil friend function menggunakan object sebagai parameter
    tampilkanKeliling(ObjectLayang, ObjectBelah);  

    return 0;
}