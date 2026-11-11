#include <iostream>
using namespace std;

struct Node { int data; Node *kiri, *kanan; };

Node* buatNode(int d) {
    Node *n = new Node;
    n->data = d;
    n->kiri = n->kanan = NULL;   // node baru belum punya anak
    return n;
}

Node* insert(Node *akar, int d) {
    if (akar == NULL) return buatNode(d);                   
    if (d < akar->data) akar->kiri = insert(akar->kiri, d);
    else if (d > akar->data) akar->kanan = insert(akar->kanan, d);
    return akar;                                             
}


int minimum(Node *akar) { while (akar->kiri != NULL) akar = akar->kiri; return akar->data; }
int maksimum(Node *akar) { while (akar->kanan != NULL) akar = akar->kanan; return akar->data; }

void inOrder(Node *akar) {
    if (akar != NULL) {
        inOrder(akar->kiri);
        cout << akar->data << " ";
        inOrder(akar->kanan);
    }
}

int main() {
    Node *akar = NULL;
    int x;
    cout << "Masukkan angka (0 berhenti): ";
    while (cin >> x && x != 0) akar = insert(akar, x);   

    cout << "In-order : "; inOrder(akar); cout << endl;
    cout << "Min: " << minimum(akar) << endl;
    cout << "Max: " << maksimum(akar) << endl;
    return 0;
}