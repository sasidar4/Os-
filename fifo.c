#include <stdio.h>
#include <stdlib.h>

//#define FRAME_SIZE 3 // Size of the page frame

int pageFaults(int pages[], int n)
{
    int FRAME_SIZE;
    printf("Enter the size of the page frame\n");
    scanf("%d",&FRAME_SIZE);
    int frame[FRAME_SIZE], page_faults = 0;
    int i, j, k, pos = 0;
    int isPageInFrame;

    // Initialize frame to -1 indicating empty frame
    for (i = 0; i < FRAME_SIZE; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++)
    {
        isPageInFrame = 0;

        // Check if page is already in frame
        for (j = 0; j < FRAME_SIZE; j++)
        {
            if (frame[j] == pages[i])
            {
                isPageInFrame = 1;
                break;
            }
        }

        // If page is not in frame, replace the oldest page
        if (!isPageInFrame)
        {
            frame[pos] = pages[i];
            pos = (pos + 1) % FRAME_SIZE;
            page_faults++;
        }

        // Print current frame
        printf("Frame: ");
        for (k = 0; k < FRAME_SIZE; k++)
        {
            if (frame[k] == -1)
                printf(" - ");
            else
                printf("%2d ", frame[k]);
        }
        printf("\n");
    }

    return page_faults;
}

int main()
{
    //int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}; // Reference string
    int num;
    printf("Enter the number of pages\n");
    scanf("%d",&num);
    int pages[num];
    printf("Enter the reference string\n");
    for(int i=0;i<num;i++) scanf("%d",&pages[i]);
    int n = sizeof(pages) / sizeof(pages[0]);
    printf("Reference String: ");
    for (int i = 0; i < n; i++)
        printf("%d ", pages[i]);
    printf("\n\n");

    int faults = pageFaults(pages, n);
    printf("\nTotal Page Faults: %d\n", faults);

    return 0;
}