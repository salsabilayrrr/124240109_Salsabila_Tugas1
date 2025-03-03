#include <iostream>
using namespace std;

int jumlah = 0; // Counter jumlah mahasiswa
struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};
Mahasiswa mhs[1000];

void tampilanmenu(int &menu) {
    cout << "\n============ Menu ============\n";
    cout << "1. Tampilan Data Mahasiswa" << endl;
    cout << "2. Cari berdasarkan NIM" << endl;
    cout << "3. Cari berdasarkan Nama" << endl;
    cout << "4. Sort IPK mahasiswa (asc) " << endl;
    cout << "5. Sort IPK mahasiswa (desc) " << endl;
    cout << "6. Exit" << endl;
    cout << "\nPilih menu: ";
    cin >> menu;
}

void tampilandatamhs() {
    cout << "\n=========== Data Mahasiswa ===========\n";
    cout << "\nSaat ini memiliki 10 mahasiswa.\n";
    for (int i = 0; i <10; i++) {
        cout << "\n\nMahasiswa ke-" << (i + 1) << ":\n";
        cout << "Nama : " << mhs[i].nama << ",   ";
        cout << "NIM : " << mhs[i].nim << ",  ";
        cout << "IPK : " << mhs[i].ipk;
    }
}

void tampilansearchNIM(){
    // Menggunakan sequential searche
    int cari;
    bool ketemu = false;
    cout << "Masukkan Nim yang ingin dicari : ";
    cin >> cari;

    for (int i = 0; i < jumlah; i++){
        if (cari == mhs[i].nim){
            ketemu = true;
        }
    }

    if (ketemu == 0){
        cout <<"\n------------NIM Tidak Ditemukan------------"<< endl;
    }
    else {
        cout <<"\n-------------Nim Ditemukan-------------"<< endl;
        for (int i = 0; i < jumlah; i++) {
            if (cari == mhs[i].nim) {
                cout << "Nama : " << mhs[i].nama << endl;
                cout << "NIM  : " << mhs[i].nim << endl;
                cout << "IPK  : " << mhs[i].ipk << endl;
            }
        }
    }
}
void tampilansearchNama(){
    //menggunakan binary search
    string cari;
    int awal =0, akhir=jumlah, tengah;
    int i;
    bool ketemu = false;

    cout <<"Masukkan nama mahasiswa yang dicari: ";
    cin >> cari;

        while((!ketemu) && awal <=akhir){
            tengah = (awal + akhir)/2;
            if(cari==mhs[tengah].nama){
                ketemu=true;
            }else{
                if(cari<mhs[tengah].nama){
                    akhir=tengah-1;
                }else{
                    awal =tengah+1;
                } if(cari>mhs[tengah].nama){   
                        awal =tengah +1;
                    }
            }
        }

        for(int i=0; i<jumlah; i++){
            if(cari == mhs[i].nama){
                ketemu = true;
            }
        }
         if(ketemu==0){ //untuk boolen 0 adalah false
                cout <<"\n-------------Nama Tidak Ditemukan-------------"<< endl;
            }else{
                cout <<"\n-------------Nama Ditemukan-------------"<< endl;
                for(int i =0; i<jumlah; i++){
                    if(cari==mhs[i].nama){
                        cout << "\nNama : " << mhs[i].nama << ",   ";
                        cout << "NIM : " << mhs[i].nim << ",  ";
                        cout << "IPK : " << mhs[i].ipk;
                    }
                }
            }
}

void tampilansortasc(int awal, int akhir){
    system("cls");
    //Menggunakan Quick Sort

    int low = awal, high = akhir;
    float pivot = mhs[(awal + akhir) / 2].ipk;
    int temp;

    do {
        while (mhs[low].ipk < pivot)
            low++;
        while (mhs[high].ipk > pivot)
            high--;

        if (low <= high) {
            swap(mhs[low], mhs[high]);
            low++;
            high--;
        }
    } while (low <= high);

    if (awal < high)
        tampilansortasc( awal, high);
    if (low < akhir)
        tampilansortasc(low, akhir);
}


void tampilansortascquick(){
    tampilansortasc(0, jumlah-1);
    cout<<"\n\nData mahasiswa : ";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nNama : " << mhs[i].nama << ",   ";
        cout << "NIM : " << mhs[i].nim << ",  ";
        cout << "IPK : " << mhs[i].ipk;
    }
    cout<<"\nMahasiswa telah diurutkan berdasarkan IPK (ascending)."<<endl;
}

void tampilansortdesc(){
    system("cls");
    //Menggunakan Bubble Sort
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - 1 - i; j++) {
            if (mhs[j].ipk < mhs[j + 1].ipk) {
            swap(mhs[j], mhs[j + 1]);
            }
        }
    }

    cout<<"\n\nData mahasiswa : ";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nNama : " << mhs[i].nama << ",   ";
        cout << "NIM : " << mhs[i].nim << ",  ";
        cout << "IPK : " << mhs[i].ipk;
    }
    cout<<"\nMahasiswa telah diurutkan berdasarkan IPK (descending)."<<endl;
    
}

void berhenti() {
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    system("cls");
}

int main() {
    int menu, search, sort;
    jumlah = 10; // Jumlah mahasiswa yang diinput
    mhs[0] = {"Budi", 124240001, 3.5};
    mhs[1] = {"Andi", 124240002, 3.6};
    mhs[2] = {"Caca", 124240003, 3.7};
    mhs[3] = {"Dedi", 124240004, 3.8};
    mhs[4] = {"Euis", 124240005, 3.9};
    mhs[5] = {"Feri", 124240006, 3.4};
    mhs[6] = {"Gina", 124240007, 3.3};
    mhs[7] = {"Hadi", 124240008, 3.2};
    mhs[8] = {"Ika",  124240009, 3.1};
    mhs[9] = {"Joko", 124240010, 3.0};

    do {
        tampilanmenu(menu);
        switch (menu) {
            case 1:
                tampilandatamhs(); 
                break;
            case 2:
                tampilansearchNIM();
                break;
            case 3:
                tampilansearchNama();
                break;
            case 4:
                tampilansortascquick();
                break;
            case 5:
                tampilansortdesc();
                break;
            case 6:
                cout << "\n========== EXIT PROGRAM ==========\n";
                return 0;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
        berhenti();
    } while (menu != 6);
}
