#include <stdio.h>
#include <stdlib.h>

void leaky_bucket(int bucket_capacity, int leak_rate, int num_packet, int packets[])
{
    int bucket = 0;
    printf("TIME\tINCOMING\tBUCKET\tLEAKED\tREMANING\n");
    
    for(int i=0; i<num_packet; i++)
    {
        printf("%d%10d", i+1,packets[i]);
        bucket+=packets[i]; 
        if(bucket>bucket_capacity)
        {
            printf("%10d(overflowed dropped %d)", bucket_capacity, bucket-bucket_capacity);
            bucket=bucket_capacity;
        }
        else
        {
            printf("%10d", bucket);
        }
        int leaked = (bucket>=leak_rate)? leak_rate:bucket;
        bucket-=leaked;
        printf("%10d%10d\n", leaked, bucket);
    }
    
    int time = num_packet+1;
    while(bucket>0)
    {
        int leaked= (bucket>=leaked)? leak_rate: bucket;
        printf("%d%10d%10d%10d%10d\n", time, 0, bucket, leaked, bucket-leaked);
        bucket = bucket - leaked;
        time++;
    }
    
}

int main()
{
    int bucket_capacity, leak_rate, num_packet;
    
    printf("enter capacity: ");
    scanf("%d", &bucket_capacity);
    
    printf("enter leak rate: ");
    scanf("%d", &leak_rate);
    
    printf("enter no.of packets: ");
    scanf("%d", &num_packet);
    int packets[num_packet];
    
    printf("enter the size of each packet\n");
    for(int i=0; i<num_packet; i++)
    {
        scanf("%d", &packets[i]);
    }
    
    leaky_bucket(bucket_capacity, leak_rate, num_packet, packets);
}