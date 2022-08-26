gcc -lneuralnetworks -L/apex/com.android.neuralnetworks/lib64/ -Iheaders/ -std=c99 -O3 -Wall -Wextra -Wpedantic -o result.elf list_devices.c
# Add -v to debug includes and linker
