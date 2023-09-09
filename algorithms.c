#include "headers.h"

void Move_Right(Node **finger, Stack **topUndo)
{
    // Push the finger position into the stack for undo.
    stack_push(topUndo, *finger);

    // If there is no next element, it will create one and default value is "#".
    if ((*finger)->next == NULL)
    {
        Node *newNode = malloc(sizeof(Node));
        newNode->val = '#';
        newNode->next = NULL;
        newNode->prev = *finger;
        (*finger)->next = newNode;
        *finger = newNode;
    }
    else
        // If there is next element it will move the finger's position to it.
        *finger = (*finger)->next;
}

void Move_Left(Node **finger, Node *head, Stack **topUndo)
{
    // If there is space in the left side of the band, update the finger's position.
    if ((*finger)->prev != head)
    {
        // Push the finger position into the stack for undo.
        stack_push(topUndo, *finger);
        *finger = (*finger)->prev;
    }
}

void Undo(Stack **topUndo, Stack **topRedo, Node **finger)
{
    // Extract element from the undo stack to update the finger's position.
    Node *fingerUPDATE = stack_pop(topUndo);

    // Push the finger position into the stack for redo.
    stack_push(topRedo, *finger);

    // Update finger position.
    *finger = fingerUPDATE;
}

void Redo(Stack **topUndo, Stack **topRedo, Node **finger)
{
    // Extract element from the redo stack to update the finger's position.
    Node *fingerUPDATE = stack_pop(topRedo);

    // Push the finger position into the stack for undo.
    stack_push(topUndo, *finger);

    // Update finger position.
    *finger = fingerUPDATE;
}

void Move_Left_Char(FILE *fout, Node **finger, Node *head, Data val_cautata)
{
    // Copy finger's position into an aux.
    Node *aux = (*finger);

    // While there are elements in the left side search for the wanted value.
    while (aux != head)
    {
        // Update finger's position if there is the wanted value in the left side.
        if (aux->val == val_cautata)
        {
            *finger = aux;
            break;
        }
        aux = aux->prev;
    }

    // If the wanted value is not in the left side of the band, print error.
    if (aux == head)
    {
        fprintf(fout, "ERROR\n");
    }
}

void Move_Right_Char(Node **finger, Data val_cautata)
{
    // Copy finger's position into an aux.
    Node *aux = (*finger);

    // While there are elements in the right side search for the wanted value.
    while (aux != NULL)
    {
        // Update finger's position if there is the wanted value in the right side.
        if (aux->val == val_cautata)
        {
            *finger = aux;
            break;
        }
        *finger = aux;
        aux = aux->next;
    }

    // If the wanted value is not in the right side of the band, print error.
    if (aux == NULL)
    {
        Insert_Right(finger, '#');
    }
}

// Insert data.
void Write(Node *finger, Data newData)
{
    finger->val = newData;
}

void Insert_Left(FILE *fout, Node **finger, Data newData)
{
    // If in the left position is the band's margin print error.
    if ((*finger)->prev->prev == NULL)
    {
        fprintf(fout, "ERROR\n");
    }
    else
    {
        // Create new element for the band and place it to the left.
        Node *newNode = malloc(sizeof(Node));
        newNode->val = newData;
        newNode->next = *finger;
        newNode->prev = (*finger)->prev;
        (*finger)->prev->next = newNode;
        (*finger)->prev = newNode;
        *finger = newNode;
    }
}

void Insert_Right(Node **finger, Data newData)
{
    // Create new element for the band and place it to the right.
    Node *newNode = malloc(sizeof(Node));
    newNode->val = newData;
    newNode->next = (*finger)->next;
    newNode->prev = *finger;
    if ((*finger)->next != NULL)
        (*finger)->next->prev = newNode;
    (*finger)->next = newNode;
    *finger = newNode;
}

// Print band's elements.
void Show(FILE *fout, Node *head, Node *finger)
{
    Node *headaux = head;
    headaux = headaux->next;
    while (headaux != NULL)
    {
        // On the fingers position print the value like "|value|".
        if (headaux == finger)
        {
            fprintf(fout, "|");
        }
        fprintf(fout, "%c", headaux->val);
        if (headaux == finger)
        {
            fprintf(fout, "|");
        }
        headaux = headaux->next;
    }
    fprintf(fout, "\n");
}

// Print current element's value.
void Show_Current(FILE *fout, Node *finger)
{
    fprintf(fout, "%c\n", finger->val);
}