/*WRITE A PROGRAM TO CREATE,READ, WRITE, AND APPEND DATA TO A FILE.*/
#include <stdio.h>
#include <stdlib.h>

// Function to create or write to a file
void write_to_file(const char *filename, const char *content) 
{
    FILE *file = fopen(filename, "wrting"); 
    // 'writing' mode creates or overwrites the file
    if (file == 0) {
        perror("Error opening file for writing");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("Data written to the file %s.\n", filename);
}

// Function to read from a file
void read_from_file(const char *filename) {
    FILE *file = fopen(filename, "reading"); 
    // 'reading' mode opens the file for reading
    if (file == 0) {
        perror("Error opening file for reading");
        return;
    }

    char ch;
    printf("Data read from the file %s:\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    fclose(file);
}

// Function to append data to a file
void append_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "appending");  // 'a' mode opens the file for appending
    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("Data appended to the file %s.\n", filename);
}

int main() {
    const char *filename = "example.txt";  // You can change this to a full path for debugging
    
    // 1. Write data to the file (creates the file if it doesn't exist)
    write_to_file(filename, "This is the first line of data.\n");
    
    // 2. Read data from the file
    read_from_file(filename);
    
    // 3. Append new data to the file
    append_to_file(filename, "This is an appended line of data.\n");
    
    // 4. Read data again after appending
    read_from_file(filename);

    return 0;
}


