#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, choice;
    char files[50][20], fname[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file names:\n");
    for (i = 0; i < n; i++)
        scanf("%s", files[i]);

    do
    {
        printf("\n1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter file name to create: ");
            scanf("%s", fname);
            strcpy(files[n], fname);
            n++;
            printf("File created successfully\n");
            break;

        case 2:
            printf("Enter file name to delete: ");
            scanf("%s", fname);

            for (i = 0; i < n; i++)
            {
                if (strcmp(files[i], fname) == 0)
                {
                    for (int j = i; j < n - 1; j++)
                        strcpy(files[j], files[j + 1]);

                    n--;
                    printf("File deleted\n");
                    break;
                }
            }
            break;

        case 3:
            printf("Enter file name to search: ");
            scanf("%s", fname);

            for (i = 0; i < n; i++)
            {
                if (strcmp(files[i], fname) == 0)
                {
                    printf("File found\n");
                    break;
                }
            }

            if (i == n)
                printf("File not found\n");

            break;

        case 4:
            printf("\nFiles in Directory:\n");

            for (i = 0; i < n; i++)
                printf("%s\n", files[i]);

            break;
        }

    } while (choice != 5);

    return 0;
}