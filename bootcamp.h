#ifndef BOOTCAMP_H_INCLUDED
#define BOOTCAMP_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. DEFINISI TIPE DATA & POINTER
// ==========================================

// Pointer ke alamat memori
typedef struct elmBootcamp* adrBootcamp;
typedef struct elmSesi* adrSesi;

// Tipe data info (Isi data)
struct infoBootcamp {
    string judul;
    string penulis;    // atau penyelenggara
    string kategori;   // misal: Web, Mobile, Data
};

struct infoSesi {
    string namaSesi;
    int durasi;        // dalam jam
    string kesulitan;  // Beginner, Intermediate, Advanced
};

// ==========================================
// 2. STRUKTUR ELEMEN (NODE)
// ==========================================

// CHILD: Sesi Pelatihan (Doubly Linked List)
struct elmSesi {
    infoSesi info;
    adrSesi next;
    adrSesi prev;  // Pointer ke elemen sebelumnya (karena DLL)
};

// PARENT: Bootcamp (Singly Linked List)
struct elmBootcamp {
    infoBootcamp info;
    adrBootcamp next;     // Pointer ke bootcamp berikutnya
    adrSesi firstSesi;    // POINTER RELASI: Menunjuk ke sesi pertama (Child)
};

// LIST: Pengelola Utama
struct List {
    adrBootcamp first; // Head dari list bootcamp
};

// ==========================================
// 3. PRIMITIF DASAR (CREATE & STRUKTUR)
// ==========================================

// Membuat List kosong (List Parent)
void createList(List &L);

// Membuat elemen baru (Alokasi memori)
adrBootcamp createElmBootcamp(infoBootcamp data);
adrSesi createElmSesi(infoSesi data);

// (a) Menambahkan bootcamp (Insert Parent)
// Disarankan insertLast agar urutan sesuai input
void insertBootcamp(List &L, adrBootcamp P);

// (b) & (d) Menambahkan sesi ke bootcamp tertentu
// Fungsi ini sekaligus menghubungkan relasi
void addSesiToBootcamp(List &L, string judulBootcamp, adrSesi C);


// ==========================================
// 4. FUNGSIONALITAS UTAMA (SESUAI SOAL)
// ==========================================

// (c) Mencari bootcamp tertentu berdasarkan judul
adrBootcamp findBootcamp(List L, string judul);

// (e) Menampilkan sesi berdasarkan bootcamp tertentu
void showSesiByBootcamp(List L, string judulBootcamp);

// (f) Menghapus bootcamp beserta seluruh sesinya
// Hati-hati: Harus hapus semua anak dulu baru bapaknya
void deleteBootcamp(List &L, string judulBootcamp);

// (g) Menghapus sesi tertentu dari bootcamp tertentu
void deleteSesi(List &L, string judulBootcamp, string namaSesi);

// (h) Menampilkan seluruh bootcamp beserta sesinya
void showAll(List L);

// (i) Menghitung jumlah sesi dalam bootcamp tertentu
int countSesi(List L, string judulBootcamp);

// (j) Menampilkan bootcamp dengan sesi terbanyak dan paling sedikit
void showMinMaxSesi(List L);

// Helper untuk menu (k)
void printMenu();

#endif // BOOTCAMP_H_INCLUDED