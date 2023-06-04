#include <stdio.h>

void frameUpdate(int *frameList, int frameSize, int *fi, int *fj, int *fn, int val) {
    if(*fn == 0) {
        frameList[0] = val;
        *fi = 0;
        *fj = 1;
        *fn = 1;
        return;
    }

    if(*fn < frameSize) {
        frameList[*fj] = val;
        *fj = *fj + 1;
        *fn = *fn + 1;
        return;
    }

    frameList[*fi] = val;
    *fi = (*fi + 1) % frameSize;
    *fj = *fi;
}

void printFrame(int *frameList, int i, int j, int frameSize) {
    do {
        printf("%d ", frameList[(i % frameSize)]);
        i++;
    } while((i % frameSize) != (j % frameSize));
    printf("\n");
}

int searchFrame(int *frameList, int i, int j, int frameSize, int val) {
    do {
        if(frameList[i % frameSize] == val)
            return 1;
        i++;
    } while((i % frameSize) != (j % frameSize));

    return 0;
}

int main() {

    int reference[100];
    
    int refSize;
    printf("Enter the reference size: ");
    scanf("%d", &refSize);

    printf("Enter the reference data:\n");
    for(int i=0; i<refSize; i++) {
        scanf("%d", &reference[i]);
    }

    int frameSize;
    printf("Enter the frame size: ");
    scanf("%d", &frameSize);
    int frameList[50];
    for(int i=0; i<frameSize; i++) {
        frameList[i] = -1;
    }

    // FIFO starts here

    int fi = -1, fj = 0, fn = 0;
    int pageFault = 0;

    for(int i=0; i<refSize; i++) {
        if(fn == 0) {
            frameUpdate(frameList, frameSize, &fi, &fj, &fn, reference[i]);
            printf("Reference (%d) = Miss : ", reference[i]);
            printFrame(frameList, fi, fj, frameSize);
            pageFault++;
        }
        else {
            int found = searchFrame(frameList, fi, fj, frameSize, reference[i]);

            if(found) {
                printf("Reference (%d) = Hit : ", reference[i]);
                printFrame(frameList, fi, fj, frameSize);
            }
            else {
                frameUpdate(frameList, frameSize, &fi, &fj, &fn, reference[i]);
                printf("Reference (%d) = Miss : ", reference[i]);
                printFrame(frameList, fi, fj, frameSize);
                pageFault++;
            }
        }
    }

    printf("Page faults = %d\n", pageFault);

    return 0;
}