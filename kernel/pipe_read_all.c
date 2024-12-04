//
// Created by zy_ on 24-3-16.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd[2]; // 文件描述符数组，用于管道
    pid_t pid; // 进程ID
    char buffer[1024]; // 用于存储读取到的数据的缓冲区
    ssize_t bytesRead; // 读取的字节数

    // 创建管道
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // 创建子进程
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // 子进程
        // 关闭管道的读端
        close(fd[0]);

        // 写入数据到管道的写端
        const char *message = "Hello from child process!";
        write(fd[1], message, strlen(message) + 1);

        // 关闭管道的写端
        close(fd[1]);
        exit(EXIT_SUCCESS);
    } else { // 父进程
        // 关闭管道的写端
        close(fd[1]);

        // 循环读取管道中的数据，直到没有更多数据可读
        while ((bytesRead = read(fd[0], buffer, sizeof(buffer) - 1)) > 0) {
            buffer[bytesRead] = '\0'; // 在读取的数据后添加空字符，以形成字符串
            printf("Received: %s", buffer);
        }

        // 检查是否发生错误
        if (bytesRead == -1) {
            perror("read");
        }

        // 关闭管道的读端
        close(fd[0]);

        // 等待子进程结束
        waitp   id(pid, NULL, 0);
    }

    return 0;
}
