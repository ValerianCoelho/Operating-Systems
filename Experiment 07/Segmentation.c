#include <stdio.h>

//allocated -> stores block id if block is allocated to some process
//occupied -> stores process ids

int blockSize[10], processSize[10], allocated[10], occupied[10];
int blocks = 5, processes = 4;
int diff, index;
int flag;

void firstFit()
{
    for(int i=0; i<blocks; i++)
    {
        occupied[i] = 0;
    }
    for(int i=0; i<processes; i++)
    {
        allocated[i] = -1;
    }

    for(int i=0; i<processes; i++)
    {
        for(int j=0; j<blocks; j++)
        {
            if(occupied[j] == 0 && blockSize[j] >= processSize[i])
            {
                allocated[i] = j; //For process i, block j is allocated
                occupied[j] = 1;
                break;
            }
        }
    }

    printf("\nProcess\t\tProcess Size\tBlock\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t %d \t\t", i+1, processSize[i]);
        if (allocated[i] != -1)
            printf("B%d\n", allocated[i]+1);
        else
            printf("Not Allocated\n");
    }
}
void bestFit()
{
    for(int i=0; i<blocks; i++)
    {
        occupied[i] = 0;
    }
    for(int i=0; i<processes; i++)
    {
        allocated[i] = -1;
    }

    for(int i=0; i<processes; i++)
    {
        diff = 1000;
        for(int j=0; j<blocks; j++)
        {
            if(occupied[j] == 0 && blockSize[j] >= processSize[i])
            {
                if((blockSize[j] - processSize[i]) < diff)
                {
                    diff = blockSize[j] - processSize[i];
                    index = j;
                }
            }
        }
        allocated[i] = index;
        occupied[index] = 1;
    }

    printf("\nProcess\t\tProcess Size\tBlock\n");
    for (int i = 0; i < processes; i++)
    {
        printf("P%d \t\t %d \t\t", i+1, processSize[i]);
        if (allocated[i] != -1)
            printf("B%d\n", allocated[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit()
{
    for(int i=0; i<blocks; i++)
    {
        occupied[i] = 0;
    }
    for(int i=0; i<processes; i++)
    {
        allocated[i] = -1;
    }

    for(int i=0; i<processes; i++)
    {
        diff = 0;
        flag = 0;
        for(int j=0; j<blocks; j++)
        {
            if(occupied[j] == 0 && blockSize[j] >= processSize[i])
            {
                if((blockSize[j] - processSize[i]) > diff)
                {
                    diff = blockSize[j] - processSize[i];
                    index = j;
                    flag = 1;
                }
            }
        }
        if(flag == 1)
        {
            allocated[i] = index;
            occupied[index] = 1;
        }
    }

    printf("\nProcess\t\tProcess Size\tBlock\n");
    for (int i = 0; i < processes; i++)
    {
        printf("P%d \t\t %d \t\t", i+1, processSize[i]);
        if (allocated[i] != -1)
            printf("B%d\n", allocated[i] + 1);
        else
        {
            printf("Not Allocated\n");
            continue;
        }
    }
}


int main()
{
    printf("Enter the number of processes : ");
    scanf("%d", &processes);

    for(int i=0; i<processes; i++)
    {
        printf("Process %d size : ", i+1);
        scanf("%d", &processSize[i]);
    }
    printf("\nEnter the number of blocks : ");
    scanf("%d", &blocks);
    for(int i=0; i<blocks; i++)
    {
        printf("Block %d size : ", i+1);
        scanf("%d", &blockSize[i]);
    }
    printf("First Fit:-\n");
    firstFit();

    printf("Best Fit:-\n");
    bestFit();

    printf("Worst Fit:-\n");
    worstFit();
}