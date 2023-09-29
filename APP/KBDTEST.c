#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/KeyPad/KeyPad_int.h"
#include "../HAL/Seven_Segment/Seven_Segment_int.h"
#include "../HAL/Seven_Segment/Seven_Segment_int.h"


int main(void)
{
    KPD_vidInit();
    SevenSegment_enuInit();

    while (1)

    if (KPD_u8GetPressedKey() >= 1 || KPD_u8GetPressedKey() == 9)
    {
        SevenSegment_enuDisplayDigit(KPD_u8GetPressedKey());

    }

    return 0;
}
