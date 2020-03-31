#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *pNext;

    Node(int x):data(x), pNext(NULL){}
};

class LinkedList{
private:
    Node *pRoot;
    int length;

public:
    LinkedList(): pRoot(NULL), length(0) {}

    bool find(int x, Node **&pNode) {
        pNode = &pRoot;
        while(*pNode) {
            if ((*pNode)->data==x) {
                return true;
            }
            pNode = &((*pNode)->pNext);
        }
        return 0;
    }


    void insert(int x) {
        // STEPS:
        // 1. Use the find function to check if the value `x` exists
        // 2. If it exists, then return 
        // 3. Else create a new node (using dinamic memory)
        // 4. Set pointers (Hint: you need to set 2 pointers)
        // 5. Increase the `length` attribute 
        
        Node **pNode;
        if (find(x, pNode) == true){
            return;
        }
        else{
            Node *pNew = new Node(x);
            Node *pCurr = pRoot;
            Node **pAux = &pRoot;
            
            if (length == 0){
                pRoot = pNew;
            }
            else{
                
                if(pRoot -> data > x){
    			    pNew -> pNext = pRoot;
			        pRoot = pNew;
                }
                
                else{
                
                while(pCurr){
                Node *aux = pCurr;
			    pCurr = pCurr -> pNext;
			    pAux = &((*pAux)->pNext);

			    if(pCurr == NULL && aux -> data < x){
				    (*&aux) -> pNext = pNew;
				}
				
				//Resolver a ordem
				if(aux -> data > x){ 
				    pNew -> pNext = pCurr;
				    aux -> pNext = pNew;
				}
    			}
                    
                }
            }
           
            length ++;
        }
    }

    void print() {
        Node *obj = pRoot;
        while(obj) {
            cout << obj->data << " ";
            obj=obj->pNext;
        }
        cout << endl;

    }

    void remove(int x) {
        // STEPS: 
        // 1. Use the find function to check if the value `x` exists
        // 2. If it does not exist, then return
        // 3. Else set pointers (Hint: just one pointer)
        // 4. Release memory 
        // 5. Decrease the `length` attribute 
        
        Node **pNode;
        if (find(x, pNode) == false){
            return;
        }
        else{
            Node *pCurr = pRoot;
                
                if(pRoot -> data == x){
    			    pRoot = pCurr -> pNext;
                }
                
                else{
                
                while(pCurr){

			    if(pCurr -> data == x){
                    *&pCurr = pCurr -> pNext;
				}

            	pCurr = pCurr -> pNext;

                }
                }
           
            length --;
    }
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    
    list.insert(0); //teste
    
    list.insert(10);

    list.insert(5);
    list.insert(-1);

    list.insert(1);
    list.insert(1000);
    list.print();

    list.remove(5);
    list.print();

    return 0;
}
