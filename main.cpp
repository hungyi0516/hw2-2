#include "mbed.h"

Thread thread;
Thread thread1;
PwmOut PWM1(D6);

AnalogIn Ain(A0);
AnalogOut Aout(D7);

void ADC_record()
{
    float ADC;
    while (true)
    {
        ADC = Ain;
        Aout = ADC;
        printf("%f\n\r", ADC);
        ThisThread::sleep_for(1ms);
    }
}
void led_breathing()
{
    float width[20] = {0.2f, 0.4f, 0.6f , 0.8f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f , 1.0f, 0.8f, 0.6f, 0.4f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    
    while (1) {
        PWM1.period_ms(5);
        for (int i = 0; i <= 19; i++) {
            PWM1.pulsewidth_ms(5 * width[i]);
            ThisThread::sleep_for(50ms);
        }
        
    } 
}

int main()
{
    thread.start(led_breathing);
    thread1.start(ADC_record);
    while(1){
    }
}