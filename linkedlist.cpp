#include<iostream>
using namespace std;

// 1. Memasukkan data mahasiswa kedalam list urut nim
// 2. Menghapus data mahasiswa dengan nim tertentu dari list
// 3. Mencetak data mahasiswa

struct Node{
    long int nim;
    string nama;
    string jurusan;
    Node* next;
};

Node* head = new Node;
void init(){
    head = NULL;
}
bool isEmpty(){
    return (head == NULL) ? true : false;
}
void autoPush(unsigned long int nim,string nama,string jurusan){
    Node* temp = new Node;
    Node* next = new Node;
    Node* prev = new Node;
    temp->nim = nim;
    temp->nama = nama;
    temp->jurusan = jurusan;
    if(isEmpty()){
        cout<<"Insert new head"<<endl;
        head = temp;
        head->next = NULL;
    } else {
        next = head->next;
        prev = head;
        if(next == NULL){
            if(head->nim > temp->nim){
                cout<<"Change head"<<endl;
                temp->next = head;
                head = temp;
            } else {
                cout<<"after new head"<<endl;
                head->next = temp;
                temp->next = NULL;
            }
        } else {
            if(head->nim > temp->nim){
                cout<<"Change head"<<endl;
                temp->next = head;
                head = temp;
            } else {
                cout<<"else"<<endl;
                while(temp->nim > next->nim && next->next != NULL){
                    cout<<"temp : "<<temp->nim<<" prev :  "<<prev->nim<<" next : "<<next->nim<<endl;
                    next = next->next;
                    prev = prev->next;
                }
                if(temp->nim < next->nim){
                    cout<<"Insert Middle"<<endl;
                    prev->next = temp;
                    temp->next = next;
                } else {
                    /*
                    ! jika memasukkan nim yang sama nim yang baru akan menjadi nim terakhir dan menghapus
                    ! semua data setelahnya
                    */
                    cout<<"insert : "<<temp->nim<<"next : "<<next->nim<<endl;
                    cout<<"Insert last"<<endl;
                    next->next = temp;
                }
            }
        }
    }
}
void print(){
    Node* temp = new Node;
    temp = head;
    while(temp->next != NULL){
        cout<<" | this : "<<temp<<" | NIM : "<<temp->nim<<" | Nama : "<<temp->nama<<" | Jurusan : "<<temp->jurusan<<" | next : "<<temp->next<<endl;
        temp = temp->next;
    }
    cout<<" | this : "<<temp<<" | NIM : "<<temp->nim<<" | Nama : "<<temp->nama<<" | Jurusan : "<<temp->jurusan<<" | next : "<<temp->next<<endl;
}
//TODO : make it better
/*
! BUG
! 1. menghapus nim yang tidak ada menyebabkan error (segmentation fault)
! 2. jika mencoba menghapus satu satu nya nim menyebabkan error (segmentation fault)
*/
void deleteNIM(long int nim){
    Node* prev = head;
    Node* temp = head->next;
    Node* next = temp->next;
    cout<<"before if else statement"<<endl;
    if(isEmpty()){
        cout<<"Data Kosong"<<endl;
    } else {
        cout<<"inside else"<<endl;
        if(head->nim == nim){
            if(head->next != NULL){
                delete head;
                head = temp; //! <--- error ?
            } else {
                delete head;
            }
        } else {
            while(next != NULL){
                if(temp->nim == nim){
                    delete temp;
                    prev->next = next;
                    break;
                } else {
                    prev = prev->next;
                    temp = temp->next;
                    next = next->next;
                }
            }
            cout<<"end while loop"<<endl;
            if(temp->nim = nim && next == NULL){
                delete temp;
                prev->next = NULL;
            } else {
                cout<<"NIM tidak ditemukan"<<endl;
            }
        }
    }
}
int countNode(){
    int count = 1;
    Node* temp = new Node;
    temp = head;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
int main(){
    init();
    while(true){
        int pilih;
        long int nim;
        string nama,jurusan;
        cout<<"1. Input data mahasiswa\n2. Hapus data mahasiswa by NIM\n3. Cetak semua data mahasiswa\n4. Exit"<<endl;
        cout<<"Pilih : ";
        cin>>pilih;
        cin.ignore();
        switch(pilih){
            case 1:
                cout<<"Masukkan NIM mahasiswa : ";
                cin>>nim;
                cin.ignore();
                cout<<"Masukkan nama mahasiswa : ";
                getline(cin,nama);
                cout<<"Masukkan jurusan mahasiswa : ";
                getline(cin,jurusan);
                autoPush(nim,nama,jurusan);
                break;
            case 2:
                cout<<"Masukkan NIM mahasiswa yang akan dihapus : ";
                cin>>nim;
                deleteNIM(nim);
                break;
            case 3:
                print();
                break;
            case 4:
                return false;
                break;
            default:
                cout<<"Input anda salah"<<endl;
                break;
        }
    }
}

// ============== abaikan ===================
/*
void deleteNIM(unsigned int nim){
    Node* temp = new Node;
    Node* prev = new Node;
    temp = head;
    prev = head;
    if(isEmpty()){
        cout<<"Empty"<<endl;
    } else {
        //* head fixed
        if(head->nim == nim){
            delete head;
            head = temp->next;
        } else {
            //* middle
            while(temp->next != NULL){
                if(temp->nim == nim){
                    delete temp;
                }
                temp = temp->next;
            }
            //* end
            if(temp->nim == nim){
                delete temp;
            }
        }
    }
}
*/
/*
void pushHead(unsigned long int nim,string nama,string jurusan){
    Node* temp = new Node;
    temp->nim = nim;
    temp->nama = nama;
    temp->jurusan = jurusan;
    if(isEmpty()){
        head = temp;
        head->next = NULL;
    } else {
        temp->next = head;
        head = temp;
    }
}
void pushBack(long int nim,string nama,string jurusan){
    Node* temp = new Node;
    Node* last = new Node;
    last = head;
    temp->nim = nim;
    temp->nama = nama;
    temp->jurusan = jurusan;
    temp->next = NULL;
    if(isEmpty()){
        head = temp;
        head->next = NULL;
    } else {
        while(last->next != NULL){
            last = last->next;
        }
        last->next = temp;
    }
}
*/