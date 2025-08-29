#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 80

void display_text(char text[][MAX_LEN], int line_count) {
    printf("\nCurrent Text:\n");
    for (int i = 0; i < line_count; i++) {
        printf("%d: %s\n", i + 1, text[i]);
    }
}

void save_to_file(char text[][MAX_LEN], int line_count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < line_count; i++) {
        fputs(text[i], file);
        fputc('\n', file);
    }
    fclose(file);
    printf("File saved successfully.\n");
}

int main() {
    char text[MAX_LINES][MAX_LEN];
    int line_count = 0;
    char filename[50];
    char input[MAX_LEN];
    
    printf("Enter filename to save text: ");
    scanf("%s", filename);
    getchar(); // Clear newline from input buffer
    
    printf("Enter text (type 'SAVE' to save and exit):\n");
    while (line_count < MAX_LINES) {
        printf("%d: ", line_count + 1);
        fgets(input, MAX_LEN, stdin);
        
        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';
        
        if (strcmp(input, "SAVE") == 0) {
            break;
        }
        
        strncpy(text[line_count], input, MAX_LEN - 1);
        text[line_count][MAX_LEN - 1] = '\0'; // Ensure null-termination
        line_count++;
        
        display_text(text, line_count);
    }
    
    save_to_file(text, line_count, filename);
    return 0;
}