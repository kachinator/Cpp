/**
 * Threads that waste CPU cycles
 */
#include <thread>
#include <chrono>
#include <unistd.h>
#include <stdio.h>

// a simple function that wastes CPU cycles "forever"
void cpu_waster() 
{
    printf("\tCPU Waster Process ID: %d\n", getpid());
    printf("\t\tCPU Waster Thread ID %d\n", std::this_thread::get_id());
    while(true) 
    {
        continue;  // forever loop
    }
}

int main() {
    printf("Main Process ID: %ld\n", getpid());
    printf("Main Thread ID: %ld\n", std::this_thread::get_id());

    // Create threads
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster); 

    while(true) 
    { 
        // keep the main thread alive "forever"
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

/*

Main Process ID: 135003
Main Thread ID: 129503811077056
        CPU Waster Process ID: 135003
                CPU Waster Thread ID 1950348864
        CPU Waster Process ID: 135003
                CPU Waster Thread ID 1941956160
^C

*/