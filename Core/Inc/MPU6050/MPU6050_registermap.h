/*
 * Author: 		Victo Carmona Ortiz / @BiomechatronicsRookie (github)
 * Date: 		12/10/2024 (DD-MM-YYYY)
 *
 * Description: low level i2c data read functions to work with MPU6050
 */
#ifndef MPU6000_REGISTER_MAP_H
#define MPU6000_REGISTER_MAP_H

// Self Test Registers
#define SELF_TEST_X      0x0D  // 00001101
#define SELF_TEST_Y      0x0E  // 00001110
#define SELF_TEST_Z      0x0F  // 00001111
#define SELF_TEST_A      0x10  // 00010000

// Sample Rate Divider
#define SMPLRT_DIV       0x19  // 00011001

// Configuration Registers
#define CONFIG           0x1A  // 00011010
#define GYRO_CONFIG      0x1B  // 00011011
#define ACCEL_CONFIG     0x1C  // 00011100

// FIFO Enable
#define FIFO_EN          0x23  // 00100011

// I2C Master Control
#define I2C_MST_CTRL     0x24  // 00100100

// I2C Slave 0-3 Control
#define I2C_SLV0_ADDR    0x25  // 00100101
#define I2C_SLV0_REG     0x26  // 00100110
#define I2C_SLV0_CTRL    0x27  // 00100111
#define I2C_SLV1_ADDR    0x28  // 00101000
#define I2C_SLV1_REG     0x29  // 00101001
#define I2C_SLV1_CTRL    0x2A  // 00101010
#define I2C_SLV2_ADDR    0x2B  // 00101011
#define I2C_SLV2_REG     0x2C  // 00101100
#define I2C_SLV2_CTRL    0x2D  // 00101101
#define I2C_SLV3_ADDR    0x2E  // 00101110
#define I2C_SLV3_REG     0x2F  // 00101111
#define I2C_SLV3_CTRL    0x30  // 00110000

// I2C Slave 4 Control
#define I2C_SLV4_ADDR    0x31  // 00110001
#define I2C_SLV4_REG     0x32  // 00110010
#define I2C_SLV4_DO      0x33  // 00110011
#define I2C_SLV4_CTRL    0x34  // 00110100
#define I2C_SLV4_DI      0x35  // 00110101

// I2C Master Status
#define I2C_MST_STATUS   0x36  // 00110110

// Interrupt Pin / Bypass Enable Configuration
#define INT_PIN_CFG      0x37  // 00110111

// Interrupt Enable
#define INT_ENABLE       0x38  // 00111000

// Interrupt Status
#define INT_STATUS       0x3A  // 00111010

// Accelerometer Output Registers
#define ACCEL_XOUT_H     0x3B  // 00111011
#define ACCEL_XOUT_L     0x3C  // 00111100
#define ACCEL_YOUT_H     0x3D  // 00111101
#define ACCEL_YOUT_L     0x3E  // 00111110
#define ACCEL_ZOUT_H     0x3F  // 00111111
#define ACCEL_ZOUT_L     0x40  // 01000000

// Temperature Output Registers
#define TEMP_OUT_H       0x41  // 01000001
#define TEMP_OUT_L       0x42  // 01000010

// Gyroscope Output Registers
#define GYRO_XOUT_H      0x43  // 01000011
#define GYRO_XOUT_L      0x44  // 01000100
#define GYRO_YOUT_H      0x45  // 01000101
#define GYRO_YOUT_L      0x46  // 01000110
#define GYRO_ZOUT_H      0x47  // 01000111
#define GYRO_ZOUT_L      0x48  // 01001000

// External Sensor Data Registers
#define EXT_SENS_DATA_00 0x49  // 01001001
#define EXT_SENS_DATA_01 0x4A  // 01001010
#define EXT_SENS_DATA_02 0x4B  // 01001011
#define EXT_SENS_DATA_03 0x4C  // 01001100
#define EXT_SENS_DATA_04 0x4D  // 01001101
#define EXT_SENS_DATA_05 0x4E  // 01001110
#define EXT_SENS_DATA_06 0x4F  // 01001111
#define EXT_SENS_DATA_07 0x50  // 01010000
#define EXT_SENS_DATA_08 0x51  // 01010001
#define EXT_SENS_DATA_09 0x52  // 01010010
#define EXT_SENS_DATA_10 0x53  // 01010011
#define EXT_SENS_DATA_11 0x54  // 01010100
#define EXT_SENS_DATA_12 0x55  // 01010101
#define EXT_SENS_DATA_13 0x56  // 01010110
#define EXT_SENS_DATA_14 0x57  // 01010111
#define EXT_SENS_DATA_15 0x58  // 01011000

// I2C Slave 0-3 Data Out Registers
#define I2C_SLV0_DO      0x63  // 01100011
#define I2C_SLV1_DO      0x64  // 01100100
#define I2C_SLV2_DO      0x65  // 01100101
#define I2C_SLV3_DO      0x66  // 01100110

// I2C Master Delay Control
#define I2C_MST_DELAY_CTRL 0x67  // 01100111

// Signal Path Reset
#define SIGNAL_PATH_RESET 0x68  // 01101000

// User Control
#define USER_CTRL        0x6A  // 01101010

// Power Management Registers
#define PWR_MGMT_1       0x6B  // 01101011
#define PWR_MGMT_2       0x6C  // 01101100

// FIFO Count Registers
#define FIFO_COUNTH      0x72  // 01110010
#define FIFO_COUNTL      0x73  // 01110011

// FIFO Read/Write
#define FIFO_R_W         0x74  // 01110100

// Who Am I
#define WHO_AM_I         0x75  // 01110101

#endif // MPU6000_REGISTER_MAP_H



