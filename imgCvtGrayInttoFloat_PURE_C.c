#include <stdio.h>
#include <stdlib.h>

void imgCvtGrayInttoFloat(int height, int width, int* intImg, float* floatImg) {
    int totalPixels = height * width; 
    int i;
    for (i = 0; i < totalPixels; i++) {
        int pixelValue = intImg[i] & 0xFF; // extract lower 8 bits only
        floatImg[i] = (float)pixelValue / 255.0f; // divide by 255, normalize
    }
}

int main() {
    int height, width, i, j;

    printf("Input height and width: (separate w/ space)\n");
    scanf("%d %d", &height, &width);

    int* intImg = (int*)malloc(height * width * sizeof(int));
    float* floatImg = (float*)malloc(height * width * sizeof(float));

    printf("Enter values between 0-255 (separate w/ space):\n");
    for (i = 0; i < height * width; i++) {
        scanf("%d", &intImg[i]);
    }

    imgCvtGrayInttoFloat(height, width, intImg, floatImg);

    printf("\nInt To Float: \n\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%.2f ", floatImg[i * width + j]);
        }
        printf("\n");
    }

    free(intImg);
    free(floatImg);

    return 0;
}

