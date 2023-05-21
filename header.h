#ifndef HEADER_H_
#define HEADER_H_

#include "timer.h"
#include "wdt.h"
#include "display.h"
#include "button.h"

void setup(void);
extern button_t b1, b2, b3;
extern timer_t t0;

#endif /* HEADER_H_ */