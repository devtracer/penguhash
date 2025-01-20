#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void print_help();
char* compute_hash(const char *filepath, const char *hashtype);
void compare_hashes(const char *file1, const char *file2);

int main(int argc, char *argv[]) {
    if (argc > 3) {
        printf("Entries must be three or less. Write penguinhash -h for more.\n");
        return 1;
    }

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }

    if (argc == 3) {
        printf("Comparing hashes of %s and %s\n", argv[1], argv[2]);
        compare_hashes(argv[1], argv[2]);
    } else if (argc == 2) {
        printf("Calculating hash for %s\n", argv[1]);
        char *hash = compute_hash(argv[1], "sha256");
        if (hash) {
            printf("SHA-256: %s\n", hash);
            free(hash);
        } else {
            printf("Error calculating hash.\n");
        }
    }

    return 0;
}

void print_help() {
    printf("Command menu:\n");
    printf("  penguinhash -h                : Show this help message\n");
    printf("  penguinhash <path1> <path2>   : Compare hash\n");
    printf("  penguinhash <file path>       : Calculate SHA-256 hash\n");
}

char* compute_hash(const char *filepath, const char *hashtype) {
    if (!filepath || !hashtype) return NULL;

    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Use OpenSSL or another library for hashing.
    // Placeholder return for now.
    fclose(file);
    char *result = malloc(64); // Placeholder buffer for hash output.
    strcpy(result, "dummyhashvalue"); // Placeholder hash output.
    return result;
}

void compare_hashes(const char *file1, const char *file2) {
    char *hash1 = compute_hash(file1, "sha256");
    char *hash2 = compute_hash(file2, "sha256");

    if (hash1 && hash2) {
        if (strcmp(hash1, hash2) == 0) {
            printf("Files have the same hash.\n");
        } else {
            printf("Files have different hashes.\n");
        }
        free(hash1);
        free(hash2);
    } else {
        printf("Error computing hashes for comparison.\n");
    }
}
