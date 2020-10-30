//
// Created by Alireza Shamsoshoara on 11/20/2018.
//

/* Includes ------------------------------------------------------------------*/
#include "prefix_trie.h"

/* Defines -------------------------------------------------------------------*/

/* Typedefs ------------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/

/* Structure -----------------------------------------------------------------*/

/* Function Prototypes -------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
char* ReadGenome(string Path)
{

    ifstream MyFile(Path);
    if (!MyFile)
    {
        cout << "Failed to open the file !!!" << endl;
        exit(1);
    }
    else
    {
        cout << "File is opened !!!" << endl;
        string sSkipFirst;
        char character;
        getline(MyFile,sSkipFirst);
        uint32_t u32CharSize = 0;
        while (MyFile.get(character))
        {
            if ((character == '\n') || (character == '\r'))
            {
                continue;
            }

            u32CharSize++;
        }
        cout << "u32CharSize = " << u32CharSize << endl;
        MyFile.clear();
        MyFile.seekg(0, ios::beg);
        char* cpChar;
        cpChar          = new char[u32CharSize];
        uint32_t index  = 0;
        getline(MyFile,sSkipFirst);
        while (MyFile.get(character))
        {
            if ((character == '\n') || (character == '\r'))
                continue;
            cpChar[index] = character;
            index++;
        }
        cpChar[index] = '\0';
        if (MyFile.is_open())
        {
            MyFile.close();
            cout << "File is closed !!!" << endl;
        }
        cout << "index = " <<index << endl;
        return cpChar;
    }
}

void Problem1A(string path, char* genome)
{
    cout << "Size of the Genome = " << strlen(genome) << endl;
    uint32_t u32RandGenTarg[NUMB_OF_SIM] = {5000, 50000, 100000};
    int16_t i16MismatchNumber;
    int32_t i32MismatchFound[3] = {0, 0, 0};

    for (uint8_t j = 0; j < NUMB_OF_SIM; j++)
    {
        cout << "*******************************************************" << endl;
        prefix_trie Trie(path, genome);
        cout << "Adding " << u32RandGenTarg[j] << " Random 36-Mers to the Prefix-Trie!" << endl;
        char** cppRandomTarg = RandomMers(u32RandGenTarg[j], Trie.cGenome, 0);
        for (int32_t i = 0; i < (int32_t)u32RandGenTarg[j]; i++)
        {
            Trie.Insert(cppRandomTarg[i]);
        }
        cout << "Size of the Trie = " << Trie.PrefixTrieSize(Trie.root) << " (Including the root node)" <<
         " for " << u32RandGenTarg[j] << " Random 36-Mers" << endl;
        cout << " +++++++ Searching +++++++ " << endl;
        for(int k = 0; k < (int)strlen(genome) - SEQ_LENGTH + 1; k++)
        {
            char Query[SEQ_LENGTH + 1];
            for (int8_t m = 0; m < SEQ_LENGTH; m++)
            {
                Query[m] = genome[m + k];
            }
            Query[SEQ_LENGTH] = '\0';
            i16MismatchNumber = Trie.FuzzyMatch(Trie.root, Query, MISMATCHONE);

            if (i16MismatchNumber == 0)
                i32MismatchFound[0]++;
            else if (i16MismatchNumber == 1)
                i32MismatchFound[1]++;
            else
                i32MismatchFound[2]++;
        }
        cout << "Number of 0 Mismatch = " << i32MismatchFound[0] << "\n" <<
                "Number of 1 Mismatch = " << i32MismatchFound[1] << "\n" <<
                "Number of 2 or more Mismatch = " << i32MismatchFound[2] << "\n" << endl;

        cout << "Number of Matches = " << i32MismatchFound[0] + i32MismatchFound[1] << endl;
    }
}

char** RandomMers(int32_t numb, char* genome, float Error)
{
    char cBaseA[3] = {'C', 'G', 'T'};
    char cBaseC[3] = {'A', 'G', 'T'};
    char cBaseG[3] = {'A', 'C', 'T'};
    char cBaseT[3] = {'A', 'C', 'G'};
    char** returnVal;
    returnVal = new char*[numb];
    for (int32_t i = 0; i < numb; i++)
    {
        returnVal[i] = new char[SEQ_LENGTH + 1];
        int iRandIndex = rand() % ((int)strlen(genome) - 1 - SEQ_LENGTH + 1);
        for(int8_t j = 0; j < SEQ_LENGTH; j++)
        {
            returnVal[i][j] = genome[j + iRandIndex];
            if (Error > 0)
            {
                float Probablity = ((float)rand() / (RAND_MAX));
                if (Probablity < Error)
                {
                    int Rand;
                    switch (returnVal[i][j])
                    {
                        case 'A':
                            Rand = rand() % (BASE-1);
                            returnVal[i][j] = cBaseA[Rand];
                            break;
                        case 'C':
                            Rand = rand() % (BASE-1);
                            returnVal[i][j] = cBaseC[Rand];
                            break;
                        case 'G':
                            Rand = rand() % (BASE-1);
                            returnVal[i][j] = cBaseG[Rand];
                            break;
                        case 'T':
                            Rand = rand() % (BASE-1);
                            returnVal[i][j] = cBaseT[Rand];
                            break;
                        default:
                        break;
                    }
                }
            }
        }
        returnVal[i][SEQ_LENGTH] = '\0';
    }
    return returnVal;
}

void Problem1B(string path, char* genome)
{
    cout << "Size of the Genome = " << strlen(genome) << endl;
    uint32_t u32RandGenTarg[NUMB_OF_SIM] = {5000, 50000, 100000};
    int16_t i16MismatchNumber;
    int32_t i32MismatchFound[3] = {0, 0, 0};

    for (uint8_t j = 0; j < NUMB_OF_SIM; j++)
    {
        cout << "*******************************************************" << endl;
        prefix_trie Trie(path, genome);
        cout << "Adding " << u32RandGenTarg[j] << " Random 36-Mers to the Prefix-Trie!" << endl;
        char** cppRandomTarg = RandomMers(u32RandGenTarg[j], Trie.cGenome, ERROR);
        for (int32_t i = 0; i < (int32_t)u32RandGenTarg[j]; i++)
        {
            Trie.Insert(cppRandomTarg[i]);
        }
        cout << "Size of the Trie = " << Trie.PrefixTrieSize(Trie.root) << " (Including the root node)" <<
             " for " << u32RandGenTarg[j] << " Random 36-Mers" << endl;
        cout << " +++++++ Searching +++++++ " << endl;
        for(int k = 0; k < (int)strlen(genome) - SEQ_LENGTH + 1; k++)
        {
            char Query[SEQ_LENGTH + 1];
            for (int8_t m = 0; m < SEQ_LENGTH; m++)
            {
                Query[m] = genome[m + k];
            }
            Query[SEQ_LENGTH] = '\0';
            i16MismatchNumber = Trie.FuzzyMatch(Trie.root, Query, MISMATCHONE);

            if (i16MismatchNumber == 0)
                i32MismatchFound[0]++;
            else if (i16MismatchNumber == 1)
                i32MismatchFound[1]++;
            else
                i32MismatchFound[2]++;
        }
        cout << "Number of 0 Mismatch = " << i32MismatchFound[0] << "\n" <<
                "Number of 1 Mismatch = " << i32MismatchFound[1] << "\n" <<
                "Number of 2 or more Mismatch = " << i32MismatchFound[2] << "\n" << endl;

        cout << "Number of Matches = " << i32MismatchFound[0] + i32MismatchFound[1] << endl;
    }
}


/* Class Implementation (PrefixNode)------------------------------------------*/
PrefixNode::PrefixNode()
{
    this->index = -1;
    for (int8_t i = 0; i < BASE; i++)
    {
        this->children[i] = nullptr;
    }
}

PrefixNode::~PrefixNode()
{

}

/* Class Implementation (prefix_trie)-----------------------------------------*/
prefix_trie::prefix_trie()
{
    root = (PrefixNode* ) calloc(1, sizeof(PrefixNode));
}

prefix_trie::prefix_trie(string Path, char* Genome)
{
    root            = (PrefixNode*) calloc(1, sizeof(PrefixNode));
    this->path      = Path;
    this->cGenome   = Genome;
}

prefix_trie::~prefix_trie()
{

}

prefix_trie::prefix_trie(prefix_trie &obj)
{
    this->root = obj.root;
    this->path = obj.path;
//    this->
}

int8_t prefix_trie::IndexReturn(char character)
{
    int8_t i8ReturnVal;
    switch (character)
    {
        case 'A':
            i8ReturnVal = 0;
            break;
        case 'C':
            i8ReturnVal = 1;
            break;
        case 'G':
            i8ReturnVal = 2;
            break;
        case 'T':
            i8ReturnVal = 3;
            break;
        default:
            i8ReturnVal = -1;
            cout << "Wrong Character" << endl;
            break;
    }
    return i8ReturnVal;
}

char prefix_trie::CharReturn(int8_t index)
{
    char cReturnChar;
    switch (index) {
        case 0:
            cReturnChar = 'A';
            break;
        case 1:
            cReturnChar = 'C';
            break;
        case 2:
            cReturnChar = 'G';
            break;
        case 3:
            cReturnChar = 'T';
            break;
        default:
            cReturnChar = '\0';
            cout << "Invalid Index" << endl;
            break;
    }
    return cReturnChar;
}

void prefix_trie::Insert(char *Sequence)
{
    this->root->index = -1;
    PrefixNode* tempNode = this->root;


    for (int8_t i = 0; i < (int8_t)strlen(Sequence); i++)
    {
        if (tempNode->children[IndexReturn(Sequence[i])] == nullptr)
        {
            tempNode->children[IndexReturn(Sequence[i])]            = (PrefixNode*)calloc(1, sizeof(PrefixNode));
            tempNode->children[IndexReturn(Sequence[i])]->index     = i;
            tempNode->children[IndexReturn(Sequence[i])]->parent    = tempNode;
        }
//        this->print(IndexReturn(Sequence[i]));
        tempNode = tempNode->children[IndexReturn(Sequence[i])];
//        cout << "index = " << tempNode->index << endl;
    }
//    cout << endl;
}

void prefix_trie::print(int8_t index)
{
    cout << this->CharReturn(index);
}

int32_t prefix_trie::PrefixTrieSize(PrefixNode* Node)
{
    if (Node == nullptr)
        return 0;
    else
        return PrefixTrieSize(Node->children[0]) + PrefixTrieSize(Node->children[1]) +
                PrefixTrieSize(Node->children[2]) + PrefixTrieSize(Node->children[3]) + 1;
}

int16_t prefix_trie::FuzzyMatch(PrefixNode* node, char* Query, int8_t Mismatch)
{
    auto i8Length = (int8_t)strlen(Query);
    int8_t i8MismatchNumber = 0;
//    PrefixNode* TempNode = node;
    Stack stack;

    StackValueStruct stackstruct;
    stackstruct.Mismatch    = i8MismatchNumber;
    stackstruct.StackNode   = node;
    stack.push(stackstruct);

    while (stack.top >= 0)
    {
        StackValueStruct Tempstackstruct = stack.pop();
        PrefixNode* TempNode    = Tempstackstruct.StackNode;
        i8MismatchNumber        = Tempstackstruct.Mismatch;

        int16_t i = TempNode->index + (int16_t)1;
        while(i < i8Length)
        {
            if (TempNode->children[IndexReturn(Query[i])] == nullptr)
            {
                i8MismatchNumber++;
                if (i8MismatchNumber > Mismatch)
                    break;
                for (int j = 0; j < BASE; j++)
                {
                    if (TempNode->children[j] != nullptr)
                    {
                        StackValueStruct Alternateleaf;
                        Alternateleaf.Mismatch  = i8MismatchNumber;
                        Alternateleaf.StackNode = TempNode->children[j];
                        stack.push(Alternateleaf);
                    }
                }
                Tempstackstruct     = stack.pop();
                TempNode            = Tempstackstruct.StackNode;
                i8MismatchNumber    = Tempstackstruct.Mismatch;
            }
            else
                TempNode = TempNode->children[IndexReturn(Query[i])];
            i++;
        }
    }

    if (i8MismatchNumber == 0)
        return ERROR_0MISMATCH;
    else if (i8MismatchNumber == 1)
        return ERROR_1MISMATCH;
    else
        return ERROR_2MISMATCH;
}
/* Class Implementation (STACK)-----------------------------------------------*/
Stack::Stack()
{
    top = -1;
}

bool Stack::push(StackValueStruct Val)
{
    if (top >= STACKSIZE - 1)
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        Stackvalue[++top] = Val;
        return true;
    }
}

StackValueStruct Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        StackValueStruct nullStruct;
        nullStruct.Mismatch     = 0;
        nullStruct.StackNode    = nullptr;
        return nullStruct;
    }
    else
    {
        StackValueStruct val = Stackvalue[top--];
        return val;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

