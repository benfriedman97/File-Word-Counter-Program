#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"
#include "linked_list.h"
#include <vld.h>

// gets rid of any punctation and uppercase letters
char* modifyWord(char* word);

int main(int argc, char** argv) {
	
	HASH_TABLE hTable = ht_create(1000);

	FILE* fpIn;
	fopen_s(&fpIn, "test.txt", "r");
	if (fpIn == NULL) {
		printf("Failed to open file\n");
		exit(1);
	}
	
	char word[50];
	int data;
	unsigned index;
	unsigned numberOfWords = 0;
	while (fscanf_s(fpIn, "%s", word, 50) != EOF) {
		numberOfWords++;
		modifyWord(word);
		if (ht_key_exists(hTable, word, &index, &data)) {
			ht_update_elemment(hTable, word, index, data + 1);
		}
		else {
			ht_insert(hTable, word, 1);
		}
	}

	NODE list = NULL;
	ht_combine_entries_into_one_list(hTable, &list);
	list_mergeSort_LTG(&list);
	list_print_head_to_tail(list);
	printf("\nNumber of words: %d\n\n", numberOfWords);
	ht_destroy(&hTable);
	list_destroy(&list);

	return 0;
}

char* modifyWord(char* word) {
	unsigned lastCharIndex = strlen(word) - 1;
	if (ispunct(word[lastCharIndex])) {
		word[lastCharIndex] = '\0';
	}
	for (char* p = word; *p; p++) {
		if (*p >= 65 && *p <= 90)
			*p += 32;
	}
	return word;
}
