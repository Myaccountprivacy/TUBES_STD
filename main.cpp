#include "bootcamp.h"

int main() {
    List L;
    createList(L);

    int pilihan;
    infoBootcamp dataB;
    infoSesi dataS;
    string judulCari, namaSesiCari;
    adrBootcamp pB;
    adrSesi;

    pilihan = -1

    while (piloihan != 0){
        printMenu();
        cout << "Masukkan pilihan  :";
        cin >> pilihan;

        coutt << "\n";

        if (pilihan == 1){
            cout << "--- Tambah Bootcamp ---\n";
            cout << "(Gunakan underscore '_'pengganti spasi)\n ";
            cout << "Judul Bootcamp  :  "; cin >> dataB.judul
            cout << "Penyelenggara  :  "; cin >> dataB.penulis;
            cout << "Kategori  :  "; cin >> dataB.kategori;

            pB = createElmBootcamp_103012400164(dataB);
            insertBootcamp_103012400164(L, pB);
            cout << "Bootcamp berhasil didaftarkan. \n"
                
        } else if (pilihan == 2){
            cout << "--- Tambah Sesi ---\n";
            cout << "Masukkan ke Bootcamp (judul): "; cin >> judulCari;

            if (findBootcamp_103012400164(L))
            
        }
    }
}
