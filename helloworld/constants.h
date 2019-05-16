/*
 * Constants.h
 *
 * Author: Connor Hibbs
 * Created: Dec 20, 2017
 * Revised: Jan 24, 2017
 */

// Constants for the various systems on the microcontroller

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <stdint.h>

struct GPIO {
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDER;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;
};

#define gpio_a ((struct GPIO*) 0x40020000)
#define gpio_b ((struct GPIO*) 0x40020400)
#define gpio_c ((struct GPIO*) 0x40020800)

#define RCC_BASE		(volatile uint32_t*) 0x40023800
#define RCC_AHB1ENR		(volatile uint32_t*) 0x40023830
#define RCC_APB1ENR     (volatile uint32_t*) 0x40023840
#define RCC_APB2ENR		(volatile uint32_t*) 0x40023844

#define AHB1ENR_GPIOA_EN 0b1
#define AHB1ENR_GPIOB_EN 0b10
#define AHB1ENR_GPIOC_EN 0b100

#define ADC1_EN (1 << 8)

// ADC
#define ADC1_BASE 		(volatile uint32_t*) 0x40012000
#define ADC1_SR 		(volatile uint32_t*) 0x40012000
#define ADC1_CR2 		(volatile uint32_t*) 0x40012008
#define ADC1_SQR3		(volatile uint32_t*) 0x40012034
#define ADC1_DR			(volatile uint32_t*) 0x4001204C

typedef struct {
	uint32_t CR1;  // 00
	uint32_t CR2;  // 04
	uint32_t SMCR; // 08
	uint32_t DIER; // 0C
	uint32_t SR;   // 10
	uint32_t EGR;  // 14
	uint32_t CCMR1;// 18
	uint32_t CCMR2;// 1C
	uint32_t CCER; // 20
	uint32_t CNT;  // 24
	uint32_t PSC;  // 28
	uint32_t ARR;  // 2C
	uint32_t null1;// 30
	uint32_t CCR1; // 34
	uint32_t CCR2; // 38
	uint32_t CCR3; // 3C
	uint32_t CCR4; // 40
	uint32_t null2;// 44
	uint32_t DCR;  // 48
	uint32_t DMAR; // 4C
	uint32_t OR;   // 2 and 5 only
} TIMER;

#define TIMER2 ((TIMER*) 0x40000000)
#define TIMER3 ((TIMER*) 0x40000400)
#define TIMER4 ((TIMER*) 0x40000800)
#define TIMER5 ((TIMER*) 0x40000C00)

// Board Constants
#define F_CPU 16000000UL

// Useful Constants
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0


#define NVIC_ISER1 		(volatile uint32_t*) 0xE000E104


#endif
