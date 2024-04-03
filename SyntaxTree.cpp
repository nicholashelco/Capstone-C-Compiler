//
// Created by nicho on 4/3/2024.
//

#include "SyntaxTree.h"

#include <utility>


SyntaxTree::SyntaxTree(){
    tree = std::vector<SynNode>();
}


SyntaxTree::~SyntaxTree() = default;


// Make an inner node with children locations l and r
void SyntaxTree::makeParent(int32_t type, int32_t l, int32_t r, std::string lex = ""){
    SynNode node;
    node.nodeType = type;
    node.left = l;
    node.right = r;
    node.lexeme = std::move(lex);
    tree.push_back(node);
}


// TODO: implement dummy nodes
// Makes a dummy node with children
void SyntaxTree::makeDummy() {}


// Makes a leaf node
void SyntaxTree::makeLeaf(int32_t type, std::string lex){
    SynNode node;
    node.nodeType = type;
    node.left =  -1;
    node.right = -1;
    node.lexeme = std::move(lex);
    tree.push_back(node);
}


int32_t SyntaxTree::size(){
    return (int32_t) tree.size();
}


bool SyntaxTree::isEmpty(){
    return tree.empty();
}
