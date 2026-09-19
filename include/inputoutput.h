#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

void IO_printText(const char* text);
void IO_printHealthBar(int current, int max);
void IO_clearScreen(void);
int IO_readInt(void);
void IO_readString(char* buffer, int size);

#endif
