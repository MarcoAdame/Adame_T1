
/**Standard input/output to debug console*/
#include <stdio.h>
/**Standard integer definition provided by the compiler*/
#include <stdint.h>
#include "MK64F12.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_common.h"

#define LED_R 22u  	//PortB
#define LED_B 21u	//PortB
#define LED_G 26u	//PortE
#define RED		0x00400000
#define BLUE	0x00200000
#define GREEN	0x04000000

#define CORE_FREQ 21000000u
#define DELAY 1000000u



int main(void) {

	//Encender relojes
		//Registra para habilitar el clock del puerto B
		SIM->SCGC5 = 0x2400; //Configuracion del reloj? -> estoy configurando el reloj del periferico
		//SIM->SCGC5 |= 0x800;
	//Configurar el puerto para que se comporte como GPIO
		PORTB->PCR[LED_R] = 0x00000100;
		PORTB->PCR[LED_B] = 0x00000100;
		PORTE->PCR[LED_G] = 0x00000100;


		//Registro de salida
			GPIOB->PDOR = 0x00400000;  	//LED_R
			GPIOB->PDOR |= 0x00200000;	//LED_B
			GPIOE->PDOR = 0x04000000;

	//Direccion de registro
	GPIOB->PDDR = 0x00400000;  	//LED_R
	GPIOB->PDDR |= 0x00200000;	//LED_B
	GPIOE->PDDR = 0x04000000;




    while(1) {
    	//Blue Led
    		GPIOB->PDOR ^= BLUE;

    		printf("BLUE RED LED ON\n");

    		SDK_DelayAtLeastUs(DELAY, CORE_FREQ);
    		GPIOB->PDOR |= BLUE;

    	//Red Led
			GPIOB->PDOR ^= RED;

			printf("RED LED ON\n");

			SDK_DelayAtLeastUs(DELAY, CORE_FREQ);
			GPIOB->PDOR |= RED;
		//Green Led
			GPIOE->PDOR ^= GREEN;

			printf("GREEN LED ON\n");

			SDK_DelayAtLeastUs(DELAY, CORE_FREQ);
			GPIOE->PDOR |= GREEN;

    }
    return 0 ;
}
