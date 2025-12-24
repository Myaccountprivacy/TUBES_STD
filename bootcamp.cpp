#include "bootcamp.h"

// Membuat List kosong (List Parent)
void createList(List &L) {
/*
    I.S. Tidak ada list
    F.S. Terbentuk list kosong (elemen pertama = NIL)
*/
    L.first=nullptr;
}

// Membuat elemen baru (Alokasi memori)
adrBootcamp createElmBootcamp_103012400164(infoBootcamp data) {
/*
    I.S. Data terdefinisi
    F.S. Terbentuk elemen bootcamp baru dengan info = data, next = NIL, firstSesi = NIL
*/
    adrBootcamp p=new elmBootcamp;
    p->info=data;
    p->next=nullptr;
    p->firstSesi=nullptr;
    return p;
}
adrSesi createElmSesi_103012400164(infoSesi data) {
/*
    I.S. Data terdefinisi
    F.S. Terbentuk elemen sesi baru dengan info = data, next = NIL, prev = NIL
*/
    adrSesi p=new elmSesi;
    p->info=data;
    p->next=nullptr;
    p->prev=nullptr;
    return p;
}

// (a) Menambahkan bootcamp (Insert Parent)
void insertBootcamp_103012400164(List &L, adrBootcamp p) {
/*
    I.S. List mungkin kosong
    F.S. Elemen bootcamp baru ditambahkan di akhir list
*/
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
void addSesiToBootcamp_103012400206(List &L, string judulBootcamp, adrSesi C) {
/*
    I.S. List sesi suatu bootcamp mungkin kosong
    F.S. Elemen sesi C ditambahkan ke bootcamp dengan judul tertentu
*/
    adrBootcamp p=findBootcamp_103012400164(L,judulBootcamp);
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
adrBootcamp findBootcamp_103012400164(List L, string judul) {
/*
    I.S. List mungkin kosong
    F.S. Mengembalikan pointer ke elemen bootcamp dengan judul tertentu, atau NIL jika tidak ditemukan
*/
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
void showSesiByBootcamp_103012400164(List L, string judulBootcamp) {
/*
    I.S. List mungkin kosong
    F.S. Menampilkan seluruh sesi dari bootcamp dengan judul tertentu
*/
    adrBootcamp bc=findBootcamp_103012400164(L,judulBootcamp);
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
void deleteBootcamp_103012400206(List &L, string judulBootcamp) {
/*
    I.S. List mungkin kosong
    F.S. Bootcamp dengan judul tertentu beserta seluruh sesinya dihapus dari list
*/
    adrBootcamp p=findBootcamp_103012400164(L,judulBootcamp);
    if (p!=nullptr) {
        // Hapus semua sesi terlebih dahulu
        adrSesi q=p->firstSesi;
        while (q!=nullptr) {
            adrSesi temp=q;
            q=q->next;
            temp=nullptr;
        }
        // Hapus bootcamp
        if (p==L.first) {
            L.first=p->next;
        } else {
            adrBootcamp prev=L.first;
            while (prev->next!=p) {
                prev=prev->next;
            }
            prev->next=p->next;
        }
        p=nullptr;
    }
}

// (g) Menghapus sesi tertentu dari bootcamp tertentu
void deleteSesi_103012400206(List &L, string judulBootcamp, string namaSesi) {
/*
    I.S. List mungkin kosong
    F.S. Sesi dengan nama tertentu dihapus dari bootcamp dengan judul tertentu
*/
    adrBootcamp bc=findBootcamp_103012400164(L,judulBootcamp);
    if (bc!=nullptr) {
        adrSesi p=bc->firstSesi;
        while (p!=nullptr && p->info.namaSesi!=namaSesi) {
            p=p->next;
        }
        if (p!=nullptr) {
            // Hapus sesi dari linked list
            if (p->prev!=nullptr) {
                p->prev->next=p->next;
            } else {
                bc->firstSesi=p->next; // Jika sesi pertama yang dihapus
            }
            if (p->next!=nullptr) {
                p->next->prev=p->prev;
            }
            p=nullptr;
        }
    }
}

// (h) Menampilkan seluruh bootcamp beserta sesinya
void showAll(List L) {
/*
    I.S. List mungkin kosong
    F.S. Menampilkan seluruh bootcamp beserta sesi-sesinya
*/
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
int countSesi_103012400164(List L, string judulBootcamp) {
/*
    I.S. List mungkin kosong
    F.S. Mengembalikan jumlah sesi dalam bootcamp dengan judul tertentu
*/
    int tally=0;
    adrBootcamp bc=findBootcamp_103012400164(L, judulBootcamp);
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
void showMinMaxSesi_103012400164(List L) { // might be wrong
/*
    I.S. List mungkin kosong
    F.S. Menampilkan bootcamp dengan jumlah sesi terbanyak dan paling sedikit
*/
    //adrBootcamp bc=findBootcamp(L, L.first->info.judul);
    adrBootcamp p=L.first;
    adrBootcamp top=p;
    adrBootcamp bottom=p;
    while (p!=nullptr) {
        if (countSesi_103012400164(L,p->info.judul)>countSesi_103012400164(L,top->info.judul)) {
            top=p;
        }
        if (countSesi_103012400164(L,p->info.judul)<countSesi_103012400164(L,bottom->info.judul)) {
            bottom=p;
        }
        p=p->next;
    }
    cout<<"Bootcamp dengan sesi terbanyak: "<<top->info.judul<<" ("<<countSesi_103012400164(L, top->info.judul)<<" sesi)"<<endl;
    cout<<"Bootcamp dengan sesi paling sedikit: "<<bottom->info.judul<<" ("<<countSesi_103012400164(L, bottom->info.judul)<<" sesi)"<<endl;
}

// Helper untuk menu (k)
void printMenu() {
/*
    I.S. -
    F.S. Menampilkan menu pilihan kepada user
*/
    cout<<"=== Menu Bootcamp Management ===\n";
    cout<<"1. Tambah Bootcamp\n";
    cout<<"2. Tambah Sesi ke Bootcamp\n";
    cout<<"3. Cari Bootcamp berdasarkan judul\n";
    cout<<"4. Tampilkan Sesi berdasarkan Bootcamp\n";
    cout<<"5. Hapus Bootcamp beserta Sesi-nya\n";
    cout<<"6. Hapus Sesi dari Bootcamp\n";
    cout<<"7. Tampilkan Semua Bootcamp beserta Sesinya\n";
    cout<<"8. Hitung Jumlah Sesi dalam Bootcamp\n";
    cout<<"9. Tampilkan Bootcamp dengan Sesi Terbanyak dan Paling Sedikit\n";
    cout<<"10. Keluar\n";
}