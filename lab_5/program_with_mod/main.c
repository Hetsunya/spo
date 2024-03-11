#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/random_gen"

int main() {
    int fd = open(DEVICE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    char buffer[20]; // предполагается, что числа могут быть представлены в виде строк
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));

    if (bytesRead < 0) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Read from device: %.*s\n", (int)bytesRead, buffer);

    close(fd);
    return EXIT_SUCCESS;
}
