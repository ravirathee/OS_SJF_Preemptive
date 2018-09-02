//Ravi Rathee
//OS_ShortestJobFirst_Pre-emptive

#include <stdio.h>

int main() {
    int n = 0, i = 0;

    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("\nNumber of processes entered : %d\n", n);

    int AT[20] = {0};                           //Arrival Time
    int BT[20] = {0};                           //Burst   Time
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

/*
OUTPUT

/Users/ravirathee/CLionProjects/OS_SJF_Preemptive/cmake-build-debug/OS_SJF_Preemptive
Enter the number of processes : 4

Number of processes entered : 4

Enter Arrival time of processes:
0
1
2
3
Arrival Time: 0 1 2 3

Enter Burst time of processes :
8
4
9
5



Processes Arrived : 1
Time : 0
Smallest : 8
Smallest_pos : 0
Remaining Time: 7 4 9 5
Completion Time: 0 0 0 0


Processes Arrived : 2
Time : 1
Smallest : 4
Smallest_pos : 1
Remaining Time: 7 3 9 5
Completion Time: 0 0 0 0


Processes Arrived : 3
Time : 2
Smallest : 3
Smallest_pos : 1
Remaining Time: 7 2 9 5
Completion Time: 0 0 0 0


Processes Arrived : 4
Time : 3
Smallest : 2
Smallest_pos : 1
Remaining Time: 7 1 9 5
Completion Time: 0 0 0 0


Processes Arrived : 4
Time : 4
Smallest : 1
Smallest_pos : 1
Remaining Time: 7 0 9 5
Completion Time: 0 5 0 0


Processes Arrived : 4
Time : 5
Smallest : 5
Smallest_pos : 3
Remaining Time: 7 0 9 4
Completion Time: 0 5 0 0


Processes Arrived : 4
Time : 6
Smallest : 4
Smallest_pos : 3
Remaining Time: 7 0 9 3
Completion Time: 0 5 0 0


Processes Arrived : 4
Time : 7
Smallest : 3
Smallest_pos : 3
Remaining Time: 7 0 9 2
Completion Time: 0 5 0 0


Processes Arrived : 4
Time : 8
Smallest : 2
Smallest_pos : 3
Remaining Time: 7 0 9 1
Completion Time: 0 5 0 0


Processes Arrived : 4
Time : 9
Smallest : 1
Smallest_pos : 3
Remaining Time: 7 0 9 0
Completion Time: 0 5 0 10


Processes Arrived : 4
Time : 10
Smallest : 7
Smallest_pos : 0
Remaining Time: 6 0 9 0
Completion Time: 0 5 0 10


Processes Arrived : 4
Time : 11
Smallest : 6
Smallest_pos : 0
Remaining Time: 5 0 9 0
Completion Time: 0 5 0 10


Processes Arrived : 4
Time : 12
Smallest : 5
Smallest_pos : 0
Remaining Time: 4 0 9 0
Completion Time: 0 5 0 10


Processes Arrived : 4
Time : 13
Smallest : 4
Smallest_pos : 0
Remaining Time: 3 0 9 0
Completion Time: 0 5 0 10


Processes Arrived : 4
Time : 14
Smallest : 3
Smallest_pos : 0
Remaining Time: 2 0 9 0
Completion Time: 0 5 0 10


Processes Arrived : 4
Time : 15
Smallest : 2
Smallest_pos : 0
Remaining Time: 1 0 9 0
Completion Time: 0 5 0 10


Processes Arrived : 4
Time : 16
Smallest : 1
Smallest_pos : 0
Remaining Time: 0 0 9 0
Completion Time: 17 5 0 10


Processes Arrived : 4
Time : 17
Smallest : 9
Smallest_pos : 2
Remaining Time: 0 0 8 0
Completion Time: 17 5 0 10


Processes Arrived : 4
Time : 18
Smallest : 8
Smallest_pos : 2
Remaining Time: 0 0 7 0
Completion Time: 17 5 0 10


Processes Arrived : 4
Time : 19
Smallest : 7
Smallest_pos : 2
Remaining Time: 0 0 6 0
Completion Time: 17 5 0 10


Processes Arrived : 4
Time : 20
Smallest : 6
Smallest_pos : 2
Remaining Time: 0 0 5 0
Completion Time: 17 5 0 10


Processes Arrived : 4
Time : 21
Smallest : 5
Smallest_pos : 2
Remaining Time: 0 0 4 0
Completion Time: 17 5 0 10


Processes Arrived : 4
Time : 22
Smallest : 4
Smallest_pos : 2
Remaining Time: 0 0 3 0
Completion Time: 17 5 0 10


Processes Arrived : 4
Time : 23
Smallest : 3
Smallest_pos : 2
Remaining Time: 0 0 2 0
Completion Time: 17 5 0 10


Processes Arrived : 4
Time : 24
Smallest : 2
Smallest_pos : 2
Remaining Time: 0 0 1 0
Completion Time: 17 5 0 10


Processes Arrived : 4
Time : 25
Smallest : 1
Smallest_pos : 2
Remaining Time: 0 0 0 0
Completion Time: 17 5 26 10
Completion Time: 17 5 26 10
Turn Around Time: 17 4 24 7
Waiting Time: 9 0 15 2

Average Turn Around Time : 13.000000
Average Waiting Time : 6.500000
Process finished with exit code 0

*/