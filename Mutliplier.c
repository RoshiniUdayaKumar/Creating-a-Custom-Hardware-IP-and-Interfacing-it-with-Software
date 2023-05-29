#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include<xparameters.h>
#include <multiply1.h>
#include <xil_io.h>

//register offset
#define Register_offset0 MULTIPLY1_S00_AXI_SLV_REG0_OFFSET
#define Register_offset1 MULTIPLY1_S00_AXI_SLV_REG1_OFFSET
#define Register_offset2 MULTIPLY1_S00_AXI_SLV_REG2_OFFSET

//multiply1_base address
#define baseaddress XPAR_MULTIPLY1_0_S00_AXI_BASEADDR

int main()
{
    init_platform();//initialize
    int output;
    for (int i; i<16; i++)
    {
      MULTIPLY1_mWriteReg(baseaddress,Register_offset0,i+1);
      MULTIPLY1_mWriteReg(baseaddress,Register_offset1,i+2);

      output= MULTIPLY1_mReadReg(baseaddress, Register_offset2 );
      xil_printf("reg1 =%d , reg2 =%d, output =%d \n \r",i+1, i+2, output);
    }
    cleanup_platform(); //clean-up
    return 0;
}
