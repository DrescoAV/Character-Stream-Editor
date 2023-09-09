#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Data is of type char.
typedef char Data;

// DataQ is a pointer to char used for a queue.
typedef char *DataQ;

// Element of the "magic band", a node for a list.
typedef struct Node
{
    Data val;
    struct Node *next, *prev;
} Node;

typedef struct Stack
{
    Node *val;
    struct Stack *next;
} Stack;

typedef struct NodeQ
{
    Data val[20];
    struct NodeQ *next;
} NodeQ;

typedef struct Queue
{
    NodeQ *front, *rear, *head;
} Queue;

// The magic band.
typedef struct List
{
    Node *head;
    Node *finger;
} List;

/*
 * stack_push() - Is responsible for pushing elements in a stack.
 * @arg1: Stack's top's address.
 * @arg2: Data to be pushed into the stack.
 */
void stack_push(Stack **top, Node *newData);

/*
 * stack_pop() - Extracts the top element from the stack.
 * @arg1: Pointer to stack top's address.
 */
Node *stack_pop(Stack **top);

/*
 * createQueue() - Allocates memory for a queue.
 * Returns pointer to the created queue.
 */
Queue *createQueue();

/*
 * enQueue() - Insert data at the rear of the queue.
 * @arg1: The queue to modify.
 * @arg2: Data to insert.
 */
void enQueue(Queue *q, DataQ input);

/*
 * deQueue() - Remove data from the front of the queue.
 * @arg1: The queue to modify.
 * @arg2: Data to extract from the queue.
 */
void deQueue(Queue *q, char *data);

/*
 * deleteQueue() - Deallocates memory used by the queue and its elements.
 * @arg1: The queue to be deleted.
 */
void deleteQueue(Queue *q);

/*
 * stack_Delete() - Deallocates memory used by the stack and its elements.
 * @arg1: The top of the stack to be deleted.
 */
void stack_Delete(Stack *top);

/*
 * list_delete() - Deallocates memory used by the linked list and its nodes.
 * @arg1: The head of the linked list to be deleted.
 */
void list_delete(Node *head);

/*
 * Move_Left() - Moves the finger to the left in the linked list.
 * @arg1: Pointer to the finger's position.
 * @arg2: The head of the linked list.
 * @arg3: Stack's top used for undo operations.
 */
void Move_Left(Node **finger, Node *head, Stack **topUndo);

/*
 * Move_Right() - Moves the finger's position to the right in the list.
 * @arg1: Pointer to the finger's position.
 * @arg2: Stack's top used for undo operations.
 */
void Move_Right(Node **finger, Stack **topUndo);

/*
 * Undo() - Reverts the last operation by moving to the previous position.
 * @arg1: Stack's top for undo operations.
 * @arg2: Stack's top for redo operations.
 * @arg3: Pointer to the finger's position.
 */
void Undo(Stack **topUndo, Stack **topRedo, Node **finger);

/*
 * Redo() - Reapplies the last undone operation.
 * @arg1: Stack's top for undo operations.
 * @arg2: Stack's top for redo operations.
 * @arg3: Pointer to the finger's position.
 */
void Redo(Stack **topUndo, Stack **topRedo, Node **finger);

/*
 * Move_Right_Char() - Moves the finger's position to the right until a specific value is found.
 * @arg1: Pointer to the finger's position.
 * @arg2: The value to be searched for.
 */
void Move_Right_Char(Node **finger, Data val_cautata);

/*
 * Move_Left_Char() - Moves the finger's position to the left until a specific value is found.
 * @arg1: File pointer for writing errors.
 * @arg2: Pointer to the finger's position.
 * @arg3: The head of the linked list.
 * @arg4: The value to be searched for.
 */
void Move_Left_Char(FILE *fout, Node **finger, Node *head, Data val_cautata);

/*
 * Write() - Modifies the data at the finger's position.
 * @arg1: Pointer to the finger's position.
 * @arg2: New data to be written.
 */
void Write(Node *finger, char newData);

/*
 * Insert_Right() - Inserts new data to the right of the finger's position.
 * @arg1: Pointer to the finger's position.
 * @arg2: New data to be inserted.
 */
void Insert_Right(Node **finger, Data newData);

/*
 * Insert_Left() - Inserts new data to the left of the finger's position.
 * @arg1: File pointer for writing errors.
 * @arg2: Pointer to the finger's position.
 * @arg3: New data to be inserted.
 */
void Insert_Left(FILE *fout, Node **finger, Data newData);

/*
 * Show() - Displays the linked list content, writing to a file.
 * @arg1: File pointer for writing.
 * @arg2: The head of the linked list.
 * @arg3: The finger's position.
 */
void Show(FILE *fout, Node *head, Node *finger);

/*
 * Show_Current() - Displays the data at the current finger's position, writing to a file.
 * @arg1: File pointer for writing.
 * @arg2: The finger's position.
 */
void Show_Current(FILE *fout, Node *finger);