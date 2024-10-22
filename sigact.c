#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

// Global variables to keep track of signals
volatile int usr1_count = 0;
volatile int usr2_count = 0;

// TODO: Implement this function to handle SIGUSR1
void handle_sigusr1(int sig) {
    // Your code here:
    // 1. Increment usr1_count
    // 2. Print current counts of both signals
    // 3. Exit if usr1_count reaches 3
    // 4. Check if SIGUSR2 is blocked using sigprocmask()
}

// TODO: Implement this function to handle SIGUSR2
void handle_sigusr2(int sig) {
    // Your code here:
    // 1. Increment usr2_count
    // 2. Print current counts of both signals
}

int main(void) {
    struct sigaction sa1, sa2;
    
    // TODO: Set up sigaction for SIGUSR1
    // 1. Initialize sa1 structure
    // 2. Set up signal mask to block SIGUSR2 during SIGUSR1 handling
    // 3. Set appropriate flags
    // 4. Register signal handler
    
    // TODO: Set up sigaction for SIGUSR2
    // 1. Initialize sa2 structure
    // 2. Set up empty signal mask
    // 3. Set appropriate flags
    // 4. Register signal handler

    printf("PID: %d\n", getpid());
    printf("Waiting for signals (SIGUSR1 or SIGUSR2)...\n");
    printf("Send signals using: kill -SIGUSR1 %d or kill -SIGUSR2 %d\n", getpid(), getpid());
    
    // Loop until program is terminated
    while(1) {
        pause();  // Wait for signals
    }
    
    return 0;
}