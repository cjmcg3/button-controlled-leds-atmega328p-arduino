#include <avr/io.h>
#include <util/delay.h>
#define MYDELAY 200

int main(void){
    DDRD = 1<<DDD6|1<<DDD7;
    PORTD = 1<<PORTD3|1<<PORTD4|1<<PORTD5;

    while(1){

        if ((PIND & (1<<PIND3)) == 0){
            if (((PIND & (1<<PIND4)) == 0)||((PIND & (1<<PIND5)) == 0)){
                PORTD &= ~(1<<PORTD6);
                PORTD &= ~(1<<PORTD7);
            }
            else{
                PORTD ^= (1<<PORTD6);
                _delay_ms(MYDELAY); 
            }
        }
        
        else{
            PORTD &= ~(1<<PORTD6);
        }

        if ((PIND & (1<<PIND4)) == 0){
            if (((PIND & (1<<PIND3)) == 0)||((PIND & (1<<PIND5)) == 0)){
                PORTD &= ~(1<<PORTD6);
                PORTD &= ~(1<<PORTD7);
            }
            else{
            PORTD ^= (1<<PORTD7);
            _delay_ms(MYDELAY);
            }
        }
        
        else{
            PORTD &= ~(1<<PORTD7);
        }

        if ((PIND & (1<<PIND5)) == 0){
            while(((PIND & (1<<PIND5)) == 0)){
                if (((PIND & (1<<PIND3)) == 0)||((PIND & (1<<PIND4)) == 0)){
                    PORTD &= ~(1<<PORTD6);
                    PORTD &= ~(1<<PORTD7);
                }
                else{
            PORTD ^= (1<<PORTD6);
            PORTD ^= (1<<PORTD7);
            _delay_ms(MYDELAY);
            }        
            }
        }
        
    }
    return(0);
}
