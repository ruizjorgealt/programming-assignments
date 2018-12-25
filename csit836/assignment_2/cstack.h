// Jorge A. Ruiz
// Professor Kent
// Computer Science 836
// Thursday, March 20, 2015
// Assignment 02

#ifndef CSTACK_H
#define	CSTACK_H

class CSTACK {
    
public:
    CSTACK();
    bool IsEmpty();
    bool IsFull();
    void Push(char);
    void Pop();
    char Top();
    
private:
    int top;
    char data[21];
    
};

#endif	/* CSTACK_H */

