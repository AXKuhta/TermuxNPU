#include <stdint.h>

/**
 * Device types.
 *
 * The type of NNAPI device.
 */
typedef enum {
    /** The device type cannot be provided. */
    ANEURALNETWORKS_DEVICE_UNKNOWN = 0,
    /** The device does not fall into any category below. */
    ANEURALNETWORKS_DEVICE_OTHER = 1,
    /** The device runs NNAPI models on single or multi-core CPU. */
    ANEURALNETWORKS_DEVICE_CPU = 2,
    /** The device can run NNAPI models and also accelerate graphics APIs such
     * as OpenGL ES and Vulkan. */
    ANEURALNETWORKS_DEVICE_GPU = 3,
    /** Dedicated accelerator for Machine Learning workloads. */
    ANEURALNETWORKS_DEVICE_ACCELERATOR = 4,
} DeviceTypeCode;

const char* DeviceTypeNames[] = {"Unknown device", "Other device", "CPU", "GPU", "NPU"};

// Device handle is an empty struct
typedef struct ANeuralNetworksDevice ANeuralNetworksDevice;

// Device list API
int ANeuralNetworks_getDeviceCount(uint32_t *numDevices);
int ANeuralNetworks_getDevice(uint32_t devIndex, ANeuralNetworksDevice **device);

// Device info API
int ANeuralNetworksDevice_getName(const ANeuralNetworksDevice* device, const char** name);
int ANeuralNetworksDevice_getType(const ANeuralNetworksDevice* device, int32_t* type);
int ANeuralNetworksDevice_getVersion(const ANeuralNetworksDevice* device, const char** version);
int ANeuralNetworksDevice_getFeatureLevel(const ANeuralNetworksDevice* device, int64_t* featureLevel);
int ANeuralNetworksDevice_wait(const ANeuralNetworksDevice* device);
