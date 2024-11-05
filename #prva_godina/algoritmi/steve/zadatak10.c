#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char *companyName;
    char *status;
    char *jobTitle;
} job;

typedef struct
{
    int id;
    char *name;
    job job;
} user;


int main() {
    job dabidJob = {1, "Hoyoverse", "Working 24/7", "Beta-tester"};
    user david;
    david.id = 0;
    david.name = "David";
    david.job = dabidJob;

    printf("The main gacha user is %s with ID=%d and his job is %s for company\"%s\"\n", david.name, david.id, david.job.jobTitle, david.job.companyName);
    
    return 0;
}