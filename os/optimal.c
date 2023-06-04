#include <stdio.h>

void frameUpdate(int *frameList, int frameSize, int *fn, int *ref, int valIdx, int refSize) {
    if(*fn < frameSize) {
        frameList[*fn] = ref[valIdx];
        *fn = *fn + 1;
        return;
    }

    int most = valIdx;
    int mostFrameIdx = -1;
    for(int i=0; i<frameSize; i++) {
        int minIdx = refSize;
        for(int j=valIdx+1; j<refSize; j++) {
            if(frameList[i] == ref[j]) {
                minIdx = j;
                break;
            }
        }

        if(minIdx == refSize) {
            mostFrameIdx = i;
            break;
        }
        if(minIdx > most) {
            most = minIdx;
            mostFrameIdx = i;
        }
    }
    frameList[mostFrameIdx] = ref[valIdx];
}

void printFrame(int *frameList, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", frameList[i]);
    }
    printf("\n");
}

int searchFrame(int *frameList, int n, int val) {
    for(int i=0; i<n; i++) {
        if(frameList[i] == val)
            return 1;
    }
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
            frameUpdate(frameList, frameSize, &fn, reference, i, refSize);
            printf("Reference (%d) = Miss : ", reference[i]);
            printFrame(frameList, fn);
            pageFault++;
        }
        else {
            int found = searchFrame(frameList, fn, reference[i]);

            if(found) {
                printf("Reference (%d) = Hit : ", reference[i]);
                printFrame(frameList, fn);
            }
            else {
                frameUpdate(frameList, frameSize, &fn, reference, i, refSize);
                printf("Reference (%d) = Miss : ", reference[i]);
                printFrame(frameList, fn);
                pageFault++;
            }
        }
    }

    printf("Page faults = %d\n", pageFault);

    return 0;
}