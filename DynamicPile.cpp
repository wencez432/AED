#include<iostream>

using namespace std;

class NodePile{
    public:
        int e;
        NodePile* next;

        NodePile(int x){
            e = x;
            next = NULL;
        }
};

class DynamicPile{
    public:
        NodePile* top;

        DynamicPile(){
            top = NULL;
        }

        void push(int x){
            NodePile* nuevo = new NodePile(x);
            nuevo->next = top;
            top = nuevo;
        }

        int pop(){
            if(isEmpty()){
                cout << "Underflow\n";
                return NULL;
            }
            else{
                NodePile* n = top;
                int x = top->e;
                top = top->next;
                delete n;
                return x;
            }
        }

        bool isEmpty(){
            return top == NULL;
        }

        int getTop(){
            if(isEmpty()){
                cout << "Pila vacia\n";
                return NULL;
            }
            else    return top->e;
        }

        void clear(){
            NodePile* n;
            cout << "Limpiar Pila: " << endl;
            while(!isEmpty()){
                cout << "Direccion cima: " << top << " .Elemento en la cima: " << getTop() << endl;
                n = top;
                top = top->next;
                delete n;
            }
        }
};

void showPile(DynamicPile & pile){
    int x;
    cout << "\nElementos de la Pila:\n";
    while(!pile.isEmpty()){
        cout << "Direccion cima: " << pile.top << " .Elemento en la cima: " << pile.getTop() << endl;
        x = pile.pop();
        cout << x << endl;
    }
    cout << "Al terminar queda:\n";
    cout << "Direccion cima: " << pile.top << " .Elemento en la cima: " << pile.getTop() << endl;
}

void fillPile(DynamicPile &pile){
    int x, n;
    cout << "Cuantos elementos ingresara a la pila: ";
    cin >> n;
    cout << "Digite el elmento y luego pulse Enter\n";
    for(int i = 0; i < n; i++){
        cout << "Direccion cima: " << pile.top << " .Elemento en la cima: " << pile.getTop() << endl;
        cout << "indice " << i << ": ";
        cin >> x;
        pile.push(x);
    }
    cout << "Direccion cima: " << pile.top << " .Elemento en la cima: " << pile.getTop() << endl;
}

int main(int argc, char const *argv[]){
    DynamicPile pile;
    fillPile(pile);
    pile.clear();
    showPile(pile);
    return 0;
}
