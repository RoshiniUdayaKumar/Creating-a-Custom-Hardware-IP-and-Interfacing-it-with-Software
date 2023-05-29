# Creating-a-Custom-Hardware-IP-and-Interfacing-it-with-Software
Objective of this project is to create a unique hardware IP block that can perform multiplication. This is accomplished using Vivado's "Create and Package IP" capability, which allows us to later integrate the peripheral into a microprocessor system and create software that communicates with it (SDK). In contrast to the prior lab, the ARM A9 CPU will be used in this lab. In place of a GPIO block, we are having the multiplication block.

Steps:

1.Creating a Block Diagram:

The block diagram for the Zynq7 processing system using the "add IP feature" is laid out.

We make sure only the UART peripheral is selected.

2.Creating a multiplication IP Block:

The "Create and Package New IP" feature can be used to create the multiplication block and we operate this in a slave mode with the data width being 32 bits.
We shall use two registers as the multiplier inputs and another register is used to connect the multiplier output.
Since, we dont need to have write capabilities for the third register, we shall comment out the non-blocking lines for slv_reg2. 
A block diagram can be re-generated after this. 

![Blockdesign](https://github.com/RoshiniUdayaKumar/Creating-a-Custom-Hardware-IP-and-Interfacing-it-with-Software/assets/133715179/021234e4-5c17-44f3-99b5-d4d88f16e8c2)

3.Developing software using SDK:

The code is written using Embedded C. 

The working of the code is:

We will first define the address of reg0, reg1 and reg2.

The values are taken from 0 to 16 and the values of reg0 and reg1 are incremented by 1 step.

The format for writing/reading registers are followed according to the syntax attached below.

// Below are examples for reading/writing to the registers 

// in your hello world C file. 

MULTIPLY_mWriteReg( /* Multiply IP Base address */, /* Register offset */, /* Value to write */ );

<variable> = MULTIPLY_mReadReg( /* Multiply IP Base address */, /* Register offset */ );

All these values (register and multiplication output) are printed on the console window.
 
After we write the code, we program the FPGA. 

4.Results:
  
The output in observed on the Moba-Xterm console window. 
  
We shall select the COM port and the baud rate/speed as 115200.
  
![output](https://github.com/RoshiniUdayaKumar/Creating-a-Custom-Hardware-IP-and-Interfacing-it-with-Software/assets/133715179/20022d68-8a9e-4047-b39a-20d4d8107a00)

5.Conclusion:
  
The ARM processor is used to generate the inputs and send it to the multiply IP block we created.
 
Important Note:
  
Suppose we change the mode from "Slave" to "Master", there could be some effects:

Depending on the specific IP core and its functionality, switching the mode from "Master" to "Slave" might have a number of effects.
  
In general, switching the IP core's mode from "Master" to "Slave" can affect how it interacts with other IP cores in the system. A Slave IP core reacts to transactions started by a Master IP core while a Master IP core normally starts transactions on the bus or interface. Hence, if you switch an IP core from Master to Slave, it won't start transactions anymore; instead, it will reply to those started by another Master IP core.
  
The timing and efficiency of the entire system may be affected by this modification. For instance, switching to a Slave IP core may result in timing issues and have an impact on the system's performance if the Master IP core oversees starting crucial operations that must happen at specified times.
 
Furthermore, the Slave IP core could become a bottleneck and impair system performance if it is not built to handle the same volume of transactions as the preceding Master IP core.
