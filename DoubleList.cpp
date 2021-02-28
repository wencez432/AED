#include<iostream>
#include<iomanip>
#include <ctime>

using namespace std;

class DoubleNode{
private:
    int data;
    DoubleNode* RightLink;
    DoubleNode* LeftLink;

public:
    DoubleNode(int d){
        data = d;
        RightLink = LeftLink = NULL;
    }

    DoubleNode(int d, DoubleNode* l, DoubleNode* r){
        data = d;
        RightLink = r;
        LeftLink = l;
    }

    int getData(){
        return data;
    }

    void setData(int d){
        data = d;
    }

    DoubleNode* getRightLink(){
        return RightLink;
    }

    DoubleNode* getLeftLink(){
        return LeftLink;
    }

    void setRightLink(DoubleNode* r){
        RightLink = r;
    }

    void setLeftLink(DoubleNode* l){
        LeftLink = l;
    }

    void print(){
        cout << "Atras = " << setw(11) << LeftLink << ", Dato = " << setw(3) << data << ", Adelante = " << setw(11) << RightLink << endl;
    }
};

class DoubleList{
private:
    DoubleNode* head;
    DoubleNode* tail;

public:
    DoubleList(){
        head = tail = NULL;
    }

    void create(){
        int x;
        cout << "Ingrese dato (termina con -1): ";  cin >> x;
        if(x != -1){
            head = tail = new DoubleNode(x);
        }
        do{
            cout << "Ingrese dato (termina con -1): ";  cin >> x;
            if(x != -1){
                addHead(x);
            }
        }while(x != -1);
    }

    void addHead(int x){
        DoubleNode* new_node = new DoubleNode(x);
        new_node->setRightLink(head);
        if(head != NULL)
            head->setLeftLink(new_node);
        head = new_node;
    }

    void addTail(int x){
        DoubleNode* new_node = new DoubleNode(x);
        tail->setRightLink(new_node);
        new_node->setLeftLink(tail);
        tail = new_node;
    }

    void deleteNode(int d){
        DoubleNode *node = findNode(d);
        if(node == head){
            head = node->getRightLink();
            if(node->getRightLink() != NULL)
                node->getRightLink()->setLeftLink(NULL);
        }
        else{
            if(node->getRightLink() != NULL){
                node->getLeftLink()->setRightLink(node->getRightLink());
                node->getRightLink()->setLeftLink(node->getLeftLink());
            }
            else{
                tail = node->getLeftLink();
                node->getLeftLink()->setRightLink(NULL);
            }
        }
        delete node;
    }

    void insertNodeRight(int d, int x){
        DoubleNode *node = findNode(d);
        if(node != NULL){
            if(node == tail){
                addTail(x);
            }
            else{
                DoubleNode *later_node = node->getRightLink(), *new_node = new DoubleNode(x);
                new_node->setRightLink(later_node);
                new_node->setLeftLink(node);
                node->setRightLink(new_node);
                later_node->setLeftLink(new_node);
            }
        }
    }

    void insertNodeLeft(int d, int x){
        DoubleNode *node = findNode(d);
        if(node != NULL){
            if(node == head){
                addHead(x);
            }
            else{
                DoubleNode* prev_node = node->getLeftLink(), *new_node = new DoubleNode(x);
                new_node->setRightLink(node);
                new_node->setLeftLink(prev_node);
                node->setLeftLink(new_node);
                prev_node->setRightLink(new_node);
            }
        }
    }

    DoubleNode* getHead(){
        return head;
    }

    DoubleNode* getTail(){
        return tail;
    }

    DoubleNode* findNode(int d){
        for(DoubleNode* i = head; i != NULL; i = i->getRightLink()){
            if(i->getData() == d)
                return i;
        }
        return NULL;
    }

    void changeDataOf(int d, int x){
        DoubleNode* node = findNode(d);
        node->setData(x);
    }

    void print(){
        DoubleNode* n = head;
        int i = 1;
        while(n != NULL){
            cout << "Nodo" << setw(3) << to_string(i) << ": Atras = " << setw(11) << n->getLeftLink() << ", Direccion = " << n << ", Dato = " << setw(3) << n->getData() << ", Adelante = " << n->getRightLink() << endl;
            n = n->getRightLink();
            i++;
        }
    }
};

int main(int argc, char const *argv[]){
    DoubleList l;
    l.create();
    l.print();
    /*
    cout << "cambiando cola\n";
    l.addTail(7);
    l.insertNodeRight(7, 2);
    l.deleteNode(2);
    l.print();
    cout << "Cabeza y cola" << endl;
    l.getHead()->print();
    l.getTail()->print();
    l.insertNodeRight(1, 4);
    l.print();
    */
    return 0;
}
