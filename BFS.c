#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_ROW 7
#define MAX_COL 7

int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

typedef struct Node
{
    int x, y;
    struct Node *next;
}Node;

typedef struct
{
    Node* head, *tail;
}Queue;

typedef struct
{
    int x, y;
}Point;

void SetColor(int color);
void MakeGrid(int grid[MAX_ROW][MAX_COL]);
void initQueue (Queue* q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int x, int y);
Node* dequeue(Queue *q);
void DestroyQueue(Queue *q);
void DisplayPath(int grid[MAX_ROW][MAX_COL], int startX, int startY, int targetX, int targetY, Point path[MAX_ROW * MAX_COL], int length, int visited[MAX_ROW][MAX_COL]);
void BFS (int grid[MAX_ROW][MAX_COL], int startX, int startY, int targetX, int targetY);

int main (void)
{
    int table[MAX_ROW][MAX_COL];
    MakeGrid(table);

    int startX, startY, targetX, targetY;
    do
    {
        printf("Starting point and ending must not be equal.\n");
        printf("Starting point (x, y)? ");
        scanf("%d %d", &startY, &startX);

        printf("Ending point (x, y)? ");
        scanf("%d %d", &targetY, &targetX);

        printf("Received Start: (%d, %d), End: (%d, %d)\n", startY, startX, targetY, targetX);
    } while (startX == targetX && startY == targetY);

    BFS(table, startX, startY, targetX, targetY);
    
}

void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void MakeGrid(int grid[MAX_ROW][MAX_COL])
{
    srand(time(NULL));

    for(int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    for(int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            printf("%d  ", grid[i][j]);
        }
        printf("\n");
    }
}

void initQueue (Queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

int isEmpty(Queue *q)
{
    return q->head == NULL;
}

void enqueue(Queue *q, int x, int y)
{
        Node *newNode = (Node*)malloc(sizeof(Node));

        newNode->x = x, newNode->y = y;
        newNode->next = NULL;

        if(isEmpty(q))
        {
            q->head = newNode;
            q->tail = newNode;
        }

        else
        {
            q->tail->next = newNode;
            q->tail = newNode;
        }
}

Node* dequeue(Queue *q)
{
    if (isEmpty(q)) return NULL;

    Node *current = q->head;
    q->head = q->head->next;


    return current;
}

void DestroyQueue(Queue *q)
{
    Node *current = q->head;

    while (current != NULL)
    {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
}

void DisplayPath(int grid[MAX_ROW][MAX_COL], int startX, int startY, int targetX, int targetY, Point path[MAX_ROW * MAX_COL], int length, int visited[MAX_ROW][MAX_COL])
{
   
    Sleep(200);

    for (int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            int printed = 0;

            if (i == startX && j == startY)
            {
                SetColor(10); printf("S "); printed = 1;
            }
            else if (i == targetX && j == targetY)
            {
                SetColor(12); printf("E "); printed = 1;
            }
            else
            {
                for (int k = 0; k < length; k++)
                {
                    if (path[k].x == i && path[k].y == j)
                    {
                        SetColor(11); printf("* "); printed = 1; break;
                    }
                }
            }

            if (!printed)
            {
                if (grid[i][j] == 1) { SetColor(8); printf("# "); }
                
                else { SetColor(15); printf(". "); }
            }
        }
        printf("\n");
    }
    SetColor(15);
    Sleep(200);

}

void BFS (int grid[MAX_ROW][MAX_COL], int startX, int startY, int targetX, int targetY)
{
    system("cls");

    printf("Grid: \n");

    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (i == startX && j == startY) {
                SetColor(10); 
                printf("S "); 
            }
            else if (i == targetX && j == targetY) {
                SetColor(10); 
                printf("E "); 
            }
            else if (grid[i][j] == 1) {
                SetColor(12); 
                printf("1 "); 
            }
            else {
                SetColor(7);
                printf("0 ");
            }
        }
        printf("\n");
    }

    if (grid[startX][startY] == 1 || grid[targetX][targetY] == 1)
    {
        SetColor(15);
        printf("Starting or ending point is blocked.\n");
        return;
    }
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    initQueue(queue);
    int visited[MAX_ROW][MAX_COL] = {0};
    Point Parent[MAX_ROW][MAX_COL];
    

    enqueue(queue, startX, startY);

    visited[startX][startY] = 1;
    Parent[startX][startY] =(Point){-1, -1};

    while (!isEmpty(queue))
    {
        Node *current = dequeue(queue);
        int x = current->x, y = current->y;
        free(current);   

        if (x == targetX && y == targetY)
        {
            Point Path[MAX_ROW * MAX_COL];
            int length = 0;

            while (x != -1 && y != -1)
            {
                Path[length++] = (Point){x, y};
                
                int tempX = Parent[x][y].x;
                int tempY = Parent[x][y].y;

                x = tempX;
                y = tempY;
            }
            printf("Path: ");

            SetColor(15);

            for (int i = length-1; i >= 0; i--)
            {
                printf("(%d, %d) ",Path[i].y, Path[i].x);
            }
            printf("\n");

            DisplayPath(grid, startX, startY, targetX, targetY, Path, length, visited);

            DestroyQueue(queue);
            free(queue);
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (newX >= 0 && newX < MAX_ROW && newY >= 0 && newY < MAX_COL && !visited[newX][newY] && grid[newX][newY] == 0)
            {
                enqueue(queue, newX, newY);
                visited[newX][newY] = 1;
                Parent[newX][newY] = (Point){x, y};
            }
        }
    }
    SetColor(15);
    printf("No path found.\n");
    DestroyQueue(queue);
    return;
}