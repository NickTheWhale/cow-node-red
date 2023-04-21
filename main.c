#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    uint8_t* buffer = malloc(8 * sizeof(uint8_t));
    int i = 0;

    int32_t latitude = (int32_t)(42.72744510756365 * 1000000);
    int32_t longitude = (int32_t)(-90.48441780492087 * 1000000);

    buffer[i++] = (uint8_t)((latitude >> 24) & 0xFF);
    buffer[i++] = (uint8_t)((latitude >> 16) & 0xFF);
    buffer[i++] = (uint8_t)((latitude >> 8) & 0xFF);
    buffer[i++] = (uint8_t)(latitude & 0xFF);

    // buffer[i++] = (uint8_t)((longitude >> 24) & 0xFF);
    // buffer[i++] = (uint8_t)((longitude >> 16) & 0xFF);
    // buffer[i++] = (uint8_t)((longitude >> 8) & 0xFF);
    // buffer[i++] = (uint8_t)(longitude & 0xFF);

    // sp
    printf("%d\n", latitude);
    // printf("%d\n", longitude);
    for (int j = 0; j < i; j++) {
        printf("%u", buffer[j]);
        printf("\n");
    }

    // printf("lat: %d", latitude);
    // printf("\n");
    // printf("lon: %d", longitude);

    int32_t new_latitude = ((int32_t)buffer[0] << 24) | ((int32_t)buffer[1] << 16) | ((int32_t)buffer[2] << 8) | ((int32_t)buffer[3]);
    // int32_t new_longitude = ((int32_t)buffer[4] << 24) | ((int32_t)buffer[5] << 16) | ((int32_t)buffer[6] << 8) | ((int32_t)buffer[7]);

    printf("Original Latitude: %f\n", (float)new_latitude / 1000000.0);
    // printf("Original Longitude: %f\n", (float)new_longitude / 1000000.0);

    free(buffer);

    return 0;
}