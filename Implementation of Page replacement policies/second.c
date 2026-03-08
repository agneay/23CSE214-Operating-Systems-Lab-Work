#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k;
    int page_faults = 0;
    int flag, pos, farthest;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++)
    {
        flag = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            if (i < f)
            {
                frames[i] = pages[i];
            }
            else
            {
                farthest = -1;
                pos = -1;

                for (j = 0; j < f; j++)
                {
                    int found = 0;

                    for (k = i + 1; k < n; k++)
                    {
                        if (frames[j] == pages[k])
                        {
                            if (k > farthest)
                            {
                                farthest = k;
                                pos = j;
                            }
                            found = 1;
                            break;
                        }
                    }

                    if (!found)
                    {
                        pos = j;
                        break;
                    }
                }

                frames[pos] = pages[i];
            }

            page_faults++;
        }

        printf("%d\t", pages[i]);

        for (j = 0; j < f; j++)
            printf("%d ", frames[j]);

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}