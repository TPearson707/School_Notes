#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    // Open a file for writing
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file_fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Use dup to duplicate the file descriptor
    int dup_fd = dup(file_fd);
    if (dup_fd < 0) {
        perror("dup");
        close(file_fd);
        exit(EXIT_FAILURE);
    }

    // Use dup2 to redirect stdout to the file
    if (dup2(file_fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(file_fd);
        close(dup_fd);
        exit(EXIT_FAILURE);
    }

    // Now all printf statements will go to the file
    printf("This will go to the file output.txt using dup2!\n");

    // Close the file descriptor
    close(file_fd);
    close(dup_fd);

    // Restore stdout (optional)
    int saved_stdout = dup(STDOUT_FILENO); // Save original stdout
    if (saved_stdout < 0) {
        perror("dup");
        exit(EXIT_FAILURE);
    }

    // Redirect stdout back to the terminal
    if (dup2(saved_stdout, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(saved_stdout);
        exit(EXIT_FAILURE);
    }
    close(saved_stdout);

    // Now printf will go back to the terminal
    printf("This will go to the terminal!\n");

    return 0;
}
