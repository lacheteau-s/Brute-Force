#ifndef __UTILS_H__
#define __UTILS_H__

int str_is_digits(char *);
int int_array_contains(int, int[], int);
int index_of_char(char, char *);
int index_of_str(char *, char **);
int str_to_int(char *);
char *int_to_str(int);
int get_file_size(char *);
int get_max_entries(t_params *);

#endif