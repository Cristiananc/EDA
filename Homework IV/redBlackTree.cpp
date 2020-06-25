#include <iostream>
#include <iomanip>

//RBT not finished

using namespace std;

enum colors {black, red};

struct Node {
    int data;
    Node *pChild[2];
    Node *parent;
    enum colors color;

    Node(int x):data(x){
        pChild[0] = pChild[1] = nullptr;
        parent = nullptr;
        color = black;
    }
}; 

class BlackRedTree {
protected:
    Node *pRoot;

public:
    BlackRedTree():pRoot(nullptr) {}
    
    void swap_color(Node *p){
        if (p -> color == red) p -> color = black;
        else if (p -> color == black) p -> color = red;
    }
    
    Node* parent(Node* p){
        return (p -> parent);
    }
    
    Node* grandparent(Node* p){
        return parent(parent(p));
    }
    
    Node** aunt(Node** p, Node* pai){
        Node **aunt;
        Node **grandparent = &(pai -> parent);
        if (pai == (*grandparent) -> pChild[0]){
            aunt = &((*grandparent) -> pChild[1]);
        }
        else aunt = &((*grandparent) -> pChild[0]);
        return aunt;
    }

    bool find(int x) {
        Node **p;
        Node *pParent;
        return find(x, p, pParent);
    }

    void insert(int x) {
        Node **p;
        Node *pai;
        if (!find(x, p, pai)) {
            *p  = new Node(x);
            (*p) -> color = red; //Inserta com nó na cor vermelha
            (*p) -> parent = pai;
            //cout << (*p) -> parent << endl;
        }
        recolor(p, pai);
    }
    
    void recolor(Node **p, Node *pai){

        if ( pai == pRoot){
            pai -> color = black; //Caso 1
            return;
        }
        if (pai -> color == black) return; //Caso 2
        
        while(((*p) != pRoot) && ((*p) -> parent -> color != black)){
            Node *grandparent = pai -> parent;
            Node *uncle = nullptr;
            Node *pai = (*p) -> parent;
            
            if (pai == grandparent -> pChild[0]){
                uncle = grandparent -> pChild[1];
            }
            else uncle = grandparent -> pChild[0];
            //if (uncle == NULL && pai == grandparent -> pChild[1]){
            //    rotateLeft(grandparent);
            //    (*p) -> color = black;
            //    recolor(&grandparent, grandparent -> parent);
            //}
            
                if (uncle -> color == red){
                    uncle -> color = black;
                    pai -> color = black;
                    grandparent -> color = red;
                    recolor(&grandparent, grandparent -> parent);
                }
            
                else if (uncle -> color == black){
                //Left left case
                if((pai == grandparent -> pChild[0]) && ((*p) == pai -> pChild[0])){
                    rotateRight(grandparent);
                    swap_color(pai);        //segmentation fault
                    swap_color(grandparent);
                    recolor(p, (*p) -> parent);

                }
                // Left Right case
                else if((pai == grandparent -> pChild[0]) && ((*p) == pai -> pChild[1])){
                    rotateLeft((*p));
                    rotateRight(grandparent);
                    swap_color(*p);
                    swap_color(grandparent);
                    recolor(p, (*p) -> parent);
                }
                else if((pai == grandparent -> pChild[1]) && ((*p) == pai -> pChild[0])){
                    rotateRight((*p));
                    rotateLeft(grandparent);
                    swap_color(grandparent);
                    swap_color(*p);
                    recolor(p, (*p) -> parent);
                }
                
                //Right right case
                else if((pai == grandparent -> pChild[1]) && ((*p) == pai -> pChild[1])){
                    rotateLeft(grandparent);
                    swap_color(grandparent);
                    swap_color(pai);
                    recolor(p, (*p) -> parent);
                }
            
            } 
        }
    } 
    
    void RBinsert(int a){
        Node *y = nullptr;
        Node *x = pRoot;
        Node *z = new Node(a);
        
        while(x != nullptr){
            y = x;
            cout << "oiii" << endl;
            if ((z -> data) < (x -> data)){
                cout << "oii" << endl;
                x = x -> pChild[0];
            }
            else{
                x = x -> pChild[1];
            }
        }
        z -> parent = y;
        if (y == nullptr){
            pRoot = z;
            if((z -> data) < (y -> data)){
                y -> pChild[0] = z;
            }
            else{
                y -> pChild[1] = z;
            }
        }
        z -> color = red;
    }
    
    void rotateRight(Node *&p){
        Node *previous_left = p -> pChild[0];
        p -> pChild[0] = previous_left -> pChild[1];
        
        if (p -> pChild[0] != NULL){
            p -> pChild[0] -> parent = p;
        }
        previous_left -> parent = p -> parent;
        
        if (p == p -> parent -> pChild[1]){
            p -> parent -> pChild[1] = previous_left;
        }
        else if (p == p -> parent -> pChild[0]){
            p -> parent -> pChild[0] = previous_left;
        }
        
        else pRoot = previous_left;
        
        previous_left -> pChild[1] = p;
        p -> parent = previous_left;
    }
    
    void rotateLeft(Node *&p){
        Node *previous_right = p -> pChild[1];
        p -> pChild[1] = previous_right -> pChild[0];
        
        previous_right -> parent = p -> parent;
        
        if (p -> pChild[1] != NULL){
            p -> pChild[1] -> parent = p;
        }
        
        if (p == p -> parent -> pChild[1]){
            p -> parent -> pChild[1] = previous_right;

        }
        else if (p == p -> parent -> pChild[0]){
            p -> parent -> pChild[0] = previous_right;
        }
        else pRoot = previous_right;

        previous_right -> pChild[0] = p;
        p -> parent = previous_right;
    }
    
    void remove(int x) {
        Node **p;
        Node *pParent;
        if(find(x, p, pParent))
            remove(*p);
    }

    void print() {
        print(pRoot);
        cout << endl;
    }
    
private:
    bool find(int x, Node **&p, Node *&pParent){
        p = &pRoot;
        while(*p) { 
            if ((*p)->data==x) return true;
            pParent = *p;
            p = &((*p)->pChild[(*p)->data < x]);
        }
        return false;
    }

    void remove(Node *&p) {
        if (!p->pChild[0] || !p->pChild[1])
            p = p->pChild[p->pChild[1]!=nullptr];
        else {
            Node **succesor = &(p->pChild[1]);
            find_min(succesor);
            p->data = (*succesor)->data;
            remove(*succesor);
        }
    }

    void find_min(Node **&p) {
        while((*p)->pChild[0]){
            p = &((*p)->pChild[0]);
        }
    }

    void print(Node *p, int indent=0) {
        if (p) {
            print(p->pChild[1], indent+6);
            cout << setw(indent) << ' ';
            cout<< p->data << "cor:" << p -> color <<endl;
            print(p->pChild[0], indent+6);
        }
    }
};

int main() {
    BlackRedTree bst;
    bst.insert(6);
    bst.insert(4);
    bst.insert(7);
    bst.insert(2);
    bst.insert(5);
    bst.insert(1);
    bst.insert(3);
    bst.insert(8);
    bst.print();

    cout << "-----------------\n";
    bst.remove(4);
    //bst.print();

    bst.remove(3);
    //bst.print();

    bst.remove(6);
    //bst.print();

    return 0;
}
