#include <stdio.h>
#include "linked_list.h"

void LinkedList::Init (int M, int b2){
	mem_allocation = malloc(M*sizeof(char));
	b = b2;
	fre_ptr = mem_allocation;
}

void LinkedList::Destroy (){
	
	free(mem_allocation);
}
 		 
int LinkedList::Insert (int key,char * value_ptr, int value_len){
	Node *n = fre_ptr;
	n->key = key;
	n->val_len = value_len;
	memcpy(n+1, value_ptr, val_len)
	//LinkedList *item = new LinkedList();
	fre_ptr += b;
	n -> next = NULL;
	
}

int LinkedList::Delete (int key){
	Node *n = new Node();
	delete node->key;
}

char* LinkedList::Lookup (int key){
	Node *n = new Node();
	
	return NULL;
}

void LinkedList::PrintList (){
	Node *n = new Node
	cout
}
