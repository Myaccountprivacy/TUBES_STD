#include "bootcamp.h"

int main() {
    List L;
    createList(L);

    int pilihan;
    infoBootcamp dataB;
    infoSesi dataS;
    string judulCari, namaSesiCari;
    adrBootcamp pB;
    adrSesi pS;

    pilihan = -1;

    while (pilihan != 10){
        printMenu();
        cout << "Masukkan pilihan  :";
        cin >> pilihan;

        cout << "\n";

        if (pilihan == 1) {
            cout<<"--- Tambah Bootcamp ---\n";
            cout<<"(Gunakan underscore '_' sebagai pengganti spasi).\n";
            cout<<"Judul Bootcamp\t\t: "; cin>>dataB.judul;
            cout<<"Penyelenggara\t\t: "; cin>>dataB.penulis;
            cout<<"Kategori\t\t\t: "; cin>>dataB.kategori;
            pB = createElmBootcamp_103012400164(dataB);
            insertBootcamp_103012400164(L, pB);
            cout << "Bootcamp berhasil didaftarkan.\n";
        } else if (pilihan == 2) {
            cout<<"--- Tambah Sesi ---\n";
            cout<<"Masukkan ke Bootcamp (judul): "; cin>>judulCari;
            if (findBootcamp_103012400164(L, judulCari) != nullptr ) {
                cout<<"Nama sesi   : "; cin>>dataS.namaSesi;
                cout<<"Durasi (jam): "; cin>>dataS.durasi;
                cout<<"Kesulitan:  : "; cin>>dataS.kesulitan;
                pS= createElmSesi_103012400164(dataS);
                addSesiToBootcamp_103012400206(L, judulCari, pS); 
            } 
        } else if (pilihan == 3) {
            string judulCari2;
            cout << "--- Cari Bootcamp ---\n";
            cout << "Nama Bootcamp  :  "; cin >> judulCari2;
            adrBootcamp px=findBootcamp_103012400164(L,judulCari2);
            if (px!=nullptr) {
                cout<<"Ditemukan, "<<px->info.judul<<"\n";
            } else {
                cout<<"Bootcamp tidak ditemukan.\n";
            }    
        } else if (pilihan == 4){
            cout << "--- Tampilkan Sesi Bootcamp ---\n";
            string judulCari3;
            cout<<"Bootcamp yang dicari : "; cin>>judulCari3;
            showSesiByBootcamp_103012400164(L, judulCari3);    
        } else if (pilihan == 5){
            cout << "--- Hapus Bootcamp beserta sesinya ---\n";
            string judulCari4;
            cout << "Bootcamp yang dicari : "; cin >> judulCari4;
            deleteBootcamp_103012400206(L, judulCari4);      
        } else if (pilihan == 6){
            cout << "--- Hapus Sesi dari Bootcamp ---\n";
            string judulCari5;
            string cariSesi;
            cout << "Bootcamp yang dicari : "; cin >> judulCari5;
            cout << "Sesi yang ingin dihapus : "; cin >> cariSesi;
            deleteSesi_103012400206(L, judulCari5, cariSesi);        
        } else if (pilihan == 7){
            cout << "--- Tampilkan Semua Bootcamp beserta Sesinya ---\n";
            showAll(L);        
        } else if (pilihan == 8){
            cout<<"--- Hitung Jumlah Sesi dalam Bootcamp ---\n";
            string judulCari6;
            cout << "Nama Bootcamp : "; cin >> judulCari6;
            cout << countSesi_103012400164(L, judulCari6) << "\n";        
        } else if (pilihan == 9){
            cout<<"--- Tampilkan Bootcamp dengan Jumlah Sesi Terbanyak dan Tersedikit ---\n";
            showMinMaxSesi_103012400164(L);   
        }     
    }
}
