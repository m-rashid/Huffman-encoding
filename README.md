*******************************************************************************
                          HUFFMAN TREE ENCODIMG
*******************************************************************************
A compression algorithm to compress English language text files using a Huffman Encoder.  
  
GETTING STARTED  
  
Project files:  
  
HuffmanNode.h     -  Header file containing the structure for HuffmanNode class. This represents a Node in the Huffman tree.  
             
HuffmanNode.cpp   -  Defintions for the functions declared in the HuffmanNode header file

HuffmanTree.h     -  Header file containing the structure for HuffmanTree class. This represents the overall tree, and has functionality for constructing the tree, code table and data representation.  

HUffmanTree.cpp   -  Defintions for the functions declared in the HuffmanNode header file  

/Test/Test.cpp    -  Utility for performing unit tests on various code sections.  
driver.cpp        -  Driver file containing the main() method to run the program  
Makefile          -  Utility for compiling, linking and creating the executable  
  
  
COMPILING  
  
Navigate to the project source folder. Run 'make' in the terminal.  
An executable named 'huffencode' is created.  
  
  
RUNNING  
  
cd into the project folder. Execute the following command to run the program:  
  ./huffencode \<input file name\> \<output file name (prefix only)\>  
  
huffencode          - Name of the executable  
\<input file name\>   - Name of the input text file to be compressed using Huffman Tree encoding  
\<output file name\>  - Prefix of compressed file  
  
NOTE  
Two output files are created upon running the program:  
\<output_prefix\>.hdr : Mapping that gives a bit string code to each letter in the input file.  
<output_prefix>.bin : Overall bit string code for each letter  
  

To perform unit testing:  
  
cd into /Test  
run make  
An executable named 'test' is created.  
Execute './test' in the terminal to run the unit test program  

