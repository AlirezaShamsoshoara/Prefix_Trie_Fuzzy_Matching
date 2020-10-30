# Prefix Trie Fuzzy Matching
Data Structure: Prefix Trie with Fuzzy Matching


## Project Goal
This project aims to implement a Prefix Trie data structure to read and store genomic sequences of a given dataset. Then, the aim is to implement a fuzzy matching method to tolerate up to 1 mismatch and find the matching sequence between the dataset and the target. This problem is divided into two independent subproblems. However, the same class must be used in both problems. The structure of the class is as follow:

* It has a default constructor
* It has at least one custom constructor
* It has a search function to traverse the genome
* It has a copy constructor


### Problem A-:
In this problem, first, we generate random 36-mers genomic data from the genome sequence in different number of samples (5000, 50000, 100000). Nextm we use the search function to traverse the genome and find the match of each sample up to 1 mismatch in the whole sequence of genome and we print out the number of matches.

### Problem B-: 
In this problem,  we generate random 36-mers genomic data from the genome sequence in different number of samples (5000, 50000, 100000) but in this case, we consider 5% error rate per base for each character. And we store all of them in the prefix trie. Next, we use a search function to traverse through the genomic sequence and find all the matches up to 1 mismatch with the random data we saved in the prefix trie.

### Input Arguments: 
There are two input arguments for this project: i) the first one is the address of the file and ii) the second one chooses the subproblem {A or B}.

## Dataset:
Each read being a 50 character-long string of letters A,C,T, or G. -a reference genome consisting of 20 million base-pairs of letters A, C, T, or G.
An example of Fuzzy matching: An attempt to align the sequences [A C T G C T A] and [A C C T C T C] would be successful if a mismatch threshold of 3 was used, however a 2 character mismatch threshold would not yield a successful alignment.

## Required Libraries:
1) iostream
2) fstream
3) cmath
4) string
5) cstdlib
6) random

