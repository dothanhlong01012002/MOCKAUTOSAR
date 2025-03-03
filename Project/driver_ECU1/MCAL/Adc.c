#include "Adc.h"

FUNC(uint16,AUTOMATIC) Adc_ReadChannel(VAR(char,AUTOMATIC) channel) {
    if(channel == 1){
        return 512;
    }
    else{
        return 32;
    }
}
