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

        // Make an inner node with children locations l and r
        void makeParent(int32_t type, int32_t l, int32_t r, std::string lex);

        // Make a dummy node
        void makeDummy();

        // Make a leaf node
        void makeLeaf(int32_t type, std::string lex);

        int32_t size();

        bool isEmpty();


    private:

        std::vector<SynNode> tree;

};


#endif //CAPSTONE_C_COMPILER_SYNTAXTREE_H
