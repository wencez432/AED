#include<iostream>
#include<iomanip>
#include <ctime>

using namespace std;

class Node{
private:
    int data;
    Node* link;

public:
    Node(int d){
        data = d;
        link = NULL;
    }

    Node(int d, Node* l){
        data = d;
        link = l;
    }

    int getData(){
        return data;
    }

    void setData(int d){
        data = d;
    }

    Node* getLink(){
        return link;
    }

    void setLink(Node* l){
        link = l;
    }
};

class List{
private:
    Node* head;

public:
    List(){
        head = NULL;
    }

    void insertSortList(){
        int x;
        do{
            cout << "Ingrese dato (termina con -1): ";  cin >> x;
            if(x != -1){
                insertSort(x);
            }
        }while(x != -1);
    }

    void insertSort(int x){
        Node* new_node = new Node(x);
        if(head == NULL)
            head = new_node;
        else{
            if(x < head->getData()){
                new_node->setLink(head);
                head = new_node;
            }
            else{
                Node *prev_node = NULL, *p = head;
                while((p != NULL) && (x > p->getData()))
                {
                    prev_node = p;
                    p = p->getLink();
                }
                new_node->setLink(prev_node->getLink());
                prev_node->setLink(new_node);
            }
        }
    }

    void create(){
        int x;
        do{
            cout << "Ingrese dato (termina con -1): ";  cin >> x;
            if(x != -1)
                head = new Node(x, head);
        }while(x != -1);
    }

    void create(int n){
        int x, i = 0;
        do{
            cout << "Ingrese dato " << i + 1 << ": ";  cin >> x;
            head = new Node(x, head);
            i++;
        }while(i != n);
    }

    void randList(int n){
        int x, i = 0;
        do{
            x = rand() % 51;    //(0 - 50)
            head = new Node(x, head);
            i++;
        }while(i != n);
    }

    void addHead(int x){
        head = new Node(x, head);
    }

    void addTail(int x){
        Node* tail = getTail();
        tail->setLink(new Node(x));
    }

    void insertNodeR(int d, int x){
        Node *new_node = new Node(x), *node = findNode(d);
        if(node != NULL){
            new_node->setLink(node->getLink());
            node->setLink(new_node);
        }
    }

    void insertNodeL(int d, int x){
        Node *new_node = new Node(x), *prev_node = NULL, *p = head;
        if(findNode(d) == head){
            addHead(x);
        }
        else{
            while((p->getLink() != NULL) && (p->getData() != d)){
                prev_node = p;
                p = p->getLink();
            }
            new_node->setLink(prev_node->getLink());
            prev_node->setLink(new_node);
        }
    }

    void removeNode(int d){
        Node *curr = head, *prev = NULL;
        bool found = false;
        while((curr != NULL) && !found){
            found = (curr->getData() == d);
            if(!found){
                prev = curr;
                curr = curr->getLink();
            }
        }
        if(curr != NULL){
            if(curr == head){
                head = curr->getLink();
            }
            else{
                prev->setLink(curr->getLink());
            }
            delete curr;
        }
    }

    void changeData_Of_Node(int d, int x){
        Node* n = findNode(d);
        n->setData(x);
    }

    Node* getTail(){
        Node* p = head;
        while(p->getLink() != NULL){
            p = p->getLink();
        }
        return p;
    }

    Node* getHead(){
        return head;
    }

    Node* findNode(int d){
        for(Node* i = head; i != NULL; i = i->getLink()){
            if(i->getData() == d)
                return i;
        }
        cout << "Nodo no encontrado!!\n";
        return NULL;
    }

    void print(){
        Node* n = head;
        int i = 1;
        while(n != NULL){
            cout << "Nodo" << setw(3) << to_string(i) << ": Direccion = " << n << ", Dato = " << setw(3) << n->getData() << ", Enlace = " << n->getLink() << endl;
            n = n->getLink();
            i++;
        }
    }

    int lenList(){
        Node* n = head;
        int N = 0;
        while(n != NULL){
            n = n->getLink();
            N++;
        }
        return N;
    }

    void separate(List *B, List *C){
        Node* n = head;
        while(n != NULL){
            int d = n->getData();
            if(d % 2 == 0){
                B->addHead(d);
            }
            else{
                C->addHead(d);
            }
            n = n->getLink();
        }
    }
};

int main(int argc, char const *argv[]){
    srand(time(NULL));
    List l;
    l.insertSortList();
    l.print();
    /*
    List A;
    A.create(5);
    //A.randList(20);
    cout << "Lista A de 5 nodos a leatorios (0 - 50)\n";
    A.print();
    A.changeData_Of_Node(4, 7);
    A.insertNodeR(7,10);
    A.removeNode(7);
    cout << "Lista A de 5 nodos a leatorios (0 - 50)\n";
    A.print();
    List B, C;
    A.separate(&B, &C);
    cout << "Lista B (pares)\n";
    B.print();
    cout << "Lista C (impares)\n";
    C.print();
    */
    return 0;
}
