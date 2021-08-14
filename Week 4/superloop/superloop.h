#ifndef _SUPERLOOP_H
#define _SUPERLOOP_H

extern void superloop(int depth, int start, int end, int increment, void (*function)(int, int (*)[]));

#endif