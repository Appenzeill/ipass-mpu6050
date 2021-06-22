#ifndef MPU6050_DIY_HPP
#define MPU6050_DIY_HPP

#include <vector>
#include <string>
#include <math.h>
/// \brief
/// Class om de data van de mpu6050 breakout board op te vragen.
/// \details
/// De functie geeft de mogelijkheid om de mpu6050 wakker te maken en de gyroscoop en acceleromater terug te geven.
class mpu6050_diy {
private:
  hwlib::i2c_bus & i2c_bus;
  uint8_t i2c_address;

  // registers
  uint8_t wake_up  = 0x6B;

  uint8_t accel_x_h = 0x3B;
  uint8_t accel_x_l = 0x3C;
  uint8_t accel_y_h = 0x3D;
  uint8_t accel_y_l = 0x3E;
  uint8_t accel_z_h = 0x3F;
  uint8_t accel_z_l = 0x40;

  uint8_t gyro_x_h    = 0x43;
  uint8_t gyro_x_l    = 0x44;
  uint8_t gyro_y_h    = 0x45;
  uint8_t gyro_y_l    = 0x46;
  uint8_t gyro_z_h    = 0x47;
  uint8_t gyro_z_l    = 0x48;

public:
  /// \brief
  /// Constructor voor de mpu6050_diy class 
  /// \details
  /// De constructor vraagt om een hwlib::i2c_bus en een uint_fast8_t i2c address.
  mpu6050_diy(hwlib::i2c_bus & i2c_bus, uint_fast8_t i2c_address):
    i2c_bus( i2c_bus ),
    i2c_address( i2c_address)
  {}
  
  /// \brief
  /// Functie om de mpu6050 breakout board wakker te maken.
  /// \details
  /// De functie is void, en heeft geen parameters.
  void wakeup() {
    const uint8_t data[] = {wake_up, 0};
    size_t byte_size = sizeof(data);

    i2c_bus.write(i2c_address).write(data, byte_size);
  }

  /// \brief
  /// Functie om de acceleratie data van X op te halen.
  /// \details
  /// De functie is void, en heeft geen parameters.

  int16_t getAccelX() {
    uint8_t first_half, second_half;
    int16_t result;
    
    const uint8_t data_0[] = {accel_x_h};
    const uint8_t data_1[] = {accel_x_l};

    i2c_bus.write(i2c_address).write(data_0, sizeof(data_0));
    i2c_bus.read(i2c_address).read(first_half);

    i2c_bus.write(i2c_address).write(data_1, sizeof(data_1));
    i2c_bus.read(i2c_address).read(second_half);

    result = (first_half << 8) + second_half;
    result = (round(result / 65.4) + 250) / 2.77777777; 


    return result;
  }

  /// \brief
  /// Functie om de acceleratie data van Y op te halen.
  /// \details
  /// De functie is void, en heeft geen parameters.
  int16_t getAccelY() {
    uint8_t first_half, second_half;
    int16_t result;
    
    const uint8_t data_0[] = {accel_y_h};
    const uint8_t data_1[] = {accel_y_l};

    i2c_bus.write(i2c_address).write(data_0, sizeof(data_0));
    i2c_bus.read(i2c_address).read(first_half);

    i2c_bus.write(i2c_address).write(data_1, sizeof(data_1));
    i2c_bus.read(i2c_address).read(second_half);

    result = (first_half << 8) + second_half;
    result = (round(result / 65.4) + 250) / 2.77777777; 


    return result;
  }
  
  /// \brief
  /// Functie om de acceleratie data van Z op te halen.
  /// \details
  /// De functie is void, en heeft geen parameters.
  int16_t getAccelZ() {
    uint8_t first_half, second_half;
    int16_t result;
    
    const uint8_t data_0[] = {accel_z_h};
    const uint8_t data_1[] = {accel_z_l};

    i2c_bus.write(i2c_address).write(data_0, sizeof(data_0));
    i2c_bus.read(i2c_address).read(first_half);

    i2c_bus.write(i2c_address).write(data_1, sizeof(data_1));
    i2c_bus.read(i2c_address).read(second_half);

    result = (first_half << 8) + second_half;
    result = (round(result / 65.4) + 250) / 2.77777777; 


    return result;
  }

  /// \brief
  /// Functie om de gyroscoop data van X op te halen.
  /// \details
  /// De functie is void, en heeft geen parameters.
  int16_t getGyroX() {
    uint8_t first_half, second_half;
    int16_t result;
    
    const uint8_t data_0[] = {gyro_x_h};
    const uint8_t data_1[] = {gyro_x_l};
    
    i2c_bus.write(i2c_address).write(data_0, sizeof(data_0));
    i2c_bus.read(i2c_address).read(first_half);
    
    i2c_bus.write(i2c_address).write(data_1, sizeof(data_1));
    i2c_bus.read(i2c_address).read(second_half);
    
    result = (first_half << 8) + second_half;
    result = (round(result / 65.4) + 250) / 2.77777777; 

    return result;
  }

  /// \brief
  /// Functie om de gyroscoop data van Y op te halen.
  /// \details
  /// De functie is void, en heeft geen parameters.
  int16_t getGyroY() {
    uint8_t first_half, second_half;
    int16_t result;
    
    const uint8_t data_0[] = {gyro_y_h};
    const uint8_t data_1[] = {gyro_y_l};
    
    i2c_bus.write(i2c_address).write(data_0, sizeof(data_0));
    i2c_bus.read(i2c_address).read(first_half);
    
    i2c_bus.write(i2c_address).write(data_1, sizeof(data_1));
    i2c_bus.read(i2c_address).read(second_half);
    
    result = (first_half << 8) + second_half;
    result = (round(result / 65.4) + 250) / 2.77777777; 


    return result;
  }

  /// \brief
  /// Functie om de gyroscoop data van Z op te halen.
  /// \details
  /// De functie is void, en heeft geen parameters.
  int16_t getGyroZ() {
    uint8_t first_half, second_half;
    int16_t result;
    
    uint8_t data_0[] = {gyro_z_h};
    uint8_t data_1[] = {gyro_z_l};
    
    i2c_bus.write(i2c_address).write(data_0, sizeof(data_0));
    i2c_bus.read(i2c_address).read(first_half);
    
    i2c_bus.write(i2c_address).write(data_1, sizeof(data_1));
    i2c_bus.read(i2c_address).read(second_half);
    
    result = (first_half << 8) + second_half;
    result = (round(result / 65.4) + 250) / 2.77777777; 

    return result;
  }
};

#endif
