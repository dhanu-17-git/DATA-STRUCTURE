# **Operating System Lab Programs**

## **Process System Calls**

### **1. fork() System Call**
```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // make two process which run same
    // program after this instruction
    fork();
    printf("Hello world!\n");
    return 0;
}
```

### **2. wait() System Call**
```c
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    if (fork() == 0) {
        printf("HC: hello from child\n");
    } else {
        printf("HP: hello from parent\n");
        wait(NULL);
        printf("CT: child has terminated\n");
    }
    
    printf("Bye\n");
    return 0;
}
```

### **3. exec() System Call**

**File 1: ex1.c**
```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *agrv[]) {
    printf("PID of ex1.c =%d\n", getpid());
    
    char *agrs[] = {"Hello", "World", NULL};
    
    execv("./ex2", agrs);
    
    printf("Back to ex1.c");
    return 0;
}
```

**File 2: ex2.c**
```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *agrv[]) {
    printf("We are in ex2.c \n");
    printf("PID of ex2.c =%d\n", getpid());
    return 0;
}
```

---

## **CPU Scheduling Algorithms**

### **1. FCFS Scheduling**
```c
#include<stdio.h>

int main() {
    int n, at[10], bt[10], wt[10], tat[10], ct[10], sum, i, j, k;
    float totaltat = 0, totalwt = 0;
    
    printf("enter the total number of processes:");
    scanf("%d", &n);
    
    printf("\nEnter The Process Arrival Time & Burst Time\n");
    for(i = 0; i < n; i++) {
        printf("Enter Arrival time of process[%d]:", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst time of process[%d]:", i + 1);
        scanf("%d", &bt[i]);
    }
    
    /* Calculate completion time of processes */
    sum = at[0];
    for(j = 0; j < n; j++) {
        sum = sum + bt[j];
        ct[j] = sum;
    }
    
    /* Calculate Turn Around time */
    for(k = 0; k < n; k++) {
        tat[k] = ct[k] - at[k];
        totaltat = totaltat + tat[k];
    }
    
    /* Calculate Waiting time */
    for(k = 0; k < n; k++) {
        wt[k] = tat[k] - bt[k];
        totalwt = totalwt + wt[k];
    }
    
    printf("\n Process\t AT\t BT\t CT\t TAT\t WT \n\n\n");
    for(i = 0; i < n; i++) {
        printf("\n P%d\t %d\t %d\t %d\t %d\t %d\t \n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    printf("\n Average TurnaroundTime:%f \n", totaltat / n);
    printf("\n Average Waiting Time:%f", totalwt / n);
    return 0;
}
```

### **2. SJF Scheduling**
```c
#include<stdio.h>

int main() {
    int n, at[10], bt[10], wt[10], tat[10], ct[10], p[10], sum, i, j, k, temp;
    float totaltat = 0, totalwt = 0;
    
    printf("Enter the total number of processes:");
    scanf("%d", &n);
    
    printf("\nEnter the process number:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);
    
    printf("\nEnter The Process Burst Time\n");
    for(i = 0; i < n; i++) {
        printf("Enter Burst time of process[%d]:", i + 1);
        scanf("%d", &bt[i]);
    }
    
    /* Apply Bubble sort to sort according to burst time and process number */
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(bt[j] > bt[j + 1]) {
                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                
                // Swap Process ID
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    
    /* Calculate completion time of processes */
    sum = 0;
    for(j = 0; j < n; j++) {
        sum = sum + bt[j];
        ct[j] = sum;
        printf("%d\t", ct[j]);
    }
    
    /* Calculate Turn Around time */
    for(k = 0; k < n; k++) {
        tat[k] = ct[k];
        totaltat = totaltat + tat[k];
    }
    
    /* Calculate Waiting time */
    for(k = 0; k < n; k++) {
        wt[k] = tat[k] - bt[k];
        totalwt = totalwt + wt[k];
    }
    
    printf("\nProcess\tBT\tTAT\tWT\n\n\n");
    for(i = 0; i < n; i++) {
        printf("\nP%d\t %d\t %d\t %d\t %d\t %d\t\n", i + 1, bt[i], tat[i], wt[i]);
    }
    
    printf("\nAverage TurnaroundTime:%f\n", totaltat / n);
    printf("\nAverage Waiting Time:%f", totalwt / n);
    return 0;
}
```

### **3. Priority Scheduling (Round Robin)**
```c
#include<stdio.h>

int main() {
    int n, i, remaining[10], bt[10], wt[10], tat[10], quantum, time = 0, done;
    float totaltat = 0, totalwt = 0;
    
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    
    printf("\nEnter Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        remaining[i] = bt[i];
        wt[i] = 0;
    }
    
    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);
    
    /* Round Robin Logic */
    while(1) {
        done = 1;
        for(i = 0; i < n; i++) {
            if(remaining[i] > 0) {
                done = 0;
                if(remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    tat[i] = time;
                    remaining[i] = 0;
                }
            }
        }
        if(done == 1) break;
    }
    
    /* Calculate waiting times */
    for(i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        totaltat += tat[i];
        totalwt += wt[i];
    }
    
    /* Display Results */
    printf("\nProcess\tBT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], tat[i], wt[i]);
    }
    
    printf("\nAverage Turnaround Time: %.2f", totaltat / n);
    printf("\nAverage Waiting Time: %.2f\n", totalwt / n);
    
    return 0;
}
```

---

## **Synchronization Problems**

### **4. Producer-Consumer Problem**
```c
#include <stdio.h>
#include <stdlib.h>

// Global variables
int mutex = 1;
int full = 0;
int empty = 3;
int count = 0;

// Function prototypes
void producer();
void consumer();
int wait(int s);
int signal(int s);

int main() {
    int choice;
    
    printf("\n1. PRODUCER\n2. CONSUMER\n3. EXIT\n");
    
    while (1) {
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("BUFFER IS FULL\n");
                }
                break;
                
            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("BUFFER IS EMPTY\n");
                }
                break;
                
            case 3:
                printf("Exiting the program.\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

int wait(int s) {
    return --s;
}

int signal(int s) {
    return ++s;
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    count++;
    printf("\nProducer produces item %d\n", count);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d\n", count);
    count--;
    mutex = signal(mutex);
}
```

---

## **Memory Allocation Methods**

### **5. First Fit**
```c
#include<stdio.h>

int main() {
    int bno, pno, bs[20], ps[20], i, j;
    
    printf("Enter no of Blocks.\n");
    scanf("%d", &bno);
    
    for(i = 0; i < bno; i++) {
        printf("Enter the %d Block size:", i);
        scanf("%d", &bs[i]);
    }
    
    printf("Enter no of Process.\n");
    scanf("%d", &pno);
    
    for(i = 0; i < pno; i++) {
        printf("Enter the size of %d Process:", i);
        scanf("%d", &ps[i]);
    }
    
    for(i = 0; i < bno; i++) {
        for(j = 0; j < pno; j++) {
            if(ps[j] <= bs[i]) {
                printf("The Process %d allocated to %d\n", j, bs[i]);
                ps[j] = 10000;
                break;
            }
        }
    }
    
    for(j = 0; j < pno; j++) {
        if(ps[j] != 10000) {
            printf("The Process %d is not allocated\n", j);
        }
    }
    
    return 0;
}
```

### **6. Best Fit**
```c
#include<stdio.h>
#define max 25

int main() {
    int nb, np, b[max], p[max], frag[max], i, j, temp, lowest = 10000;
    static int bf[max], ff[max];
    
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    
    printf("Enter the number of processes:");
    scanf("%d", &np);
    
    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    
    printf("Enter the size of the processes:\n");
    for(i = 1; i <= np; i++) {
        printf("Process %d:", i);
        scanf("%d", &p[i]);
    }
    
    for(i = 1; i <= np; i++) {
        for(j = 1; j <= nb; j++) {
            if(bf[j] != 1) {
                temp = b[j] - p[i];
                if(temp >= 0) {
                    if(lowest > temp) {
                        ff[i] = j;
                        lowest = temp;
                    }
                }
            }
        }
        
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
    }
    
    printf("\nProcess_no \tProcess_size \tBlock_no \tBlock_size \tFragment");
    for(i = 1; i <= np && ff[i] != 0; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], ff[i], b[ff[i]], frag[i]);
    }
    
    return 0;
}
```

### **7. Worst Fit**
```c
#include<stdio.h>
#define max 20

int main() {
    int frag[max], bs[max], ps[max], i, j, bno, pno, temp, highest = 0;
    static int bf[max], ff[max];
    
    printf("\nEnter the number of blocks:");
    scanf("%d", &bno);
    
    printf("Enter the number of processes:");
    scanf("%d", &pno);
    
    printf("\nEnter the size of the blocks:\n");
    for(i = 0; i < bno; i++) {
        printf("Block %d:", i);
        scanf("%d", &bs[i]);
    }
    
    printf("Enter the size of the processes:\n");
    for(i = 0; i < pno; i++) {
        printf("Process %d:", i);
        scanf("%d", &ps[i]);
    }
    
    for(i = 0; i < pno; i++) {
        for(j = 0; j < bno; j++) {
            if(bf[j] != 1) {
                temp = bs[j] - ps[i];
                if(temp >= 0) {
                    if(highest < temp) {
                        ff[i] = j;
                        highest = temp;
                    }
                }
            }
        }
        
        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }
    
    printf("\nProcess_no \tProcess_size \tBlock_no \tBlock_size \tFragment");
    for(i = 0; i < pno; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, ps[i], ff[i], bs[ff[i]], frag[i]);
    }
    
    return 0;
}
```

---

## **Page Replacement Algorithms**

### **8. FIFO Page Replacement**
```c
#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int num_pages, num_frames, i, j, k;
    int page_faults = 0, found;
    
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);
    
    printf("Enter the page numbers:\n");
    for(i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }
    
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);
    
    // Initialize frames to -1 (empty)
    for(i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }
    
    printf("\nRef String\tPage Frames\n");
    
    j = 0;  // FIFO pointer
    for(i = 0; i < num_pages; i++) {
        printf("%d\t\t", pages[i]);
        found = 0;
        
        // Check if page already in frames
        for(k = 0; k < num_frames; k++) {
            if(frames[k] == pages[i]) {
                found = 1;
                break;
            }
        }
        
        // If not found, it's a page fault
        if(!found) {
            frames[j] = pages[i];
            j = (j + 1) % num_frames;
            page_faults++;
        }
        
        // Display current frames
        for(k = 0; k < num_frames; k++) {
            printf("%d\t", frames[k]);
        }
        printf("\n");
    }
    
    printf("\nTotal page faults: %d\n", page_faults);
    
    return 0;
}
```

### **9. LRU Page Replacement**
```c
#include <stdio.h>

#define MAX_PAGES 50
#define MAX_FRAMES 20

int main() {
    int referenceString[MAX_PAGES], frames[MAX_FRAMES];
    int pageFaults = 0, n, numFrames, i, j, k, leastUsedIndex, pageFound;
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &referenceString[i]);
    }
    
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);
    
    // Initialize frames to -1 (empty)
    for (i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }
    
    printf("\nPage Frames:\n");
    for (i = 0; i < n; i++) {
        pageFound = 0;
        
        // Check if the page is already in one of the frames
        for (j = 0; j < numFrames; j++) {
            if (frames[j] == referenceString[i]) {
                pageFound = 1;
                break;
            }
        }
        
        // If the page is not found, we need to replace a page
        if (!pageFound) {
            pageFaults++;
            
            // If there's an empty frame, use it
            if (i < numFrames) {
                frames[i] = referenceString[i];
            } else {
                // Find the index of the least recently used page
                int usage[MAX_FRAMES] = {0};
                
                for (j = 0; j < numFrames; j++) {
                    for (k = i - 1; k >= 0; k--) {
                        if (frames[j] == referenceString[k]) {
                            usage[j] = i - k;
                            break;
                        }
                    }
                }
                
                // Find the least recently used page
                leastUsedIndex = 0;
                for (j = 1; j < numFrames; j++) {
                    if (usage[j] > usage[leastUsedIndex]) {
                        leastUsedIndex = j;
                    }
                }
                
                // Replace the least recently used page
                frames[leastUsedIndex] = referenceString[i];
            }
        }
        
        // Print current page frames
        for (j = 0; j < numFrames; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }
    
    printf("\nThe number of page faults is %d\n", pageFaults);
    
    return 0;
}
```

---

