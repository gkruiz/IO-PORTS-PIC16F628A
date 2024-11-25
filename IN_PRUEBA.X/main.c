#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 4000000

unsigned int pwmCounter = 0;
 
void initialize (){
    // Tri-state registers. Sets all pins to outputs
    TRISA = 15; 
    TRISB = 0;
    // Turn off all comparators
    CMCON = 7;

    PORTA = 0;
    PORTB = 0;
    GIE = 1;
    T0IE = 1;
    T0CS = 0;
    PSA = 0;
    
    PS0 = 0;
    PS1 = 1;
    PS2 = 1;
    TMR0 = 255-255;
}


void main(void) {

    initialize(); 

    while (1){
    }
}

void  __interrupt() isr(void){
    
     
    if (T0IF){
        GIE = 0;
        T0IE = 0;
        T0IF = 0;
         
        PORTB=PORTA;
        
        //RB3=RA3;

        //pwmCounter++;
 
        TMR0 = 255-255;
        GIE = 1;
        T0IE = 1;
        
    }else{
        
        pwmCounter=0;
    }
    
     
}








/*
 #pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 4000000

unsigned char pwmCounter = 0;
unsigned char ledActualBrightness = 20;
unsigned char ledTargetBrightness = 0;
unsigned char fadeCounter = 0;
void initialize (){
    // Tri-state registers. Sets all pins to outputs
    TRISA = 0; 
    TRISB = 0;
    // Turn off all comparators
    CMCON = 7;

    PORTA = 0;
    PORTB = 0;
    GIE = 1;
    T0IE = 1;
    T0CS = 0;
    PSA = 0;
    
    PS0 = 0;
    PS1 = 0;
    PS2 = 0;
    TMR0 = 255 - 50;
}


void main(void) {

    initialize(); 

    while (1){
    }
}

void  __interrupt() isr(void){
    if (T0IF){
        GIE = 0;
        T0IE = 0;
        T0IF = 0;
        // Perform the PWM brightness control
        if (ledActualBrightness > pwmCounter)
            RB0 = 1; else RB0 = 0;

        pwmCounter++;
        /*if (pwmCounter > 19) pwmCounter = 0;

        // Perform fading control
        if (ledActualBrightness <= ledTargetBrightness)
            ledActualBrightness = ledTargetBrightness;
        else
        {
            fadeCounter++;
            if (fadeCounter >= 24)
            {
                ledActualBrightness--;
                fadeCounter = 0;
            }
        }

        TMR0 = 255 - 50;
        GIE = 1;
        T0IE = 1;
    }
}
 */