#include<iostream>
#include<iomanip>

using namespace std;

class CircularNode{
private:
    int data;
    CircularNode* link;

public:
    CircularNode(int d){
        data = d;
        link = this;
    }

    CircularNode(int d, CircularNode* l){
        data = d;
        link = l;
    }

    int getData(){
        return data;
    }

    void setData(int d){
        data = d;
    }

    CircularNode* getLink(){
        return link;
    }

    void setLink(CircularNode* l){
        link = l;
    }

    void print(){
        cout << "Dato = " << setw(3) << data << ", Enlace = " << link << endl;
    }
};

class CircularList{
private:
    CircularNode* access;

public:
    CircularList(){
        access = NULL;
    }

    void create(){
        int x;
        do{
            cout << "Ingrese dato (termina con -1): ";  cin >> x;
            if(x != -1){
                addAccess(x);
            }
        }while(x != -1);
    }

    void addAccess(int x){
        CircularNode* new_node = new CircularNode(x);
        if(access != NULL){
            new_node->setLink(access->getLink());
            access->setLink(new_node);
        }
        access = new_node;
    }

    void addPrevNode(int d, int x){
        CircularNode *n = access, *prev = NULL;
        do{
            prev = n;
            n = n->getLink();
        }while(n->getData() != d && n != access);
        if(n->getData() == d){
            CircularNode *new_node = new CircularNode(x);
            prev->setLink(new_node);
            new_node->setLink(n);
        }
    }

    void addNextNode(int d, int x){
        CircularNode* n = findNode(d);
        if(n != NULL){
            CircularNode *new_node = new CircularNode(x), *next_node = n->getLink();
            n->setLink(new_node);
            new_node->setLink(next_node);
        }
    }

    void changeDataOf(int d, int x){
        CircularNode* n = findNode(d);
        if(n != NULL){
            n->setData(x);
        }
    }

    void deleteNode(int d){
        CircularNode *i = access, *prev = NULL;
        do{
            prev = i;
            i = i->getLink();
        }while(i->getData() != d && i != access);
        if(i->getData() == d){
            if(i == access){
                access = access->getLink();
                prev->setLink(access);
            }
            else{
                prev->setLink(i->getLink());
            }
            delete i;
        }
    }

    CircularNode* findNode(int d){
        CircularNode *i = access;
        do{
            i = i->getLink();
        }while(i->getData() != d && i != access);
        if(i->getData() == d)
            return i;
        return NULL;
    }

    void print(){
        if(access != NULL){
            CircularNode* n = access;
            int i = 1;
            do{
                cout << "Nodo" << setw(3) << to_string(i) << ": Direccion = " << n << ", Dato = " << setw(3) << n->getData() << ", Siguiente = " << n->getLink() << endl;
                n = n->getLink();
                i++;
            }while(n != access);
        }
    }
};

int main(int argc, char const *argv[]){
    CircularList cl;
    cl.create();
    cl.print();
    cout << "Modificando lista\n";
    cl.deleteNode(5);
    cl.addNextNode(3, 8);
    cl.addPrevNode(8, 6);
    cl.changeDataOf(1, 7);
    cl.print();
    return 0;
}
