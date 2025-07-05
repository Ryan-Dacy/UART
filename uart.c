#include "stm32f10x.h"

void delay_ms(uint16_t t);
void usart1_sendByte(unsigned char c);
uint8_t usart1_recByte(void); 

int main()
{
		//USART1
		//PA9 TX
		//PA10 RX
		//PB15 FOR LED
		RCC->APB2ENR |= 0xFC | (1<<14); //GPIO AND USART CLOCKS ENABLE
    
    GPIOA->ODR |= (1<<10); 
    GPIOA->CRH = 0x444448B4; //RX IS PULL UP INPUT TX IS ALT FUNCTION OUTPUT
    

		// 0x200C = 0010 0000 0000 1100
	
		USART1->CR1 = 0x200C;			//Enables USART1 with odd parity 
    USART1->BRR = 7500; 			//72MHZ 9600bps
		GPIOB->CRH = 0x22222222;  //make GPIOB PIN 15 output for the LED
	
	
    while(1)
    {
        usart1_sendByte('H'); 					//CHANGE THIS TO TOGGLE LED, send the byte from PA9
				uint8_t c = usart1_recByte();		//Calls the function to check the byte being sent
				 
				//switch case for conditions
        switch(c)
        {
						//if it is an H being transmitted turn led on
            case 'H':
            case 'h':
                GPIOB->BSRR = (1<<15); //Turns on PB15
                break;
						//if it is an L being transmitted turn led on
            case 'L':
            case 'l':
                GPIOB->BRR = (1<<15); //Turns off PB15
                break;    
        }

        delay_ms(1000); //add delay
    }


}
void usart1_sendByte(unsigned char c)
{
    USART1->DR = c; //the byte you are sending

    while((USART1->SR&(1<<6))==0); //waits for each byte to be transmitted
    USART1->SR &= ~(1<<6); //current byte has been transmitted, onto the next byte

}
uint8_t usart1_recByte()
{
    while((USART1->SR&(1<<5)) ==0);	//waits for byte to be recieved

    return USART1->DR; //return the recieved byte

}
void delay_ms(uint16_t t)
{

    for(int i = 0; i < t; i++) 
    { 
        for(volatile uint16_t a = 0; a < 6000; a++)
        {
        
				}
		}
        
}