#include <mbed.h>
#include <COMPONENT_SD/include/SD/SDBlockDevice.h>
#include <FATFileSystem.h>

// Uncomment row below to enable writing to SD-Card
// #define MY_SD_DEFINITION

// Create an SD Card block device with pin configuration
// according to mbed_app.json
#ifdef MY_SD_DEFINITION
SDBlockDevice sd(MBED_CONF_SD_SPI_MOSI,
                 MBED_CONF_SD_SPI_MISO,
                 MBED_CONF_SD_SPI_CLK,
                 MBED_CONF_SD_SPI_CS,
                 MBED_CONF_SD_TRX_FREQUENCY,
                 MBED_CONF_SD_CRC_ENABLED);
#endif

SPI device(PB_5, PB_4, PB_3, PA_4);

int main() {
    device.format(8, 3);
    device.frequency(1000000);

#ifdef MY_SD_DEFINITION
    // Create filesystem FAT object
    FATFileSystem fatFileSystem("sd");

    // Mount the filesystem to the block device,
    // in this case an SD Card
    if (fatFileSystem.mount(&sd) < 0)
    {
        perror("Mounting of filesystem failed!");
        return -1;
    }

    // Create a file called "hello.txt"
    File f;
    int status = f.open(&fatFileSystem, "hello.txt", O_CREAT | O_RDWR);
    if (status < 0)
    {
        perror("Error creating file with read/write permissions");
        return -1;
    }

    // Check if we can write on it
    if (!f.writable())
    {
        perror("File is not writable!");
        return -1;
    }

    // Write the start header
    const char buffer[] = "<======= Start of program =======>\r\n";
    status = f.write(buffer, sizeof(buffer));
    if (status < 0)
    {
        perror("Error writing buffer to file!");
        return -1;
    }
#endif

    // Create a buffer to write stuff to.
    char b[50] = { 0 };

    // Temporary create battery information
    int battery_status = 100;
    while (true)
    {
        // Simulate a discharging battery
        if (battery_status == 0)
            battery_status = -1;
        else
            battery_status--;

        int response = device.write(battery_status);
        printf("Response from slave: 0x%X\r\n", response);

#ifdef MY_SD_DEFINITION
        // Write battery status to a buffer and write it to a file
        snprintf(b, 30, "Battery Status: %d\r\n", battery_status);
        status = f.write(b, sizeof(b));
        if (status < 0)
        {
            perror("Could not write data to file");
            break;
        }
#endif

        // If the battery level gets to 0 end execution
        if (battery_status == -1)
            break;

        ThisThread::sleep_for(1s);
    }

#ifdef MY_SD_DEFINITION
    // Write the ending footer in the document
    const char buffer2[] = "<======= End of program =======>\r\n";
    status = f.write(buffer2, sizeof(buffer2));
    if (status < 0)
    {
        perror("Error writing to file!");
        return -1;
    }

    // Close the file
    status = f.close();
    if (status < 0)
    {
        perror("Error closing file!");
        return -1;
    }
#endif

    // End the program normally
    return 0;
}
