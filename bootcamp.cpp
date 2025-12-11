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

}

// (i) Menghitung jumlah sesi dalam bootcamp tertentu
int countSesi(List L, string judulBootcamp) {
    int tally=0;
    adrSesi p=L.first->firstSesi;
    while (p!=nullptr) {
        tally++;
        p=p->next;
    }
    return tally;
}

// (j) Menampilkan bootcamp dengan sesi terbanyak dan paling sedikit
void showMinMaxSesi(List L) {

}

// Helper untuk menu (k)
void printMenu() {

}