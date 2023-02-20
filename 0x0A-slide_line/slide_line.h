#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

void slide_number_left(int *line, size_t size, int direction);
void slide_number_right(int *line, size_t size, int direction);
int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
