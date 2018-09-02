//Ravi Rathee
//OS_ShortestJobFirst_Pre-emptive
#include <stdio.h>

int main() {
    int n = 0, i = 0;

    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("\nNumber of processes entered : %d\n", n);

    int AT[20] = {0}, at_i = 0;                 //Arrival Time
    int BT[20] = {0}, bt_i = 0;                 //Burst   Time
    int P[20] = {0}, p_i = 0;                   //Priority
    int RT[20] = {0};                           //Remaining Time
    int CT[20] = {0};                           //Completion Time
    int TAT[20] = {0};                          //Turn-Around Time
    int WT[20] = {0};                           //Waiting Time
    int time = 0;                               //current time
    int count = 0;                              //current process
    int remain = n;                             //remain processes with rt>0
    int processes_arrived = 0;                  //processes arrived
    int smallest = 0;
    int smallest_pos = 0;



    //Input Arrival Time
    printf("\nEnter Arrival time of processes: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &AT[i]);
    }

    printf("Arrival Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", AT[i]);
    }

    // Input Burst Time
    printf("\n\nEnter Burst time of processes : \n");

    for (i = 0; i < n; i++) {
        scanf("%d", &BT[i]);
        RT[i] = BT[i];
    }



    for (time = 0; remain != 0 && time < 40; time++) {

        for (i = 0; i < n; i++) {
            if (AT[i] == time) {
                processes_arrived += 1;
            }
        }

        smallest = 999999;
        smallest_pos = -1;

        for (i = 0; i < processes_arrived; i++) {
            if (RT[i] > 0) {
                if (smallest > RT[i]) {
                    smallest = RT[i];
                    smallest_pos = i;
                }
            }
        }

        count = smallest_pos;
        RT[count]-=1;

        if (RT[count] == 0) {
            remain--;
            CT[count] = time+1;
            TAT[count] = CT[count] - AT[count];
            WT[count] = TAT[count] - BT[count];
        }


        printf("\n\n\nProcesses Arrived : %d", processes_arrived);
        printf("\nTime : %d", time);
        printf("\nSmallest : %d", smallest);
        printf("\nSmallest_pos : %d", smallest_pos);

        printf("\nRemaining Time: ");
        for (i = 0; i < n; i++) {
            printf("%d ", RT[i]);
        }

        printf("\nCompletion Time: ");
        for (i = 0; i < n; i++) {
            printf("%d ", CT[i]);
        }

    }

    printf("\nCompletion Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", CT[i]);
    }

    printf("\nTurn Around Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", TAT[i]);
    }

    printf("\nWaiting Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", WT[i]);
    }

    printf("\n\nAverage Turn Around Time : ");
    float sum_TAT = 0;
    float avg_TAT = 0;
    for (i = 0; i < n; i++) {
        sum_TAT+=TAT[i];
    }
    avg_TAT = sum_TAT/n;
    printf("%4f",avg_TAT);

    printf("\nAverage Waiting Time : ");
    float sum_WT = 0;
    float avg_WT = 0;
    for (i = 0; i < n; i++) {
        sum_WT+=WT[i];
    }
    avg_WT = sum_WT/n;
    printf("%4f",avg_WT);


    return 0;
}