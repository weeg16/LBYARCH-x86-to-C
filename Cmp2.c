#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include this for time() function
#include <windows.h>

extern void imgCvtGrayInttoFloat(int height, int width, int* intImg, float* floatImg);

int main() {
    int height, width, i, j;
    printf("Input height and width: (separate w/ space)\n");
    scanf("%d %d", &height, &width);

    int* intImg = (int*)malloc(height * width * sizeof(int));
    float* floatImg = (float*)malloc(height * width * sizeof(float));

    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Generate random pixel values between 0 and 255
    printf("\nGenerated pixel values:\n");
    for (i = 0; i < height * width; i++) {
        intImg[i] = rand() % 256; 
        printf("%d ", intImg[i]);
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }

    // High-resolution timer variables
    LARGE_INTEGER frequency, start, end;
    double elapsed_time;

    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&start);

    imgCvtGrayInttoFloat(height, width, intImg, floatImg);

    QueryPerformanceCounter(&end);

    // Calculate elapsed time in nanoseconds
    elapsed_time = (double)(end.QuadPart - start.QuadPart) * 1e9 / frequency.QuadPart;

    printf("\nInt to Float:\n\n");
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
