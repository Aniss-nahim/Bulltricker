#include    "../include/controle.h"

// stack management
void initStack(){
    _stackPieces = Malloc(Stack);
    _stackPieces->head = NULL;
}

Node * createNode(Piece *p){
    Node *nd = Malloc(Node);
    nd->piece = p;
    nd->next = NULL;
    return nd;
}

void pushToStack(Piece *p){
    Node * nd = createNode(p);
    nd->next = _stackPieces->head;
    _stackPieces->head = nd;
}

void makeStackEmpty(){
    Node *nd;
    while(_stackPieces->head){
        nd = _stackPieces->head;
        _stackPieces->head = _stackPieces->head->next;
        free(nd);
    }
}

bool isEmptyStack(){
    return (_stackPieces->head == NULL);
}

