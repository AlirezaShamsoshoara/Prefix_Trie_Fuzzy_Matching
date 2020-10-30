//
// Created by Alireza Shamsoshoara on 11/20/2018.
//
/* Includes ------------------------------------------------------------------*/
#include "prefix_trie.h"

/* Variables -----------------------------------------------------------------*/

/* Main Structure ------------------------------------------------------------*/
int main(int argc, char* argv[])
{
    cout << "Number of Input Arguments = " << argc - 1 << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]= " << argv[i] << endl;
    }

    if (argc == 3)
    {
        if (*argv[2] == 'A')
        {
            cout << "/***************************************/" << endl;
            cout << "Problem 1 - "<< *argv[2] << endl;
            char*   cpGenome = ReadGenome(argv[1]);
            cout << "strlen(cpGenome) " << strlen(cpGenome) << endl;
            Problem1A(argv[1], cpGenome);

        }
        else if (*argv[2] == 'B')
        {
            cout << "/***************************************/" << endl;
            cout << "Problem 1 - "<< *argv[2] << endl;
            char*   cpGenome = ReadGenome(argv[1]);
            Problem1B(argv[1], cpGenome);
        }
        else
        {
            cout << "The Input argument for the sub-problem is not Correct\n" <<
                 "Possible Values = {A,B} for Problem 1" << endl;
        }
    }
    else
    {
        cout << "Number of Input Arguments is not 2 !!! \n" <<
             "1) First one should be the address of the Dataset \n" <<
             "2) Second one is the Flag for specifying the Question which can be {A,B}  \n" << endl;
    }
    return 0;
}