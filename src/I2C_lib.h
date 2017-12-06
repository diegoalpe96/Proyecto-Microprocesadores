#ifndef I2C_LIB_H_
#define I2C_LIB_H_

#include "stm32l1xx_nucleo.h"
#include "stm32l1xx.h"

#define I2C_GPIO				GPIOB
#define I2C_SCL_PinSource		GPIO_PinSource8
#define I2C_SDA_PinSource		GPIO_PinSource9
#define I2C_SCL_Pin				GPIO_Pin_8
#define I2C_SDA_Pin				GPIO_Pin_9

//#define I2Cx					I2C1
#define RCC_APB1Periph_I2C		RCC_APB1Periph_I2C1
#define RCC_AHBPeriph_GPIO_I2C	RCC_AHBPeriph_GPIOB
#define GPIO_AF_I2Cx			GPIO_AF_I2C1


#ifndef I2C_TIMEOUT
#define I2C_TIMEOUT					20000
#endif


typedef enum {
	I2C_NoError = 0,          /*!< Everything OK */
	I2C_DeviceNotConnected = 1, /*!< There is no device with valid slave address */
	I2C_AddressDeviceInvalid = 2,
	I2C_StartBitTimeOut = 3,

	/*!< Connected device with address is not MPU6050 */
} MPU6050_Result_t;


void I2C_InitConfig();
uint8_t I2C_IsConnected(I2C_TypeDef* I2Cx, uint8_t SlaveAddress);

uint8_t I2C_ReadByte(I2C_TypeDef* I2Cx, uint8_t SlaveAddress, uint8_t reg);
uint8_t I2C_ReadNoRegister(I2C_TypeDef* I2Cx, uint8_t SlaveAddress);
void I2C_ReadMultiNoRegister(I2C_TypeDef* I2Cx, uint8_t SlaveAddress, uint8_t* data, uint16_t count);
void I2C_ReadMulti(I2C_TypeDef* I2Cx, uint8_t SlaveAddress, uint8_t reg, uint8_t* data, uint16_t count);

void I2C_WriteByte(I2C_TypeDef* I2Cx, uint8_t SlavAddress, uint8_t reg, uint8_t data);
void I2C_WriteData(I2C_TypeDef* I2Cx, uint8_t SlaveAddress, uint8_t reg, uint8_t* data, uint16_t count);
void I2C_WriteNoRegister(I2C_TypeDef* I2Cx, uint8_t SlaveAddress, uint8_t data);
void I2C_WriteMultiNoRegister(I2C_TypeDef* I2Cx, uint8_t SlaveAddress, uint8_t* data, uint16_t count);

/* Funciones privadas */
int16_t I2C_Start(I2C_TypeDef* I2Cx, uint8_t SlaveAddress, uint8_t direction, uint8_t ack);
uint8_t I2C_Stop(I2C_TypeDef* I2Cx);
uint8_t I2C_ReadAck(I2C_TypeDef* I2Cx);
uint8_t I2C_ReadNack(I2C_TypeDef* I2Cx);
void I2C_Write(I2C_TypeDef* I2Cx, uint8_t data);
void I2C_WriteBits(I2C_TypeDef* I2Cx, uint8_t SlaveAddress, uint8_t WriteAddressReg, uint8_t BitStart, uint8_t length, uint8_t data);
ErrorStatus I2C_TestEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT);

//void I2C_WriteData(uint8_t SlaveAddress, uint8_t WriteAddressReg, uint8_t* Buffer_ptr,  uint16_t NumBytesToWrite);
//void I2C_WriteByte(uint8_t SlaveAddress, uint8_t WriteAddressReg, uint8_t* Buffer_ptr);
//void I2C_WriteBit (uint8_t SlaveAddress, uint8_t WriteAddressReg, uint8_t BitNum, uint8_t data);
//void I2C_ReadData(uint8_t SlaveAddress, uint8_t ReadAddressReg, uint8_t* Buffer_ptr,  uint16_t NumBytesToRead);
//void I2C_ReadByte(uint8_t SlaveAddress, uint8_t ReadAddressReg, uint8_t* Buffer_ptr);
//void I2C_ReadBits(uint8_t SlaveAddress, uint8_t ReadAddressReg, uint8_t BitStart, uint8_t length, uint8_t *data);
//void I2C_ReadBit (uint8_t SlaveAddress, uint8_t ReadAddressReg, uint8_t BitNum, uint8_t *data);


#endif /* I2C_LIB_H_ */
