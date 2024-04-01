#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama_produk;
    int harga;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void tambahData(string nama_produk, int harga, int posisi) {
        if (posisi < 0 || posisi > size) {
            cout << "posisi tidak valid." << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->nama_produk = nama_produk;
        newNode->harga = harga;
        if (size == 0) {
            head = newNode;
            tail = newNode;
            newNode->prev = nullptr;
            newNode->next = nullptr;
        } else if (posisi == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            newNode->prev = nullptr;
        } else if (posisi == size) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            newNode->next = nullptr;
        } else {
            Node* temp = head;
            for (int i = 0; i < posisi - 1; i++) {
                temp = temp->next;
            }
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        size++;
        cout << "Data berhasil ditambahkan." << endl;
    }

    void hapusData(int posisi) {
        if (posisi < 0 || posisi >= size) {
            cout << "posisi tidak valid." << endl;
            return;
        }
        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else if (posisi == 0) {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        } else if (posisi == size - 1) {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        } else {
            Node* temp = head;
            for (int i = 0; i < posisi; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        size--;
        cout << "Data berhasil dihapus." << endl;
    }

    void updateData(string data_lama, string data_baru, int harga_baru) {
        Node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->nama_produk == data_lama) {
                temp->nama_produk = data_baru;
                temp->harga = harga_baru;
                found = true;
                cout << "Data berhasil diperbarui." << endl;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "Data tidak ditemukan." << endl;
        }
    }

    void tampilkanData() {
        if (size == 0) {
            cout << "Tidak ada data yang tersedia." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama_produk << " [ " << temp->harga << "]" << endl;
            temp = temp->next;
        }
    }

    void deleteAllData() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
        cout << "Seluruh data berhasil dihapus." << endl;
    }

    void deleteData(int posisi) {
        if (posisi <= 0 || posisi > size) {
            cout << "Posisi tidak valid." << endl;
            return;
        }
        Node* temp = head;
        if (posisi == 1) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else if (posisi == size) {
            temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            int i = 1;
            while (i < posisi) {
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
        size--;
        cout << "Data pada posisi " << posisi << " berhasil dihapus." << endl;
    };
};

int main() {
    DoubleLinkedList list;
    string nama_produk, data_lama, data_baru;
    int pilihan, posisi, harga, harga_baru;
    do {
        cout << endl;
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah data                 " << endl;
        cout << "2. Hapus data                  " << endl;
        cout << "3. Update data                 " << endl;
        cout << "4. Tambah data urutan tertentu " << endl;
        cout << "5. Hapus data urutan tertentu  " << endl;
        cout << "6. Hapus seluruh data          " << endl;
        cout << "7. Tampilkan data              " << endl;
        cout << "8. Exit                        " << endl;
        cout << "Masukan pilihan anda : ";
        cin >> pilihan;
        cin.ignore();
        cout << endl;
        switch (pilihan) {
            case 1:
                cout << "Masukan nama produk : ";
                cin >> nama_produk;
                cout << "Masukan harga produk : ";
                cin >> harga;
                cout << "Masukan posisi : ";
                cin >> posisi;
                list.tambahData(nama_produk, harga, posisi);
                break;
            case 2:
                cout << "Posisi list produk yang akan dihapus : ";
                cin >> posisi;
                list.hapusData(posisi);
                break;
            case 3:
                cout << "Nama produk lama : ";
                cin >> data_lama;
                cout << "Nama produk baru : ";
                cin >> data_baru;
                cout << "Harga baru : ";
                cin >> harga_baru;
                list.updateData(data_lama, data_baru, harga_baru);
                break;
            case 4:
                cout << "Masukan nama produk : ";
                cin >> nama_produk;
                cout << "Masukan harga produk : ";
                cin >> harga;
                cout << "Masukan posisi : ";
                cin >> posisi;
                list.tambahData(nama_produk, harga, posisi);
                break;
            case 5:
                cout << "Masukan posisi (mulai dari 1): ";
                cin >> posisi;
                list.deleteData(posisi);                                    
                break;
            case 6:
                list.deleteAllData();
                break; 
            case 7:
                list.tampilkanData();
                break;
        }
    } while (pilihan != 8);
    return 0;
}