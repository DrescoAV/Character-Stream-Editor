#include "headers.h"

int main()
{
    // Creating a linked list for storing the "magic band"'s elements.
    List *banda = malloc(sizeof(List));
    banda->head = malloc(sizeof(Node));
    Node *newNode = malloc(sizeof(Node));
    banda->head->val = '\0';
    newNode->val = '#';
    newNode->next = NULL;
    banda->head->next = newNode;
    banda->head->prev = NULL;
    banda->finger = newNode;
    newNode->prev = banda->head;

    // Creating stacks for undo/redo operations and a queue for update operations.
    Stack *topUndo = NULL;
    Stack *topRedo = NULL;
    Queue *queue = createQueue();

    // Opening input and output files.
    FILE *fin;
    FILE *fout;
    fin = fopen("MagicBandIn.in", "r");
    fout = fopen("MagicBandOut.out", "w");

    // Inserting the number of operations.
    int no_of_operations;
    char gol_buffer;
    fscanf(fin, "%d", &no_of_operations);
    fscanf(fin, "%c", &gol_buffer);

    int i;
    char input[20];
    char newData;

    // Processing individual operations.
    for (i = 0; i < no_of_operations; i++)
    {
        fgets(input, 20, fin);
        input[strlen(input) - 1] = '\0';

        // Handling undo operations.
        if (strcmp(input, "UNDO") == 0)
            Undo(&topUndo, &topRedo, &(banda->finger));

        // Handling redo operations.
        if (strcmp(input, "REDO") == 0)
            Redo(&topUndo, &topRedo, &(banda->finger));

        // Handling display operations.
        if (strcmp(input, "SHOW") == 0)
            Show(fout, banda->head, banda->finger);

        if (strcmp(input, "SHOW_CURRENT") == 0)
            Show_Current(fout, banda->finger);

        // Executing operations from the queue.
        if (strcmp(input, "EXECUTE") == 0)
        {
            deQueue(queue, input);

            if (strcmp(input, "MOVE_RIGHT") == 0)
                Move_Right(&(banda->finger), &topUndo);

            if (strcmp(input, "MOVE_LEFT") == 0)
                Move_Left(&(banda->finger), banda->head, &topUndo);

            if (strncmp(input, "MOVE_LEFT_CHAR", 14) == 0)
            {
                newData = input[15];
                Move_Left_Char(fout, &(banda->finger), banda->head, newData);
            }

            if (strncmp(input, "MOVE_RIGHT_CHAR", 15) == 0)
            {
                newData = input[16];
                Move_Right_Char(&(banda->finger), newData);
            }

            if (strncmp(input, "WRITE", 5) == 0)
            {
                newData = input[6];
                Write(banda->finger, newData);
            }

            if (strncmp(input, "INSERT_RIGHT", 12) == 0)
            {
                newData = input[13];
                Insert_Right(&(banda->finger), newData);
            }

            if (strncmp(input, "INSERT_LEFT", 11) == 0)
            {
                newData = input[12];
                Insert_Left(fout, &(banda->finger), newData);
            }
        }
        // If the operation is not a display or undo/redo operation, enqueue it.
        else if (input[0] != 'S' && input[0] != 'R' && input[0] != 'U')
        {
            enQueue(queue, input);
        }
    }

    // Freeing dynamically allocated memory.
    deleteQueue(queue);
    stack_Delete(topUndo);
    stack_Delete(topRedo);
    list_delete(banda->head);
    free(banda);

    // Closing input/output files.
    fclose(fin);
    fclose(fout);

    return 0;
}
