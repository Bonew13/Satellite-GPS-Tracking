#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>


typedef struct user_t{  //user information scracture
    char user_name[255];
    double longitiude;
    double latitude;
    double altidude;
}our_user, other_ar[1];

int scan_user(int which); //function prototype
//int calculation(int num_of_others, struct user_t me, struct user_t them[]); //function prototype

/////////////////////////////Main/////////////////////////////////
int main(){

    int check;      
    printf("Hello, if you would like to import from a file, enter 0; if not, enter any integer number: ");
    scanf("%d", &check);
    if (check == 0){
        scan_user(1);
    }
    else{
        scan_user(0);
    }
    
    return 0;
} 

////////////////////Scan_User function///////////////////////////////
int scan_user(int which){
    int num_of_others = 1;
    struct user_t our_user;
    int i, longitiude, latitude, altidude;
    struct user_t other_ar[1]; //Create a an array of structures.
    struct user_t *pointer;
    pointer = other_ar; //create a pointer variable which points to the address at the beginning of the array
    int difference [1], num, smallest_difference, closest_num, posdifference;
    double diff;

    if (which == 0){

        printf("Hello Please enter the Name, Longitiude, Latitude, and Altitude of Our User: ");
        scanf("%s %lf %lf %lf", our_user.user_name, &our_user.longitiude, &our_user.latitude, &our_user.altidude); //Gets our user info
        printf(" %s %lf %lf %lf \n", our_user.user_name, our_user.longitiude, our_user.latitude, our_user.altidude);

        printf("How many other_users would you like? "); //How many other users will there be?
        scanf("%d", &num_of_others);

        pointer = malloc(num_of_others *sizeof(double)); //Use malloc to change size of array during run time

        for (int i = 0; i < num_of_others; i++){
            printf("Please enter Name, Longitiude, Latitude, and Altitude: other_User %d: ", i);
            scanf("%s%lf%lf%lf", other_ar[i].user_name, &other_ar[i].longitiude, &other_ar[i].latitude, &other_ar[i].altidude);
        }

        for (int i = 0; i < num_of_others; i++){
            printf(" %s %lf %lf %lf \n", other_ar[i].user_name, other_ar[i].longitiude, other_ar[i].latitude, other_ar[i].altidude);
        }

       //calculation(num_of_others, our_user, other_ar);
    
    } 
    
    //////////////////////////////////if user wants to use file//////////////////////////////
    else if (which == 1){
    char filename[255];
        printf("How many other users (not including our user) would you like to read from the text file: ");
        scanf("%d", &num_of_others);
        printf("Enter the text file name (less than 255 characters) \n");
        scanf("%s", filename);
        FILE *fp = fopen(filename, "r");

        if (fp != NULL){
           
            fscanf(fp, "%s", our_user.user_name); ////////////////////Gets our user information
            fscanf(fp, "%lf", &our_user.longitiude);
            fscanf(fp, "%lf", &our_user.latitude);
            fscanf(fp, "%lf", &our_user.altidude);
            printf(" %s %lf %lf %lf \n", our_user.user_name, our_user.longitiude, our_user.latitude, our_user.altidude);

            for (int i = 0; i<num_of_others; i++){

                fscanf(fp, "%s", other_ar[i].user_name);
                fscanf(fp, "%lf", &other_ar[i].longitiude);
                fscanf(fp, "%lf", &other_ar[i].latitude);
                fscanf(fp, "%lf", &other_ar[i].altidude);
                printf(" %s %lf %lf %lf \n", other_ar[i].user_name, other_ar[i].longitiude, other_ar[i].latitude, other_ar[i].altidude);
            }
        

           //calculation(num_of_others, our_user, other_ar);

        } else{
            printf("Error Opening File. Exiting Program.");
            exit(0);
        } 
    }
  

    return 0;
}

////////////////////////////////calculation function///////////////////////////////////////////////////////
int calculation (int num_of_others, struct user_t me, struct user_t them[]){
    double diff;
    double smallest = 999999;
    int i, longitiude, latitude, altidude;
    
        int index = -1;
        for (int i = 0; i < num_of_others; i++){
        //substraction of our user and the other user
            longitiude = (me.longitiude - them[i].longitiude);
            latitude = (me.latitude - them[i].latitude);
            altidude = (me.altidude - them[i].altidude);
            //(zcalcuation difference
            diff = sqrt((pow(longitiude, 2))+(pow(latitude, 2))+(pow(altidude, 2)));

            if(diff < smallest)
            {
                smallest = diff;
                index =i;
            } 
        }
        printf ("%s, %lf \n", them[index].user_name, smallest);
        double t = time(0);
         printf("The System Time in Nanoseconds is: %lf", t);\
         return 0;
    
} 