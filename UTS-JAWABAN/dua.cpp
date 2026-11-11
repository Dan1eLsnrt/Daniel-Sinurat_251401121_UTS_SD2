#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node *next;
};

Node *head = NULL;

void tambahDiAwal(int nilai) {
    Node *baru = new Node();
    baru->nilai = nilai;
    baru->next = head;
    head = baru;
    cout << "Nilai " << nilai << " berhasil ditambahkan di awal.\n";
}

void tambahDiAkhir(int nilai) {
    Node *baru = new Node();
    baru->nilai = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Nilai " << nilai << " berhasil ditambahkan di akhir.\n";
}

void tambahSetelahNilai(int nilaiCari, int nilaiBaru) {
    Node *temp = head;

    while (temp != NULL && temp->nilai != nilaiCari) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Nilai " << nilaiCari << " tidak ditemukan dalam list.\n";
        return;
    }

    Node *baru = new Node();
    baru->nilai = nilaiBaru;
    baru->next = temp->next;
    temp->next = baru;

    cout << "Nilai " << nilaiBaru << " berhasil ditambahkan setelah nilai " << nilaiCari << ".\n";
}

void hapusBerdasarkanNilai(int nilai) {
    if (head == NULL) {
        cout << "Linked List kosong, tidak ada yang bisa dihapus.\n";
        return;
    }

    if (head->nilai == nilai) { 
        Node *hapus = head;
        head = head->next;
        delete hapus;
        cout << "Nilai " << nilai << " berhasil dihapus.\n";
        return;
    }

    Node *sebelum = head;
    while (sebelum->next != NULL && sebelum->next->nilai != nilai) {
        sebelum = sebelum->next;
    }

    if (sebelum->next == NULL) {
        cout << "Nilai " << nilai << " tidak ditemukan dalam list.\n";
        return;
    }

    Node *hapus = sebelum->next;
    sebelum->next = hapus->next;
    delete hapus;
    cout << "Nilai " << nilai << " berhasil dihapus.\n";
}

void tampilkanList() {
    cout << "Isi Linked List: ";
    if (head == NULL) {
        cout << "(kosong)\n";
        return;
    }

    Node *temp = head;
    while (temp != NULL) {
        cout << temp->nilai;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

void bersihkanList() {
    Node *temp = head;
    while (temp != NULL) {
        Node *hapus = temp;
        temp = temp->next;
        delete hapus;
    }
    head = NULL;
}

int main() {
    int pilihan;

    do {
        cout << "\n=== MENU SINGLE LINKED LIST ===\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan yang lolos\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int nilai;
            cout << "Masukkan nilai baru: ";
            cin >> nilai;
            tambahDiAwal(nilai);
            tampilkanList();

        } else if (pilihan == 2) {
            int nilai;
            cout << "Masukkan nilai baru: ";
            cin >> nilai;
            tambahDiAkhir(nilai);
            tampilkanList();

        } else if (pilihan == 3) {
            int nilaiCari, nilaiBaru;
            cout << "Masukkan nilai baru: ";
            cin >> nilaiBaru;
            cout << "Masukkan nilai yang ingin dicari: ";
            cin >> nilaiCari;
            tambahSetelahNilai(nilaiCari, nilaiBaru);
            tampilkanList();

        } else if (pilihan == 4) {
            int nilai;
            cout << "tampilkan yang lolos: ";
            cin >> nilai;
            hapusBerdasarkanNilai(nilai);
            tampilkanList();

        } else if (pilihan == 5) {
            cout << "tampilkan yang lolos: ";
            tampilkanList();

        } else if (pilihan == 0) {
            cout << "Keluar dari program.\n";

        } else {
            cout << "Pilihan tidak valid, coba lagi.\n";
        }

    } while (pilihan != 0);

    bersihkanList();
    return 0;
}