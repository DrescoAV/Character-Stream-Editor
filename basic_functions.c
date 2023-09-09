#include "headers.h"

// Allocate memory for a new node in the stack and initialize it.
void stack_push(Stack **top, Node *newData)
{
    Stack *newNode = malloc(sizeof(Stack));
    newNode->val = newData;
    newNode->next = *top;
    *top = newNode;
}

Node *stack_pop(Stack **top)
{
    // If the stack isn't empty then extract the first element and return it.
    if ((*top) != NULL)
    {
        // Update stack top.
        Stack *temp = *top;
        Node *aux = temp->val;
        *top = (*top)->next;
        free(temp);
        return aux;
    }
    else
        // Return NULL if the stack is empty.
        return NULL;
}

// Delete all elements from the stack.
void stack_Delete(Stack *top)
{
    Stack *temp;
    while ((top) != NULL)
    {
        temp = top;
        top = (top)->next;
        free(temp);
    }
}

// Allocate memory for a queue and return a pointer to it.
Queue *createQueue()
{
    Queue *q;
    q = malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;
    q->front = q->rear = q->head = NULL;
    return q;
}

// Insert element in queue.
void enQueue(Queue *q, DataQ input)
{
    // Will be using a head for the queue to keep track of the beggining
    // because elements are not freed on dequeue.
    NodeQ *newNode = calloc(1, sizeof(NodeQ));
    strcpy(newNode->val, input);
    newNode->next = NULL;

    // If the queue is empty, move head to front.
    if (q->rear == NULL)
    {
        q->rear = newNode;
        q->head = q->rear;
    }
    else
    {
        // If the queue is not empty, insert element and move rear to it.
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }

    // If the queue is cleaned, front will move to rear.
    if (q->front == NULL)
    {
        q->front = q->rear;
    }
}

// Extract element from queue.
void deQueue(Queue *q, char *data)
{
    if (q->front != NULL)
    {
        strcpy(data, q->front->val);
        q->front = (q->front)->next;
    }
}

// Delete all elements from a queue, including the queue.
void deleteQueue(Queue *q)
{
    NodeQ *temp;
    while (q->head != NULL)
    {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
    free(q);
}

// Delete all elements from a list, including the list.
void list_delete(Node *head)
{
    Node *temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
