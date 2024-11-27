#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern void imgCvtGrayInttoFloat(int height, int width, int* intImg, float* floatImg);

int main() {
    int height, width, i, j, choice;

    printf("Input height and width (separate with space):\n");
    scanf("%d %d", &height, &width);

    int* intImg = (int*)malloc(height * width * sizeof(int));
    float* floatImg = (float*)malloc(height * width * sizeof(float));

    printf("\nChoose input method:\n");
    printf("1. Randomly generate pixel values\n");
    printf("2. Manually input pixel values\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        srand((unsigned int)time(NULL));

        printf("\nGenerated pixel values:\n");
        for (i = 0; i < height * width; i++) {
            intImg[i] = rand() % 256;
            printf("%d ", intImg[i]);
            if ((i + 1) % width == 0) {
                printf("\n");
            }
        }
    } else if (choice == 2) {
        printf("\nEnter pixel values:\n");
        for (i = 0; i < height * width; i++) {
            scanf("%d", &intImg[i]);
        }

        printf("\nInput pixel values:\n");
        for (i = 0; i < height * width; i++) {
            printf("%d ", intImg[i]);
            if ((i + 1) % width == 0) {
                printf("\n");
            }
        }
    } else {
        printf("Invalid choice. Exiting.\n");
        free(intImg);
        free(floatImg);
        return 1;
    }

    LARGE_INTEGER frequency, start, end;
    double elapsed_time;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    imgCvtGrayInttoFloat(height, width, intImg, floatImg);

    QueryPerformanceCounter(&end);

    elapsed_time = (double)(end.QuadPart - start.QuadPart) * 1e9 / frequency.QuadPart;

    printf("\nConverted Float Pixel Values:\n\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%.2f ", floatImg[i * width + j]);
        }
        printf("\n");
    }

    printf("\nExecution time of imgCvtGrayInttoFloat: %.0f nanoseconds\n", elapsed_time);

    free(intImg);
    free(floatImg);

    return 0;
}
