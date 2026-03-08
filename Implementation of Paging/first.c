#include <stdio.h>

int main()
{
    int pages, frames, page_table[50];
    int i, page_no;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    /* Check if pages exceed frames */
    if (pages > frames)
    {
        printf("Error: Pages exceed frames\n");
        return 0;
    }

    printf("Enter frame number for each page:\n");

    for (i = 0; i < pages; i++)
    {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &page_table[i]);
    }

    printf("\nPage Table:\n");
    printf("Page No\tFrame No\n");

    for (i = 0; i < pages; i++)
    {
        printf("%d\t%d\n", i, page_table[i]);
    }

    printf("\nEnter page number to find frame: ");
    scanf("%d", &page_no);

    if (page_no < pages)
        printf("Page %d is in Frame %d\n", page_no, page_table[page_no]);
    else
        printf("Invalid Page Number\n");

    return 0;
}