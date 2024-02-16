#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    node* temp=head;
    int count;
    count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    node* temp = head;
    int size = length(head);
    char* str = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++) {
        str[i] = temp->letter;
        temp = temp->next;
    }
    str[size] = 0;
    return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* head = *pHead;
    node* insert = malloc(sizeof(node));
    insert->letter = c;
    insert->next = NULL;
    if (head == NULL) {
        *pHead = insert;
        return;
    }
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = insert;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    while((*pHead)!=NULL){
        node* head=*pHead;
        (*pHead)=(*pHead)->next;
        free(head);
    }
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}