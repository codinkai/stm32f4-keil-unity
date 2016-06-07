
#ifndef __DEBUG_PRINTF_H__
#define __DEBUG_PRINTF_H__

/* includes ------------------------------------------------------------------*/

#include <stdint.h>

/* defines -------------------------------------------------------------------*/

#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

#endif /* __DEBUG_PRINTF_H__ */
