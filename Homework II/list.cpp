#include <iostream>
#include <initializer_list>

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
    
    LinkedList(initializer_list<int> mylist) : length(0), pRoot(NULL){
        for(auto elem : mylist){
            insert(elem);
        }
    }
    
    ~LinkedList(){
        delete
        cout << "LinkedList "
    }

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


    void insertOrdered(int x) {
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
            Node **pCurr; 
            pCurr = &pRoot;

            //Se não há elemento na linked list, ele adiciona como primeiro
            if (length == 0){
                pRoot = pNew;
                length++;
                return;
            }
            else{
                
                //Adiciona antes de todos os demais
                if(pRoot -> data > x){
    			    pNew -> pNext = pRoot;
			        pRoot = pNew;
			        length++;
			        return;
                }
                
                else{
                
                bool addEnd = true;
                
                while(*pCurr){

			    if((*pCurr)->data < x &&  ((*pCurr)->pNext) -> data > x){
                    ((*pCurr) -> pNext) = pNew;
                    pNew -> pNext = *pCurr;
                    addEnd = false;
                }
                pCurr = &((*pNode)->pNext);
			    
                }
                
                //É o maior elemento da lista, é adicionado após todos
                if(addEnd){
			        pNew -> pNext = *pNode;
			        *pNode = pNew;
				}
                    
                }
            }
           
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
    
    void insert(int x){
        Node **pNode;
        
        if (find(x, pNode) == true){
            return;
        }
        //Chamada a função find, *pNode está no último nó se ele não encontra o elemento
        else{
            Node *pNew = new Node(x);
            pNew -> pNext = *pNode;
            *pNode = pNew;
        }
        
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
                while(pCurr!= NULL){
                    Node *aux = pCurr;
                     pCurr = pCurr -> pNext;   

                    if (pCurr -> data == x && pCurr -> pNext == NULL){
                        aux -> pNext = NULL;
                    }

                }
                
                }
           
            length --;
    }
    }
    
};

int main() {
    LinkedList list;
    list.insert(1);
    
    list.insert(0); 
    
    list.insert(10);

    list.insert(5);
    list.insert(-1);

    list.insert(1);
    list.insert(1000);
    list.insert(-5);
    list.insert(2);

    list.print();

    //list.remove(1000);
    list.print();
    
    LinkedList lista({1,2,3,5,6,8,4,4,5});
    LinkedList listinha({2,5,6,7,8,6,6,7,8});
    lista.print();
    listinha.print();

    return 0;
}
