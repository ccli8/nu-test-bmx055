#include    "mbed.h"
#include    "BMX055.h"

BMX055 imu(PD_0, PD_1);

int main()
{
    BMX055_ACCEL_TypeDef  acc;
    BMX055_GYRO_TypeDef   gyr;
    BMX055_MAGNET_TypeDef mag;

    printf("\r\nmbed OS version is %d.\r\n", MBED_VERSION);
    printf("Bosch BMX055 Test on NuMaker board!\r\n");

    //PD->SMTEN |= GPIO_SMTEN_SMTEN1_Msk;

    if (imu.chip_ready() == 0)
    {
        printf("Bosch BMX055 is NOT available!!\r\n");
        return -1;
    }
    else
    {
        printf("Bosch BMX055 is available!\r\n");
    }

    while(1) {
        imu.get_accel(&acc);
        printf("ACC: x=%+3.2f y=%+3.2f z=%+3.2f\r\n", acc.x, acc.y, acc.z);
        imu.get_gyro(&gyr);
        printf("GYR: x=%+3.2f y=%+3.2f z=%+3.2f\r\n", gyr.x, gyr.y, gyr.z);
        imu.get_magnet(&mag);
        printf("MAG: x=%+3.2f y=%+3.2f z=%+3.2f\r\n", mag.x, mag.y, mag.z);
        printf("T:%2.1f\r\n",imu.get_chip_temperature());
        ThisThread::sleep_for(500ms);
    }
    
    return 0;
}
