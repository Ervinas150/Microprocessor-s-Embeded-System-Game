#include <stm32f031x6.h>
#include "musical_notes.h"
#include "main.h"


void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode);
void playNote(uint32_t Freq)
{	
	if (Freq == 0) {TIM14->CR1 &= ~TIM_CR1_CEN;} //if we input 0, mutec
	else {
	// Counter is running at 65536 Hz 
	TIM14->ARR = (uint32_t)65536/((uint32_t)Freq); 
	TIM14->CCR1 = TIM14->ARR/2;	
	TIM14->CNT = 0; // set the count to zero initially
	TIM14->CR1 |= (1 << 0); // and enable the counter
	}
}
void initSound()
{
	// Power up the timer module
	RCC->APB1ENR |= (1 << 8);
	pinMode(GPIOB,1,2); // Assign a non-GPIO (alternate) function to GPIOB bit 1
	GPIOB->AFR[0] &= ~(0x0fu << 4); // Assign alternate function 0 to GPIOB 1 (Timer 14 channel 1)
	TIM14->CR1 = 0; // Set Timer 14 to default values
	TIM14->CCMR1 = (1 << 6) + (1 << 5);
	TIM14->CCER |= (1 << 0);
	TIM14->PSC = 48000000UL/65536UL; // Use the prescaled to set the counter running at 65536 Hz
									 // yields maximum frequency of 21kHz when ARR = 2;
	TIM14->ARR = (48000000UL/(uint32_t)(TIM14->PSC))/((uint32_t)C4);
	TIM14->CCR1 = TIM14->ARR/2;	
	TIM14->CNT = 0;
}

void mute()
{
	background_tune_notes = empty_note;
	background_tune_times = empty_times;
	background_tune_note_count = 1;
	background_repeat_tune = 1;
}

void playMainMenu()
{
	background_tune_notes = menu;
	background_tune_times = menu_times;
	background_tune_note_count = 7;
	background_repeat_tune = 1;
}
void playGameMusic()
{
	background_tune_notes = gameMusic;
	background_tune_times = gameTimes;
	background_tune_note_count = 5;
	background_repeat_tune = 1;

}
void playWin()
{
        background_tune_notes = winMusic;
        background_tune_times = winTimes;
        background_tune_note_count = 3;
        background_repeat_tune = 1;

}
void playLose()
{
        background_tune_notes = loseMusic;
        background_tune_times = loseTimes;
        background_tune_note_count = 3;
        background_repeat_tune = 1;

}
