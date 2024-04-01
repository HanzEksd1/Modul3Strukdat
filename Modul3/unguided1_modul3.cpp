#include <iostream>
#include <string>
using namespace std;

class dataMahasiswa
{
public:
    string nama;
    int usia;

    dataMahasiswa *next;

    dataMahasiswa(string nama, int usia)
    {
        this->nama = nama;
        this->usia = usia;
        next = nullptr;
    }
};

class linkedlist
{
private:
    dataMahasiswa *head;
    dataMahasiswa *tail;

public:
    linkedlist()
    {
        head = nullptr;
        tail = nullptr;
    }

    void datamasuk(string nama, int usia)
    {
        dataMahasiswa *newnode = new dataMahasiswa(nama, usia);
        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        newnode->next = nullptr;
        tail->next = newnode;
        tail = tail->next;
    }

    void updatenode(string oldname, string newname, int newage)
    {
        if (head == nullptr)
        {
            cout << "list kosong\n";
            return;
        }
        dataMahasiswa *current = head;
        while (current != nullptr && current->nama != oldname)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "data tidak ditemukan\n";
            return;
        }
        current->nama = newname;
        current->usia = newage;
        cout << "data telah diupdate\n";
    }
    void tampilandata()
    {
        if (head == nullptr)
        {
            cout << "list kosong\n";
            return;
        }
        dataMahasiswa *current = head;
        cout << endl;
        while (current != nullptr)
        {
            cout << current->nama << "[" << current->usia << "]" << endl;
            current = current->next;
        }
        cout << endl;
    }

    void hapusdata(string nama)
    {
        if (head == nullptr)
        {
            cout << "list kosong\n";
            return;
        }
        dataMahasiswa *current = head;
        dataMahasiswa *previous = nullptr;
        while (current != nullptr && current->nama != nama)
        {
            previous = current;
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "data tidak ditemukan\n";
            return;
        }
        if (current == head)
        {
            head = head->next;
        }
        else
        {
            previous->next = current->next;
        }
        if (current == tail)
        {
            tail = previous;
        }
        delete current;
    }
    void tambahnode(string nama, int usia, int pos)
    {
        dataMahasiswa *newnode = new dataMahasiswa(nama, usia);
        newnode->next = nullptr;
        dataMahasiswa *temp = head;
        int count = 1;
        while (temp != nullptr && count < pos)
        {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr)
        {
            cout << "posisi yang diminta tidak valid" << endl;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
};
int main()
{
    linkedlist list;
    int pilihan, usia, usiabaru, pos;
    string nama, namabaru;

    do
    {
        cout << "pilih" << endl;
        cout << "1. masukan data" << endl;
        cout << "2. tambahakan data" << endl;
        cout << "3. tampilkan data" << endl;
        cout << "4. ubah data" << endl;
        cout << "5. menghapus data" << endl;
        cout << "0. keluar" << endl;
        cout << "masukan pilihan :";
        cin >> pilihan;
        cin.ignore();
        cout << endl;
        switch (pilihan)
        {
        case 1:
            cout << "masukan nama :";
            cin >> nama;
            cout << "masukan usia :";
            cin >> usia;
            list.datamasuk(nama, usia);
            cout << endl;
            break;
        case 2:
            cout << "menambahkan data baru :";
            cout << "masukan nama :";
            cin >> namabaru;
            cout << "masukan usia: ";
            cin >> usia;
            cout << "masukan data ke posisi ke-";
            cin >> pos;
            if (pos < 1)
            {
                cout << "posisi yang diminta tidak valid" << endl;
            }
            else
            {
                list.tambahnode(namabaru, usia, pos);
            }
            break;
        case 3:
            list.tampilandata();
            cout << endl;
            break;
        case 4:
            cout << "masukan nama lama :";
            cin >> nama;
            cout << "masukan nama baru :";
            cin >> namabaru;
            cout << "masukan usia baru :";
            cin >> usiabaru;
            list.updatenode(nama, namabaru, usiabaru);
            cout << endl;
            break;
        case 5:
            cout << "masukan nama yang ingin dihapus :";
            cin >> nama;
            list.hapusdata(nama);
            cout << endl;
            break;
        default:
            break;
        }
    } while (pilihan != 0);
    return 0;
}