// This is code to play around with the NPU on your Android device without going through Seven Layers of Bloat of the Android Studio, Android NDK, XML, Gradle, CMake, etc etc etc 
// The API to interface with the hardware is alright, the rest of the stack is a disaster.

// This code is compiled within Termux and links against /system/lib64/libneuralnetwoks.so
// Install clang/gcc first: `pkg install clang`

// Build with: `-lneuralnetworks -Iheaders/ -std=c99 -O3 -Wall -Wextra -Wpedantic`
// Adding -L/system/lib64 may be required in the future
// Appears to be added automatically at this time 

#include <stdio.h>
#include <NeuralNetworks.h>

void show_device_info(uint32_t index) {
        ANeuralNetworksDevice *device;
        int64_t feature_level;          // NNAPI Feature Level of the driver
        int32_t type;                   // Device type
        char* name;                     // Device name
        char* version;                  // Device driver version

        int rc = 0;

        rc = ANeuralNetworks_getDevice(index, &device);

        if (rc) {
                printf("Error %d while attempting to get device %d\n", rc, index);
                return;
        }

        rc = ANeuralNetworksDevice_getFeatureLevel(device, &feature_level);
        rc = ANeuralNetworksDevice_getType(device, &type);
        rc = ANeuralNetworksDevice_getName(device, &name);
        rc = ANeuralNetworksDevice_getVersion(device, &version);

        printf("Device %d: %s %s v%s NNAPI v%lu\n", index, DeviceTypeNames[type], name, version, feature_level);
}

int main() {
        uint32_t device_count;
        int rc = ANeuralNetworks_getDeviceCount(&device_count);
		
        if (rc) {
                printf("Error %d while attempting to list devices\n", rc);
                return 1;
        }

        printf("Device count: %d\n", device_count);

        for (uint32_t i = 0; i < device_count; i++)
                show_device_info(i);


        return 0;
}

// Where to next? Porting this example: https://github.com/android/ndk-samples/blob/main/nn-samples/basic/src/main/cpp/simple_model.cpp
