/*
** EPITECH PROJECT, 2021
** asm
** File description:
** reader
*/

#include "asm.h"

/*
** Return the size of the file described by FD
*/
int get_file_size(int fd)
{
    int size;

    size = lseek(fd, 0L, SEEK_END);
    lseek(fd, 0L, SEEK_SET);
    return (size);
}

/*
** Return the content of the file described by FD
*/
char *read_source_file(int fd_in)
{
    int size = get_file_size(fd_in);
    char *buff;

    if (size == 0)
        return (NULL);
    buff = malloc(sizeof(char) * (size + 1));
    read(fd_in, buff, size);
    buff[size] = '\0';
    return (buff);
}

/*
** Open the output file and set asms->fd_out
*/
int open_output_file(char *input, asms_t *asms)
{
    char *output_path = get_output_filename(input);
    int fd_out = open(output_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd_out == -1)
        return (put_error("Fail to open the output file\n"));
    asms->fd_out = fd_out;
    return (0);
}

/*
** Return the path to the output file
*/
char *get_output_filename(char *input)
{
    char *output = NULL;
    int len = my_strlen(input);
    int i = 0;
    int size = 0;

    input[len - 2] = '\0';
    for (i = len - 3; input[i] != '/' && i >= 0; i--);
    i++;
    size = len - 1 - i;
    if (!(output = malloc(sizeof(char) * (size + 5))))
        exit(84);
    my_strcpy(output, input + i);
    my_strcat(output, ".cor");
    return (output);
}
