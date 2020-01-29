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

bool readStackFromFile(){
    printf("readStackFromFile\n");
    FILE *file = fopen(FILE_GAME_STACK, "rb");
    if(!file)
        return false;
    if(feof(file))
        return true;
    initStack();
    Piece   piece;
    
    fread(  &piece , sizeof( Piece ), 1 , file);
    while ( !feof( file ) ){
        pushToStack(createPiece( piece.PlayerOwner, piece.kind));
        printf("%d,%c",piece.PlayerOwner, piece.kind);
        fread(  &piece , sizeof( Piece ), 1 , file);
        printf(" push");
   }
    fclose(file);
    return true;
}

bool writeStackdIntoFile(){
    printf("writeBoardIntoFile");
    FILE *file = fopen(FILE_GAME_STACK, "wb");
    if(isEmptyStack()){
        close(file);
        return true;    
    }else
    {
        /* code */
        Node * node = _stackPieces->head;
        while(node){
            printf(" pull ");
            fwrite(  node->piece , sizeof( Piece ), 1 , file);
            node = node->next;
        }
        makeStackEmpty();
        free(_stackPieces);
        fclose(file);
        return true;
    }
}