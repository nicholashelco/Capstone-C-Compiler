//
// Created by nicho on 4/3/2024.
//

#ifndef CAPSTONE_C_COMPILER_SYNTAXTREE_H
#define CAPSTONE_C_COMPILER_SYNTAXTREE_H

#include <string>
#include <utility>
#include <vector>


struct SynNode{
    int32_t nodeType;
    int32_t left;
    int32_t right;
    std::string lexeme;
};


class SyntaxTree {

    public:

        SyntaxTree();

        ~SyntaxTree();

        // Returns a reference to node at a specified index of the tree vector
        SynNode* operator[](int32_t index);

        // Make an inner node with children locations l and r; returns this node's index in tree vector
        int makeNode(int32_t type, int32_t l, int32_t r);

        // Make new internal node r, then add n levels of dummy node children with r as the root
        void makeDummy(int32_t r, int32_t n);

        // Make a leaf node
        int makeLeaf(int32_t type, std::string lex);

        void printTree();

        int32_t size();

        bool isEmpty();


    private:

        std::vector<SynNode> tree;

};


#endif //CAPSTONE_C_COMPILER_SYNTAXTREE_H
