

#include <vector>
#include <math.h>
class mpu6050_diy {
private:
  hwlib::i2c_bus & i2c_bus;
  uint8_t i2c_address;

  // uint8_t gyro_x_first_half, gyro_x_second_half;
  // registers
  uint8_t wake_up  = 0x6B;

  uint8_t acel_x_h = 0x3B;
  uint8_t acel_x_l = 0x3C;

  
  uint8_t gyro_x_h = 0x43;
  uint8_t gyro_x_l = 0x44;
  uint8_t gyro_y_h = 0x45;
  uint8_t gyro_y_l = 0x46;
  uint8_t gyro_z_h = 0x47;
  uint8_t gyro_z_l = 0x48;

public:
  // Constructor van de class.
  mpu6050_diy(hwlib::i2c_bus & i2c_bus, uint_fast8_t i2c_address):
    i2c_bus( i2c_bus ),
    i2c_address( i2c_address)
  {}

  void wakeup() {
    const uint8_t data[] = {wake_up, 0};
    size_t byte_size = sizeof(data);

    i2c_bus.write(i2c_address).write(data, byte_size);
  }

  int16_t getGyroX() {
    uint8_t first_half, second_half;

    uint8_t result;
    const uint8_t data_0[] = {gyro_x_h};
    size_t byte_size_0 = sizeof(data_0);

    const uint8_t data_1[] = {gyro_x_l};
    size_t byte_size_1 = sizeof(data_1);

    i2c_bus.write(i2c_address).write(data_0, byte_size_0);
    i2c_bus.read(i2c_address).read(first_half);

    i2c_bus.write(i2c_address).write(data_1, byte_size_1);
    i2c_bus.read(i2c_address).read(second_half);

    result = (first_half << 8) + second_half;
    return result;
  }

 };
