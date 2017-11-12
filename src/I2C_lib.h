#include "stm32l1xx_nucleo.h"

#ifndef I2C_LIB_H_
#define I2C_LIB_H_

#define I2C_GPIO				GPIOB
#define I2C_SCL_PinSource		GPIO_PinSource8
#define I2C_SDA_PinSource		GPIO_PinSource9
#define I2C_SCL_Pin				GPIO_Pin_8
#define I2C_SDA_Pin				GPIO_Pin_9

#define I2Cx					I2C1
#define RCC_APB1Periph_I2C		RCC_APB1Periph_I2C1
#define RCC_AHBPeriph_GPIO_I2C	RCC_AHBPeriph_GPIOB
#define GPIO_AF_I2Cx			GPIO_AF_I2C1
#define I2Cx_EV_IRQn			I2C1_EV_IRQn
#define I2Cx_ER_IRQn			I2C1_ER_IRQn


void I2C_Config(uint32_t I2C_ClockSpeed);
void NVIC_Config(void);

void I2C_WriteData(uint8_t SlaveAddress, uint8_t WriteAddressReg, uint8_t* Buffer_ptr,  uint16_t NumBytesToWrite);
void I2C_WriteByte(uint8_t SlaveAddress, uint8_t WriteAddressReg, uint8_t* Buffer_ptr);
void I2C_WriteBits(uint8_t SlaveAddress, uint8_t WriteAddressReg, uint8_t BitStart, uint8_t length, uint8_t data);
void I2C_WriteBit (uint8_t SlaveAddress, uint8_t WriteAddressReg, uint8_t BitNum, uint8_t data);

void I2C_ReadData(uint8_t SlaveAddress, uint8_t ReadAddressReg, uint8_t* Buffer_ptr,  uint16_t NumBytesToRead);
void I2C_ReadByte(uint8_t SlaveAddress, uint8_t ReadAddressReg, uint8_t* Buffer_ptr);
void I2C_ReadBits(uint8_t SlaveAddress, uint8_t ReadAddressReg, uint8_t BitStart, uint8_t length, uint8_t *data);
void I2C_ReadBit (uint8_t SlaveAddress, uint8_t ReadAddressReg, uint8_t BitNum, uint8_t *data);


#endif /* I2C_LIB_H_ */
