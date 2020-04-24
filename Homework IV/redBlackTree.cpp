#include <iostream>
#include <iomanip>

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
    
    Node* get_parent(Node* p){
        return (p -> parent);
    }
    
    Node* get_grandparent(){
        
    }
    
    Node* get_aunt(){
        
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
    
    void rotateRight(Node *&pRoot, Node *&p){
        Node *previous_left = p -> pChild[0];
        p -> pChild[0] = previous_left -> pChild[1];
        
        if (p -> pChild[0] != NULL){
            p -> pChild[0] -> parent = p;
        }
        previous_left -> parent = p -> parent;

        if (p -> parent == NULL){
            pRoot = previous_left;
        }
        else if (p == p -> parent -> pChild[0]){
            p -> parent -> pChild[0] = previous_left;
        }
        
        else p -> parent -> pChild[1] = previous_left;

        previous_left -> pChild[1] = p;
        p -> parent = previous_left;
    }
    
    void rotateLeft(Node *&pRoot, Node *&p){
        Node *previous_right = p -> pChild[1];
        p -> pChild[1] = previous_right -> pChild[0];
        
        previous_right -> parent = p -> parent;
        
        if (p -> pChild[1] != NULL){
            p -> pChild[1] -> parent = p;
        }
        
        if (p -> parent == NULL){
            pRoot = previous_right;
        }
        else if (p == p -> parent -> pChild[0]){
            p -> parent -> pChild[0] = previous_right;
        }
        else p -> parent -> pChild[1] = previous_right;
        
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
    bool find(int x, Node **&p, Node *&pParent) {
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
            cout<< p->data <<endl;
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
    bst.print();

    cout << "-----------------\n";
    bst.remove(4);
    bst.print();

    bst.remove(3);
    bst.print();

    bst.remove(6);
    bst.print();

    return 0;
}
