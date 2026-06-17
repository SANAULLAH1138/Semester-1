#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    float rating;
    int runtime;
    char encodingFormats[50];
} ContentMetadata;

double** createEngagementMatrix(int numUsers, int numCategories) {
    double** matrix = (double**)malloc(numUsers * sizeof(double*));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (double*)malloc(numCategories * sizeof(double));
        for (int j = 0; j < numCategories; j++) {
            matrix[i][j] = 0.0;
        }
    }
    return matrix;
}

void updateEngagement(double** engagementMatrix, int userIndex, int categoryIndex, double newScore) {
    engagementMatrix[userIndex][categoryIndex] = newScore;
}

int** createDeviceMatrix(int numUsers, int numDevices) {
    int** matrix = (int**)malloc(numUsers * sizeof(int*));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (int*)malloc(numDevices * sizeof(int));
        for (int j = 0; j < numDevices; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void updateDeviceData(int** deviceMatrix, int userIndex, int deviceIndex, int newData) {
    deviceMatrix[userIndex][deviceIndex] = newData;
}

ContentMetadata** createContentMetadataMatrix(int numCategories, int numContent) {
    ContentMetadata** matrix = (ContentMetadata**)malloc(numCategories * sizeof(ContentMetadata*));
    for (int i = 0; i < numCategories; i++) {
        matrix[i] = (ContentMetadata*)malloc(numContent * sizeof(ContentMetadata));
    }
    return matrix;
}

void setContentMetadata(ContentMetadata** contentMatrix, int categoryIndex, int contentIndex, const char* title, float rating, int runtime, const char* formats) {
    strcpy(contentMatrix[categoryIndex][contentIndex].title, title);
    contentMatrix[categoryIndex][contentIndex].rating = rating;
    contentMatrix[categoryIndex][contentIndex].runtime = runtime;
    strcpy(contentMatrix[categoryIndex][contentIndex].encodingFormats, formats);
}

void printEngagementMatrix(double** engagementMatrix, int numUsers, int numCategories) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }
}

void printDeviceMatrix(int** deviceMatrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            printf("%d ", deviceMatrix[i][j]);
        }
        printf("\n");
    }
}

void printContentMetadataMatrix(ContentMetadata** contentMatrix, int numCategories, int numContent) {
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContent; j++) {
            printf("Title: %s, Rating: %.2f, Runtime: %d min, Formats: %s\n",
                contentMatrix[i][j].title,
                contentMatrix[i][j].rating,
                contentMatrix[i][j].runtime,
                contentMatrix[i][j].encodingFormats);
        }
    }
}

int main() {
    int numUsers = 3;
    int numCategories = 3;
    int numDevices = 3;
    int numContent = 2;

    double** engagementMatrix = createEngagementMatrix(numUsers, numCategories);
    updateEngagement(engagementMatrix, 0, 0, 5.0);
    updateEngagement(engagementMatrix, 1, 1, 4.5);

    int** deviceMatrix = createDeviceMatrix(numUsers, numDevices);
    updateDeviceData(deviceMatrix, 0, 0, 1080);
    updateDeviceData(deviceMatrix, 2, 2, 4);

    ContentMetadata** contentMatrix = createContentMetadataMatrix(numCategories, numContent);
    setContentMetadata(contentMatrix, 0, 0, "Action Movie 1", 4.5, 120, "HD, 4K");
    setContentMetadata(contentMatrix, 1, 1, "Drama Movie 1", 4.7, 110, "HD");

    printf("Engagement Matrix:\n");
    printEngagementMatrix(engagementMatrix, numUsers, numCategories);

    printf("\nDevice Matrix:\n");
    printDeviceMatrix(deviceMatrix, numUsers, numDevices);

    printf("\nContent Metadata Matrix:\n");
    printContentMetadataMatrix(contentMatrix, numCategories, numContent);

    for (int i = 0; i < numUsers; i++) {
        free(engagementMatrix[i]);
        free(deviceMatrix[i]);
    }
    free(engagementMatrix);
    free(deviceMatrix);

    for (int i = 0; i < numCategories; i++) {
        free(contentMatrix[i]);
    }
    free(contentMatrix);

    return 0;
}

