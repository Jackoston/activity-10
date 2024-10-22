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
    usr1_count++;
    // 1. Increment usr1_count
    cout<<"user one count:"<<usr1_count<<"user two count:"<<usr2_count;
    // 2. Print current counts of both signals
    if(usr1_count>=3)
    {
        exit(1);
    }
    // 3. Exit if usr1_count reaches 3
    sigprocmask(SIG_BLOCK, &new_set, sig);
    // 4. Check if SIGUSR2 is blocked using sigprocmask()
}

// TODO: Implement this function to handle SIGUSR2
void handle_sigusr2(int sig) {
    // Your code here:
    // 1. Increment usr2_count
    usr1_count++;
    // 2. Print current counts of both signals
    cout<<"user one count:"<<usr1_count<<"user two count:"<<usr2_count;
}

int main(void) {
    struct sigaction sa1, sa2;
    
    // TODO: Set up sigaction for SIGUSR1
    // 1. Initialize sa1 structure
    sigemptyset(&sigaction.sa1);
    // 2. Set up signal mask to block SIGUSR2 during SIGUSR1 handling
    sigprocmask(SIG_BLOCK, &sa2, sa1);
    // 3. Set appropriate flags
    sa1.sa_flags = SA_RESTART | SA_SIGINFO;
    // 4. Register signal handler
    // TODO: Set up sigaction for SIGUSR2
    // 1. Initialize sa2 structure
    // 2. Set up empty signal mask
    sigemptyset(&sigaction.sa2);
    // 3. Set appropriate flags
    sa2.sa_flags = SA_RESTART | SA_SIGINFO;
    // 4. Register signal handler
    sigaction(SIGUSR1, &sigaction, NULL);

    printf("PID: %d\n", getpid());
    printf("Waiting for signals (SIGUSR1 or SIGUSR2)...\n");
    printf("Send signals using: kill -SIGUSR1 %d or kill -SIGUSR2 %d\n", getpid(), getpid());
    
    // Loop until program is terminated
    while(1) {
        pause();  // Wait for signals
    }
    
    return 0;
}
