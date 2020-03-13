/*
 * File:   main.c
 * Author: HP
 *
 * Created on 4 de septiembre de 2019, 01:51 AM
 */


#include <xc.h>
#include "SPI_CONF.h"
#include "confes.h"

//Primera parte del maesto para el envío de datos 

#define CS1 PORTAbits.RA5

void ADC_init(void)//
{
    ADCON0 = 0x00; // Inioiamos con el puerto analogo AN0
    ADCON1 = 0xFE; // Elegimos el chanal de entrada del A0
    ADCON2 = 0x24; //8 TAD Fosc/4 y justificado a la izquierda 
}

//void main(void)
//{
//    SPI_Init_Master(SPI_Clock_64, MODO_1 , DATO_Mitad);
//    __delay_ms(100);
//    while(1){
//        CS1 = 0;
//        SPI_Tx(0x02);
//        __delay_ms(500);
//        CS1 = 1;
//        __delay_ms(500);
//        CS1 = 0;
//        SPI_Tx(0x01);
//        __delay_ms(500);
//        CS1 = 1;
//        __delay_ms(500);
//    }
//    return;
//}

//Segunda parte de configuración del esclavo 1 

//void main (void)
//{
//    TRISBbits.RB7  = 1;
//    char data = '0';
//    SPI_Init_Slave(SPI_Slave_R5, MODO_1);
//    __delay_ms(100);
//    
//    TRISDbits.RD0 = 0;
//    
//    LATDbits.LATD0 = 1;
//    __delay_ms(1000);
//    LATDbits.LATD0 = 0;
//    __delay_ms(1000); 
//    while (1)
//    {
//    
//        LATDbits.LATD0 = 0;
//        
//        data = SPI_Rx();
//        
//        if (data == 0x01) 
//        {
//            LATDbits.LATD0 = 1;
//        } else 
//        {
//            LATDbits.LATD0 = 0;
//        }  
//    }
//    
//}

//Tercera parte de configuración del esclavo 2 

//void main(void) {
//    ADC_init();
//    int dato = 0;
//    int data;
//    TRISDbits.RD0 = 0;
//    LATDbits.LATD0 = 0;
//    SPI_Init_Slave(SPI_Slave_R5, MODO_1);
//    LATDbits.LATD0 = 1;
//    __delay_ms(1000);
//    while (1) {
//        data = SPI_Rx();
//        if (data == 0x02) {
//
//            LATDbits.LATD0 = 1;
//            SPI_Tx(0X31);
//        } else {
//            LATDbits.LATD0 = 0;
//        }
//    }
//}

void main(void) {
    ADC_init();
    int dato = 0;
    char data;
    TRISDbits.RD0 = 0;
    LATDbits.LATD0 = 0;
    SPI_Init_Slave(SPI_Slave_R5, MODO_1);
    LATDbits.LATD0 = 1;
    __delay_ms(1000);
    while (1) {
        data = SPI_Rx();
        switch (SPI_Rx())
        {
            case 0x00:
                LATDbits.LATD0 = 1;
                break;
            default:
                 LATDbits.LATD0 = 0;
                 break;
        }
    }
}