//
// Created by nicho on 4/3/2024.
//

#include "SyntaxTree.h"
#include "YaccCode.tab.hpp"


SyntaxTree::SyntaxTree(){
    tree = std::vector<SynNode>();
}


SyntaxTree::~SyntaxTree() = default;


// Returns a reference to node at a specified index of the tree vector
SynNode* SyntaxTree::operator[](int32_t index){
    return &(tree[index]);
}


// Make an inner node with children locations l and r
int SyntaxTree::makeNode(int32_t type, int32_t l, int32_t r){
    SynNode node;
    node.nodeType = type;
    node.left = l;
    node.right = r;
    node.lexeme = "";
    tree.push_back(node);

    // return this node's index in the tree vector
    return tree.size()-1;
}


// Make new internal node r of type type, then add n levels of dummy node children with r as the root
void SyntaxTree::makeDummy(int32_t type, int32_t n) {

    // first, add the new internal node r
    SynNode r;
    r.nodeType = type;
    tree.push_back(r);

    // remember location of r as parent location
    int pLoc = tree.size()-1;

    // number of dummys is 2^n
    int nDummys = 2 << n;

    // alternate between adding left and right edges
    bool isLeft = true;

    // after every two nodes, parent location will increment
    int nodesAdded = 0;

    // for each new dummy node:
    for(int i=0; i<nDummys; i++){

        // create and push the dummy
        SynNode dum;
        dum.nodeType = yy::parser::token::DUMMY;
        tree.push_back(dum);
        int32_t dumLoc = tree.size();

        // add edge to this dummy's parent
        if(isLeft)
            tree[pLoc].left  = dumLoc;
        else
            tree[pLoc].right = dumLoc;

        isLeft = !isLeft;

        // Update parent location every three nodes
        nodesAdded++;
        if(nodesAdded % 2 == 0)
            pLoc++;
    }
}


// Makes a leaf node
int  SyntaxTree::makeLeaf(int32_t type, std::string lex =""){
    SynNode node;
    node.nodeType = type;
    node.left =  -1;
    node.right = -1;
    node.lexeme = std::move(lex);
    tree.push_back(node);

    // return this node's index in the tree vector
    return tree.size()-1;
}

// Prints a row for each node in the tree.
// From left-to-right, prints index, token type, left index, right index, lexeme.
void SyntaxTree::printTree(){

    int row = 0;

    for(const SynNode& N : tree){

        std::cout << row << ' ' << N.nodeType << ' ' << N.left << ' ' << N.right << ' ' << N.lexeme << std::endl;
        row++;
    }
}


int32_t SyntaxTree::size(){
    return (int32_t) tree.size();
}


bool SyntaxTree::isEmpty(){
    return tree.empty();
}
