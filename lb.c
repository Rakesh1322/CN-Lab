#include <stdio.h>

int main() {
int bucket_size, outgoing_rate, incoming_packet_size, no_of_inputs, buffer = 0;
printf("Enter the bucket size, outgoing rate, and number of inputs: ");
scanf("%d %d %d", &bucket_size, &outgoing_rate, &no_of_inputs);

while (no_of_inputs > 0) {
    printf("Enter the incoming packet size: ");
    scanf("%d", &incoming_packet_size);
    printf("Incoming packet size: %d\n", incoming_packet_size);

    if (incoming_packet_size > bucket_size) {
        printf("Packet Rejected: Exceeded bucket size\n");
    } else if (incoming_packet_size <= (bucket_size - buffer)) {
        buffer += incoming_packet_size;
        printf("Bucket buffer size: %d out of %d\n", buffer, bucket_size);
    } else {
        printf("Packet Rejected: Insufficient buffer space\n");
    }

    buffer -= outgoing_rate;
    if (buffer < 0) {
        buffer = 0;
    }
    printf("After outgoing %d packets, %d packets left in the buffer out of %d\n", outgoing_rate, buffer, bucket_size);
    no_of_inputs--;
}
return 0;
}
