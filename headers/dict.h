#ifndef __DICT_H__
#define __DICT_H__

void    write_dictionary(t_params *);
void    write_dictionary_rec(int, char *, int, t_params *);
void    write_entry(int, char *, t_params *);
int     create_new_file(int, t_params *);

#endif