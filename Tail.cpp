#include<iostream>

using namespace std;

class NodeTail{
    public:
    int e;
    NodeTail* next;

    NodeTail(int x){
        e = x;
        next = NULL;
    }
};

class Tail{
    private:
    NodeTail *start, *end;
    
    public:
    Tail(){
        start = end = NULL;
    }

    void inserta(int x){
        NodeTail* nuevo = new NodeTail(x);
        if(isEmpty()){
            start = nuevo;
        }
        else{
            (end->next) = nuevo;
        }
        end = nuevo;
    }

    int quitar(){
        if(isEmpty()){
            cout << "Cola vacia, no se puede extraer\n";
            return NULL;
        }
        else{
            cout << "Se elimino de la memoria el nodo: " << start;
            int x = (start->e);
            NodeTail* a = start;
            start = (start->next);
            if(start == NULL)
                end = NULL;
            delete a;
            return x;
        }
    }

    bool isEmpty(){
        return start == NULL;
    }

    NodeTail* getStart(){
        return start;
    }

    NodeTail* getEnd(){
        return end;
    }

    int getStartContent(){
        if(isEmpty()){
            cout << "Cola vacia\n";
            return NULL;
        }
        else{
            return start->e;
        }
    }

    int getEndContent(){
        if(isEmpty()){
            cout << "Cola vacia\n";
            return NULL;
        }
        else{
            return end->e;
        }
    }
};

void showTail(Tail &tail){
    int x;
    cout << "\nElementos de la Cola:\n";
    while(!tail.isEmpty()){
        cout << "Direccion frente: " << tail.getStart() << " . Elemento frente: " << tail.getStartContent() << endl;
        cout << "Direccion final: " << tail.getEnd() << " . Elemento final: " << tail.getEndContent() << endl;
        x = tail.quitar();
        cout << " . " << x << endl;
    }
    cout << "Direccion frente: " << tail.getStart() << " . Elemento frente: " << tail.getStartContent() << endl;
    cout << "Direccion final: " << tail.getEnd() << " . Elemento final: " << tail.getEndContent() << endl;
}

int main(int argc, char const *argv[]){
    
    return 0;
}
