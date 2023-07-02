#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define IN_FILE "../input.txt"
#define MAX_LINE_LEN 2256
#define MAX_KV_LEN 2256

typedef struct {
    int key;
    int value;
} KeyValue;

void sortKeyValueArray(KeyValue* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j].value < array[j + 1].value) {
                KeyValue temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    clock_t start = clock(); // Start the clock

    FILE* file = fopen(IN_FILE, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", IN_FILE);
        return -1;
    }

    KeyValue keyValue[MAX_KV_LEN];
    int elfno = 0;
    int counter = 0;
    int tmpbuf = 0;
    char line[MAX_LINE_LEN];

    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        if (strlen(line) <= 1) {
            elfno++;
        } else {
            sscanf(line, "%d", &keyValue[counter].value);
            keyValue[counter].key = elfno;
            counter++;
        }
    }

    fclose(file);

    KeyValue kvTotal[MAX_KV_LEN];
    int totalCounter = 0;

    for (int i = 0; i < counter; i++) {
        /* stdout makes this run a lot slower */
        //printf("Elf: %d, value: %d\n", keyValue[i].key, keyValue[i].value); 
        tmpbuf += keyValue[i].value;
        if (i + 1 == counter || keyValue[i + 1].key != keyValue[i].key) {
            kvTotal[totalCounter].key = keyValue[i].key;
            kvTotal[totalCounter].value = tmpbuf;
            tmpbuf = 0;
            totalCounter++;
        }
    }

    sortKeyValueArray(kvTotal, totalCounter);

    printf("[*] Highest: %d\n", kvTotal[0].value);
    printf("[*] Sum of top 3: %d\n", kvTotal[0].value + kvTotal[1].value + kvTotal[2].value);


    clock_t end = clock();
    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Time taken: %.5f ms\n", time_taken);

    return 0;
}
