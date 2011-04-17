#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/set.h"
#include "headers/set_node.h"

void add(struct Set * set, char * word) {
	/*create the node containing the word*/
	struct SetNode * item = (struct SetNode *) malloc(sizeof(struct SetNode));
	if (item == NULL)
		error();
	item -> word = word;
	item -> next = NULL;
	/*attach node to set:*/
	if (set -> size == 0) {/*set is empty*/
		set -> first = item;
		set -> size = 1;
	} else if (!isMember(set, word) ) {/*if acutal word is not member of set*/
		item -> next = set -> first;
		set -> first = item;
		set -> size = set -> size + 1;
	}
}

/*tests if structure set contains word*/
int isMember(struct Set * set, char * word) {
	/*setting local variable item to the beginning of set*/
	struct SetNode * item = set -> first;
	/*tests if word of actual node is the same as word passed by parameter*/
	if (strcmp(item -> word, word) == 0)
		return 1;
	/*looping while item has an ancestor*/
	while (item -> next != NULL) {
		item = item -> next;
		/*tests if word of actual node is the same as word passed by parameter*/
		if (strcmp(item -> word, word) == 0)
			return 1;
	}
	return 0;
}

/*prints set going through it node by node*/
void printSet(struct Set * set) {
	struct SetNode * item = set -> first;
	if (item -> word != NULL)
		printf("%s\n", item -> word);
	while (item -> next != NULL) {
		item = item -> next;
		if (item -> word != NULL)
			printf("%s\n", item -> word);
	}

}

/*prints set to file going through it node by node*/
void writeSetToFile(struct Set * set, FILE * file) {
	struct SetNode * item = set -> first;
	if (item -> word != NULL) {
		fprintf(file, item -> word);
		fprintf(file, "\n");
	}
	while (item -> next != NULL) {
		item = item -> next;
		if (item -> word != NULL) {
			fprintf(file, item -> word);
			fprintf(file, "\n");
		}
	}
}

/*deallocate set node by node also with associated word*/
void deallocateSet(struct Set *set) {
	struct SetNode *phead = set -> first;
	while (phead != NULL) {
		struct SetNode *temp = phead;
		phead = phead->next;
		temp -> next = NULL;
		free(temp -> word);
		free(temp);
	}
}