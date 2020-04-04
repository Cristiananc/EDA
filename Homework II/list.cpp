#include <iostream>
#include <initializer_list>
//Referências: https://www.cs.bu.edu/teaching/c/linked-list/delete/

using namespace std;

struct NotFoundException : public exception{
    const char * what () const throw(){
        return "Element not found";
    }
} exc;

template<typename T>
struct Node{
    T data;
    Node<T> *pNext;

    Node<T>(T x):data(x), pNext(NULL){}
};

template<typename T>
class LinkedList{
private:
    Node<T> *pRoot;
    int length;

public:
    LinkedList(): pRoot(NULL), length(0) {}
    
    LinkedList(initializer_list<T> mylist) : length(0), pRoot(NULL){
        for(auto elem : mylist){
            insert(elem);
        }
    }
    
    ~LinkedList(){
        Node<T> *obj = pRoot;
        Node<T> *p;
        while(obj) {
            p = obj;
            delete obj;
            obj = p -> pNext;
        }
        cout << "LinkedList was deleted." << endl;
    }

    bool find(T x, Node<T> **&pNode) {
        pNode = &pRoot;
        while(*pNode) {
            if ((*pNode)->data==x) {
                return true;
            }
            pNode = &((*pNode)->pNext);
        }
        return 0;
    }

//Tentativa de fazer o insert em ordem
    void insertOrdered(T x) {
        // STEPS:
        // 1. Use the find function to check if the value `x` exists
        // 2. If it exists, then return 
        // 3. Else create a new node (using dinamic memory)
        // 4. Set pointers (Hint: you need to set 2 pointers)
        // 5. Increase the `length` attribute 
        
        Node<T> **pNode;
        if (find(x, pNode) == true){
            return;
        }
        else{
            Node<T> *pNew = new Node<T> (x);
            Node<T> **pList = &pRoot;
            Node<T> *pCurr = *pList;


            //Se não há elemento na linked list, ele adiciona como primeiro
            if (length == 0){
                pRoot = pNew;
                length++;
                return;
            }
            
            //Adiciona antes de todos os demais
                if(pRoot -> data > x){
    			    pNew -> pNext = pRoot;
			        pRoot = pNew;
			        length++;
			        return;
                }
                    
                //Casos em que adiciono o elemento no meio ou fim
                else{
                
                while(pCurr -> pNext != NULL){
                pCurr = pCurr -> pNext;

                if(pCurr -> pNext == NULL){
                    pCurr -> pNext = pNew;
			        length++;
			        return;
                }
                if(pCurr -> pNext -> data > x && pCurr -> data < x){
                        pNew -> pNext = pCurr -> pNext;
                        pCurr -> pNext = pNew;
                        length++;
                        return;
            }
            }
		}
    }
           
 }

    void print() {
        Node<T> *obj = pRoot;
        while(obj) {
            cout << obj->data << " ";
            obj=obj->pNext;
        }
        cout << endl;

    }
    
    void insert(T x){
        Node<T> **pNode;
        
        if (find(x, pNode) == true){
            return;
        }
        //Posso usar aqui o pNode, já q já iteramos com ele por todos os elementos
            else{
            Node<T> *pNew = new Node<T>(x);
            pNew -> pNext = *pNode;
            *pNode = pNew;
        }
        
    }

    void remove(T x) {
        // STEPS: 
        // 1. Use the find function to check if the value `x` exists
        // 2. If it does not exist, then return
        // 3. Else set pointers (Hint: just one pointer)
        // 4. Release memory 
        // 5. Decrease the `length` attribute 
        
        Node<T> **pNode;
        if (find(x, pNode) == false) {
            throw exc;
        }
        else{
            Node<T> **pList = &pRoot;
            Node<T> *pCurr = *pList;
            Node<T> *Pprev = NULL;
            
            //Caso em que vamos apagar o único elemento da lista            
            if(length == 1){
                    pRoot = NULL;
                    length--;
                    return;
                }
                
                //O primeiro elemento
                if(pCurr -> data == x){
                    pRoot = pCurr -> pNext;
                    free(pCurr);
                    length--;
                    return;
                }
                
                else{
                while(pCurr){
                if(pCurr -> data == x){
                    Pprev -> pNext = pCurr -> pNext;
                    
                    free(pCurr);
                    length--;
                    return;
                }
                
                Pprev = pCurr;
                pCurr = pCurr -> pNext;
            }
            
        }
        }
    }
    
    class Iterator{
        private:
                Node<T> *pNode_it;
        public:
                Iterator(): pNode_it(NULL){}
                
                Iterator(Node<T> * p) : pNode_it(p){}
                
                bool operator != (Iterator it){
                    return pNode_it != it.pNode_it;
                }
                
                Iterator operator++(){
                        pNode_it = pNode_it -> pNext;
                }
                
                T& operator*(){
                    return pNode_it -> data;
                }
    };
                Iterator begin(){
                    return Iterator(pRoot);
                }
                
                Iterator end(){
                    return Iterator(NULL);
                }
};

int main() {
    
    cout << "Item A" << endl;
    LinkedList<int> list;
    list.insert(1);
    list.insert(0);
    list.insert(10);
    list.insert(5);
    list.insert(-1);
    list.insert(1);
    list.insert(1000);
    list.insert(-5);

    list.print();
    list.remove(1);
    list.remove(-5);
    list.remove(10);
    list.print();

    cout << "Item B:" << endl;
    LinkedList<int>  list1({1, 2, 10, 2, 3});
    list1.print ( ) ;
    
    
    cout << "Item D:" << endl;
    LinkedList<int> ilist({1,10,2});
    ilist.print();
    
    LinkedList<float> flist({1.2, 1.4, 100000});
    flist.print();
    
    LinkedList<std::string> slist({"one", "two", "three"});
    slist.print();
    
    cout << "Item E:" << endl;
    LinkedList<int> ilist2({1,2,10,2,3});
    LinkedList<int>::Iterator it;
    for (it = ilist2.begin(); it != ilist2.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Item F:" << endl;
    try{
        list.remove(109);
    } catch (const NotFoundException& e){
        cerr << e.what() << endl;    
    }
    
    
    return 0;
}
