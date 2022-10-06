// You need this to use the Module Support Board
#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 
DigitalOut greenLED(TRAF_GRN1_PIN);
Buzzer buzz;
Buttons buttons;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);

    int counter = 0;
    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
    while (true)
    {
        while (counter < 3)
        {
        //On for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 1500);  //500ms
        //Off for 500ms
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 1000);  //500ms
        counter = counter + 1;
        }
        counter = 0;

        while (counter < 3)
        {
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 4500);  //500ms
        //Off for 500ms
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 1000);  //500ms
        //Pause
        counter = counter + 1;
        }
        counter = 0;

        while (counter < 3)
        {
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS * 1500);  //500ms
        //Off for 500ms
        greenLED = 0;
        buzz.rest();
        wait_us(WAIT_TIME_MS * 1000);
        counter = counter + 1;  //500ms
        }
         counter = 0;

        
        wait_us(WAIT_TIME_MS * 1000);

    }
}