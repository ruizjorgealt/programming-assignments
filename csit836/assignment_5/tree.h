//JORGE A. RUIZ
//CSIT 836
//PROFESSOR KENT


#ifndef TREE_H
#define	TREE_H


struct PersonRec{
    char name[20];
    int bribe;
    PersonRec* lChild;
    PersonRec* rChild;
    
    PersonRec(char*, int, PersonRec*, PersonRec*); 
};



class CTree {
public:
    CTree();
    ~CTree();
    bool isEmpty();
    bool isFull();
    void Add();
    void View(); //VIEW NODES IN TREE
private:
    PersonRec* root;
//    PersonRec* Root();
//    void BuildRoot(char*, int);
    void AppendLeft(PersonRec*, char*, int);
    void AppendRight(PersonRec*, char*, int);
    void AddItem(PersonRec*&,  char*, int);
    void DisplayTree(PersonRec*);

};

#endif	/* CTREE_H */

