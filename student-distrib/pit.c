#include "pit.h"

/*Check this link:
https://wiki.osdev.org/Pit#Operating_Modes */

void initialize_PIT(){
    
    //outb( , IO_PORT_NUM); //what is this?
    enable_irq(PIT_IRQ_NUM);
}   




