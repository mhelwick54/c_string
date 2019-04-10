#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct string {
	int (*print)(char *, char *);
	char *(*begin)(char *);
	char *(*end)(char *);
	char (*at)(char *, int);
	char (*back)(char *);
	char (*front)(char *);
	void (*append)(char *, char *);
	void (*push_back)(char *, char);
	char (*pop_back)(char *);
	int (*insert_string)(char *, char *, int);
	int (*insert_char)(char *, char, int);
	int (*replace_string)(char *, char *, int, int);
	int (*replace_char)(char *, char, int);
	char *(*substr)(char *, int, int);
	void (*erase)(char *);
	int (*erase_string)(char *, int, int);
	int (*erase_char)(char *, int);
	void (*copy)(char *, char *);
	void (*value)(char *, char *);
	void (*delete_string)(char *self);
};
extern const struct string String;

void mem_check(char *ptr);
int bound_check(char *str, int index);
int print(char *self, char *file);
char *begin(char *self);
char *end(char *self);
char at(char *self, int index);
char back(char *self);
char front(char *self);
void append(char *self, char *other);
void push_back(char *self, char c);
char pop_back(char *self);
int insert_string(char *self, char *other, int index);
int insert_char(char *self, char c, int index);
int replace_string(char *self, char *other, int start_index, int end_index);
int replace_char(char *self, char c, int index);
char *substr(char *self, int start_index, int end_index);
void erase(char *self);
int erase_string(char *self, int start_index, int ennd_index);
int erase_char(char *self, int index);
void copy(char *self, char *other);
void value(char *self, char *str);
void delete_string(char *self);

#endif
