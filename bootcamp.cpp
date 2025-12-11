#include "bootcamp.h"

// Membuat List kosong (List Parent)
void createList(List &L) {
    L.first=nullptr;
}

// Membuat elemen baru (Alokasi memori)
adrBootcamp createElmBootcamp(infoBootcamp data) {
    adrBootcamp p=new elmBootcamp;
    p->info=data;
    p->next=nullptr;
    p->firstSesi=nullptr;
    return p;
}
adrSesi createElmSesi(infoSesi data) {
    adrSesi p=new elmSesi;
    p->info=data;
    p->next=nullptr;
    p->prev=nullptr;
    return p;
}

// (a) Menambahkan bootcamp (Insert Parent)
void insertBootcamp(List &L, adrBootcamp p) {
    if (L.first==nullptr) {
        L.first=p;
    } else {
        adrBootcamp q=L.first;
        while (q->next!=nullptr) {
            q=q->next;
        }
        q->next=p;
    }
}

// (b) & (d) Menambahkan sesi ke bootcamp tertentu
void addSesiToBootcamp(List &L, string judulBootcamp, adrSesi C) {
    adrBootcamp p=findBootcamp(L,judulBootcamp);
    if (p!=nullptr) {
        if (p->firstSesi==nullptr) {
            p->firstSesi=C;
        } else {
            adrSesi q=p->firstSesi;
            while (q->next!=nullptr) {
                q=q->next;
            }
            q->next=C;
            C->prev=q;
        }
    }
}

// (c) Mencari bootcamp tertentu berdasarkan judul
adrBootcamp findBootcamp(List L, string judul) {
    adrBootcamp p=L.first;
    while (p!=nullptr) {
        if (p->info.judul==judul) {
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

// (e) Menampilkan sesi berdasarkan bootcamp tertentu
void showSesiByBootcamp(List L, string judulBootcamp) {
    adrBootcamp bc=findBootcamp(L,judulBootcamp);
    adrSesi p=bc->firstSesi;
    if (bc!=nullptr) {
        cout<<"Sesi pada bootcamp "<<judulBootcamp<<":\n";
        while (p!=nullptr) {
            cout<<"- "<<p->info.namaSesi<<" | Durasi: "<<p->info.durasi<<" jam | Kesulitan: "<<p->info.kesulitan<<"\n";
            p=p->next;
        }
    } else {
        cout<<"Bootcamp dengan nama "<<judulBootcamp<<" tidak ditemukan.\n";
    }
}

// (f) Menghapus bootcamp beserta seluruh sesinya
// Hati-hati: Harus hapus semua anak dulu baru bapaknya
void deleteBootcamp(List &L, string judulBootcamp) {
    
}

// (g) Menghapus sesi tertentu dari bootcamp tertentu
void deleteSesi(List &L, string judulBootcamp, string namaSesi) {

}

// (h) Menampilkan seluruh bootcamp beserta sesinya
void showAll(List L) {
    adrBootcamp p=L.first;
    while (p!=nullptr) {
        cout<<"Bootcamp: "<<p->info.judul<<" | Penyelenggara: "<<p->info.penulis<<" | Kategori: "<<p->info.kategori<<"\n";
        adrSesi q=p->firstSesi;
        if (q==nullptr) {
            cout<<"  (Tidak ada sesi)\n";
        } else {
            cout<<"  Sesi:\n";
            while (q!=nullptr) {
                cout<<"  - "<<q->info.namaSesi<<" | Durasi: "<<q->info.durasi<<" jam | Kesulitan: "<<q->info.kesulitan<<"\n";
                q=q->next;
            }
        }
        p=p->next;
    }
}

// (i) Menghitung jumlah sesi dalam bootcamp tertentu
int countSesi(List L, string judulBootcamp) {
    int tally=0;
    adrBootcamp bc=findBootcamp(L, judulBootcamp);
    adrSesi p=L.first->firstSesi;
    if (bc!=nullptr) {
        while (p!=nullptr) {
            tally++;
            p=p->next;
        }
    }
    return tally;
}

// (j) Menampilkan bootcamp dengan sesi terbanyak dan paling sedikit
void showMinMaxSesi(List L) { // might be wrong
    //adrBootcamp bc=findBootcamp(L, L.first->info.judul);
    adrBootcamp p=L.first;
    adrBootcamp top=p;
    adrBootcamp bottom=p;
    while (p!=nullptr) {
        if (countSesi(L,p->info.judul)>countSesi(L,top->info.judul)) {
            top=p;
        }
        if (countSesi(L,p->info.judul)<countSesi(L,bottom->info.judul)) {
            bottom=p;
        }
        p=p->next;
    }
    cout<<"Bootcamp dengan sesi terbanyak: "<<top->info.judul<<" ("<<countSesi(L, top->info.judul)<<" sesi)"<<endl;
    cout<<"Bootcamp dengan sesi paling sedikit: "<<bottom->info.judul<<" ("<<countSesi(L, bottom->info.judul)<<" sesi)"<<endl;
}

// Helper untuk menu (k)
void printMenu() {
    cout<<"=== Menu Bootcamp Management ===\n";
    cout<<"1. Tambah Bootcamp\n";
    cout<<"2. Tambah Sesi ke Bootcamp\n";
    cout<<"3. Cari Bootcamp berdasarkan judul\n";
    cout<<"4. Tampilkan Sesi berdasarkan Bootcamp\n";
    cout<<"5. Hapus Bootcamp beserta Sesi-nya\n";
    cout<<"6. Hapus Sesi dari Bootcamp\n";
    cout<<"7. Tampilkan Semua Bootcamp beserta Sesi-nya\n";
    cout<<"8. Hitung Jumlah Sesi dalam Bootcamp\n";
    cout<<"9. Tampilkan Bootcamp dengan Sesi Terbanyak dan Paling Sedikit\n";
    cout<<"10. Keluar\n";
}