#include "../include/string.h"

void mem_check(char *ptr) {
	if(ptr == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(-1);
	}
}

int bound_check(char *str, int index) {
	if(index >= strlen(str) || index < 0) {
		return 0;
	} else {
		return 1;
	}
}

int print(char *self, char *file) {
	if(strcmp(file, "stdout") == 0) {
		fprintf(stdout, "%s\n", self);
	} else if(strcmp(file, "stderr") == 0) {
		fprintf(stderr, "%s\n", self);
	} else {
		int fd = open(file, O_WRONLY | O_APPEND | O_CREAT);
		if(write(fd, self, strlen(self)) == -1) {
			fprintf(stderr, "Write failed: string %s to file %s\n", self, file);
			return -1;
		}
	}
	return 0;
}

char *begin(char *self) {
	return &self[0];
}

char *end(char *self) {
	return (self + strlen(self) - 1);
}

char at(char *self, int index) {
	if(!bound_check(self, index)) {
		return -1;
	} else {
		return self[index];
	}
}

char back(char *self) {
	return self[strlen(self) - 1];
}

char front(char *self) {
	return self[0];
}

void append(char *self, char *other) {
	int len_self = strlen(self), len_other = strlen(other);
	int i = 0;
	self = realloc(self, (len_self + len_other + 1) * sizeof(char));
	for(i = 0; i < len_other; i++) {
		self[i+len_self] = other[i];
	}
	self[len_self + len_other] = '\0';
}

void push_back(char *self, char c) {
	int len = strlen(self) + 2;
	self = realloc(self, len * sizeof(char));
	self[len-2] = c;
	self[len-1] = '\0';
}

char pop_back(char *self) {
	int pos = strlen(self) - 1;
	char ret = self[pos];
	self[pos] = '\0';
	return ret;
}

int insert_string(char *self, char *other, int index) {
	if(!bound_check(self, index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", index, strlen(self));
		return 0;
	}

	int len_self = strlen(self), len_other = strlen(other);
	self = realloc(self, (len_self + len_other + 1) * sizeof(char));
	int i = 0;
	for(i = len_self; i >= index; --i) {
		self[i+len_other] = self[i];
	}
	for(i = index; i < index + len_other; ++i) {
		self[i] = other[i - index];
	}
	self[len_self + len_other] = '\0';

	return 1;
}

int insert_char(char *self, char c, int index) {
	if(!bound_check(self, index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", index, strlen(self));
		return 0;
	}

	int len_self = strlen(self);
	self = realloc(self, (len_self + 1) * sizeof(char));
	int i = 0;
	for(i = len_self; i >= index; --i) {
		self[i+1] = self[i];
	}
	self[index] = c;
	self[len_self + 1] = '\0';

	return 1;
}

int replace_string(char *self, char *other, int start_index, int end_index) {
	if(!bound_check(self, start_index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", start_index, strlen(self));
		return 0;
	}

	if(!bound_check(self, end_index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", end_index, strlen(self));
		return 0;
	}

	int i = 0;
	for(i = start_index; i <= end_index; ++i) {
		self[i] = other[i-start_index];
	}

	return 1;
}

int replace_char(char *self, char c, int index) {
	if(!bound_check(self, index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", index, strlen(self));
		return 0;
	}

	self[index] = c;

	return 1;
}

char *substr(char *self, int start_index, int end_index) {
	if(!bound_check(self, start_index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", start_index, strlen(self));
		return 0;
	}

	if(!bound_check(self, end_index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", end_index, strlen(self));
		return 0;
	}

	int new_len = end_index - start_index + 2;

	char *substr = malloc(new_len * sizeof(char));
	int i = 0, j = 0;
	for(i = start_index; i <= end_index; ++i) {
		substr[j] = self[i];
		++j;
	}

	substr[new_len] = '\0';

	return substr;
}

void erase(char *self) {
	int len = strlen(self), i = 0;
	for(i = 0; i < len; i++) {
		self[i] = '\0';
	}
}

int erase_string(char *self, int start_index, int end_index) {
	if(!bound_check(self, start_index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", start_index, strlen(self));
		return 0;
	}

	if(!bound_check(self, end_index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", end_index, strlen(self));
		return 0;
	}

	int len = strlen(self);
	int i = 0;
	for(i = start_index; i < 1 + len - end_index; ++i) {
		self[i] = self[end_index + i];
	}
	self[i] = '\0';
	self = realloc(self, (strlen(self) + 1) * sizeof(char));

	return 1;
}

int erase_char(char *self, int index) {
	if(!bound_check(self, index)) {
		fprintf(stderr, "Attempt to access outside of bounds: request for %d is outside of range %ld\n", index, strlen(self));
		return 0;
	}

	int len = strlen(self);

	int i = 0;
	for(i = index; i < len; ++i) {
		self[i] = self[i+1];
	}
	self = realloc(self, len * sizeof(char));
	self[len] = '\0';

	return 1;
}

void copy(char *self, char *other) {
	int len = strlen(other);
	if(len > strlen(self)) {
		self = realloc(self, (len + 1));
		mem_check(self);
	}

	strncpy(self, other, len);
	mem_check(self);

	self[len] = '\0';
}

void value(char *self, char *str) {
	int len = strlen(str);
	self = malloc((len + 1) * sizeof(char));
	mem_check(self);

	strncpy(self, str, len);
	mem_check(self);

	self[len] = '\0';
}

void delete_string(char *self) {
	free(self);
}

const struct string String = {
	&print,
	&begin,
	&end,
	&at,
	&back,
	&front,
	&append,
	&push_back,
	&pop_back,
	&insert_string,
	&insert_char,
	&replace_string,
	&replace_char,
	&substr,
	&erase,
	&erase_string,
	&erase_char,
	&copy,
	&value
};
