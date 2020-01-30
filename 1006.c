/**
 * 1006 Sign In and Sign Out
 * 
 * At the beginning of every day, the first person who signs in the computer room will unlock the door, 
 * and the last one who signs out will lock the door. Given the records of signing in's and out's, 
 * you are supposed to find the ones who have unlocked and locked the door on that day.
 * 
 * Input Specification:
 * Each input file contains one test case. Each case contains the records for one day. 
 * The case starts with a positive integer M, which is the total number of records, followed by M lines, 
 * each in the format:
 * ID_number Sign_in_time Sign_out_time
 * where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.
 * 
 * Output Specification:
 * For each test case, 
 * output in one line the ID numbers of the persons who have unlocked and locked the door on that day. 
 * The two ID numbers must be separated by one space.
 * Note: It is guaranteed that the records are consistent. 
 * That is, the sign in time must be earlier than the sign out time for each person, 
 * and there are no two persons sign in or out at the same moment.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char unlockPeople[20];
    char lockPeople[20];
    char currentPeople[20];
    int unlockTime[3] = {24, 24, 24};
    int lockTime[3] = {0, 0, 0};
    int currentUnlockTime[3];
    int currentLockTime[3];
    int i, M;
    scanf("%d", &M);
    for(i = 0; i < M; i ++)
    {
        scanf("%s %d:%d:%d %d:%d:%d", currentPeople, &currentUnlockTime[0], &currentUnlockTime[1], &currentUnlockTime[2], &currentLockTime[0], &currentLockTime[1], &currentLockTime[2]);
        if(currentUnlockTime[0] < unlockTime[0])
        {
            strcpy(unlockPeople, currentPeople);
            unlockTime[0] = currentUnlockTime[0];
            unlockTime[1] = currentUnlockTime[1];
            unlockTime[2] = currentUnlockTime[2];
        } else if(currentUnlockTime[0] == unlockTime[0])
        {
            if(currentUnlockTime[1] < unlockTime[1])
            {
                strcpy(unlockPeople, currentPeople);
                unlockTime[0] = currentUnlockTime[0];
                unlockTime[1] = currentUnlockTime[1];
                unlockTime[2] = currentUnlockTime[2];
            } else if(currentUnlockTime[1] == unlockTime[1])
            {
                if(currentUnlockTime[2] < unlockTime[2])
                {
                    strcpy(unlockPeople, currentPeople);
                    unlockTime[0] = currentUnlockTime[0];
                    unlockTime[1] = currentUnlockTime[1];
                    unlockTime[2] = currentUnlockTime[2];
                }
            }
        }

        if(currentLockTime[0] > lockTime[0])
        {
            strcpy(lockPeople, currentPeople);
            lockTime[0] = currentLockTime[0];
            lockTime[1] = currentLockTime[1];
            lockTime[2] = currentLockTime[2];
        } else if(currentLockTime[0] == lockTime[0])
        {
            if(currentLockTime[1] > lockTime[1])
            {
                strcpy(lockPeople, currentPeople);
                lockTime[0] = currentLockTime[0];
                lockTime[1] = currentLockTime[1];
                lockTime[2] = currentLockTime[2];
            } else if(currentLockTime[1] == lockTime[1])
            {
                if(currentLockTime[2] > lockTime[2])
                {
                    strcpy(lockPeople, currentPeople);
                    lockTime[0] = currentLockTime[0];
                    lockTime[1] = currentLockTime[1];
                    lockTime[2] = currentLockTime[2];
                }
            }
        }
    }
    printf("%s %s\n", unlockPeople, lockPeople);
    return 0;
}