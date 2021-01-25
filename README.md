# File-Word-Counter-Program
This repository contains code to read from any file, count the number of occurences of every word in the file, and then print out
this information. Data is stored using a hash table with separate chaining. Additionally, after storing all of the words in the hash
table, there is the additional option of printing out the words in least to greatest using lexicographical order by merging them all into
one giant linked list and then sorting it with merge sort. If the file is too large, the program will crash because of stack overflow due
to the recursive merge sort implementation. Examples of both sorting and non sorting are given.

main.c/example_output.c: outputs the occurences of words in ascending lexicographical order from a large section of a text file containing
the whole bible.

main2.c/example_output2.c: outputs the occurences of words in a non-ordered fashion of the entire bible text file. Sorting in this case is
not possible due to stack overflow as previously described above.
