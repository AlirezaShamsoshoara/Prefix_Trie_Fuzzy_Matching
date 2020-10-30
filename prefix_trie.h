//
// Created by Alireza Shamsoshoara on 11/20/2018.
//
/* Checking the Header Creation for preprocessor -----------------------------*/
#ifndef HW6_PREFIX_TRIE_H
#define HW6_PREFIX_TRIE_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>
#include <cstdlib>
#include <random>
using namespace std;

/* Externs -------------------------------------------------------------------*/

/* Defines -------------------------------------------------------------------*/
#define BASE            4
#define SEQ_LENGTH      36
#define STACKSIZE       100000
#define MISMATCHONE     1
#define ERROR_0MISMATCH 0
#define ERROR_1MISMATCH 1
#define ERROR_2MISMATCH 2
#define NUMB_OF_SIM     3
#define ERROR           0.05

/* Macros --------------------------------------------------------------------*/

/* Typedefs ------------------------------------------------------------------*/

/* Class Prototypes (Node) ---------------------------------------------------*/
class PrefixNode
{
public:
    PrefixNode();
    ~PrefixNode();
    PrefixNode*     parent;
    PrefixNode*     children[BASE];
    int16_t         index;
};

/* Structure -----------------------------------------------------------------*/
struct StackValueStruct{
    int8_t          Mismatch = 0;
    PrefixNode*     StackNode = nullptr;
};

/* Class Prototypes (prefix_trie)---------------------------------------------*/
class prefix_trie {
public:
    prefix_trie();
    ~prefix_trie();
    prefix_trie(prefix_trie &obj);
    explicit    prefix_trie(string, char*);


    void        Insert(char*);
    int8_t      IndexReturn(char);
    char        CharReturn(int8_t);
    int32_t     PrefixTrieSize(PrefixNode*);
    void        print(int8_t);
    int16_t     FuzzyMatch(PrefixNode*, char*, int8_t);

    PrefixNode* root;
    string      path;
    char*       cGenome;

private:

};

/* Class Prototypes (prefix_trie)---------------------------------------------*/
class Stack
{
public:
    Stack();
    bool                push(StackValueStruct);
    bool                isEmpty();
    StackValueStruct    pop();


    int32_t             top;
    StackValueStruct    Stackvalue[STACKSIZE];
};

/* Function Prototypes -------------------------------------------------------*/
char*   ReadGenome(string);
void    Problem1A(string, char*);
char**  RandomMers(int32_t, char*, float);
void    Problem1B(string, char*);

#endif //HW6_PREFIX_TRIE_H
