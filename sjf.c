#include <stdio.h>
// #include <stdlib.h>
void wait_time(int n, int burst_time[], int waiting_time[]);
void turnaround_timer(int n, int burst_time[], int waiting_time[], int turnaround_time[]);
void avgtime(int n, int proc[],int burst_time[]);
void sort(int n, int proc[], int burst_time[]);

int main(){
    int proc[] = {1,2,3};
    int burst_time[] = {12,3,4};
    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    printf("Enter the processes\n");
    for(int i = 0; i<n; i++)
        scanf("%d", &proc[i]);
    printf("\nEnter the burst times\n");
    for(int i =0; i<n;i++)
        scanf("%d", &burst_time[i]);
    // int n = sizeof(proc)/sizeof(proc[0]);
    sort(n, proc, burst_time);
    avgtime(n,proc, burst_time);
    return 0;
}

void wait_time(int n, int burst_time[], int waiting_time[]){
    int sum = 0;
    int i;
    for(i=0;i<n;i++){
        waiting_time[i] = sum;
        sum+= burst_time[i];
    }
    waiting_time[i] = sum;
}

void turnaround_timer(int n, int burst_time[], int waiting_time[], int turnaround_time[]){
    for(int i=0; i<n; i++){
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
}

void sort(int n, int proc[], int burst_time[]){
    int temp = 0;
    for(int i = 0;i<n; i++){
        for(int j = i;j<n;j++)
        if(burst_time[i]>burst_time[j]){
            temp = burst_time[j];
            burst_time[j] = burst_time[i];
            burst_time[i] = temp;
            temp = proc[j];
            proc[j] = proc[i];
            proc[i] = temp;
        }
    }
}

void avgtime(int n, int proc[], int burst_time[]){
    int waiting_time[n];
    int turnaround_time[n];
    float avg_wait, avg_tat;
    wait_time(n, burst_time, waiting_time);
    turnaround_timer(n, burst_time, waiting_time, turnaround_time);
    int sum_wait = 0;
    int sum_tat = 0;
    for(int i = 0; i<n; i++){
        sum_wait += waiting_time[i];
        sum_tat += turnaround_time[i];
    }
    avg_tat = (float) sum_tat/n;
    avg_wait =(float) sum_wait/n;
    printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\n",proc[i],burst_time[i], waiting_time[i],turnaround_time[i]);
    }
    printf("\nAverage waiting time is: %f", avg_wait);
    printf("\nAverage turn-around time is: %f", avg_tat);
}