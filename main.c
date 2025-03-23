/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>

#define MAX_ROOMS 5  //  max number of rooms

// Function prototypes
void initializeSystem(int rooms, int light[],int temperature[],int motion[], int lock[]);
void displayMenu();
void controlLights(int rooms, int lights[]);
void readTemperature(int rooms, int temperature[]);
void detectMotion(int rooms,int motion[]);
void securitySystem(int rooms, int lock[]);
void analyzeHouseStatus(int rooms, int light[],int temperature[],int motion[], int lock[]);

int main() {
    int rooms,choice;
    printf("Enter the Number of Rooms: ");
    scanf("%d",&rooms);
    int light[rooms],temperature[rooms], motion[rooms],lock[rooms];
    if (rooms>MAX_ROOMS || rooms<1){
       printf("Invalid number of rooms"); 
    }
    initializeSystem(rooms,light,temperature,motion,lock);
    do{
        displayMenu();
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        
        switch (choice) {
            case 1:
                controlLights(rooms,light);
                break;
            case 2:
                readTemperature(rooms, temperature);
                break;
            case 3:
                detectMotion(rooms,motion);
                break;
            case 4:
                securitySystem(rooms,lock);
                break;
            case 5:
                analyzeHouseStatus(rooms,light,temperature,motion,lock);
                break;
            case 6:
                printf("Exiting System.... Thank You...");
                break;
            default:
                printf("Invalid Choice!");
                break;
    
        }
    }while (choice!=6);
    
}

 
void initializeSystem(int rooms, int light[],int temperature[],int motion[], int lock[]) {
    printf("Initializing System...");
    for(int i=0;i<rooms; i++){
        light[i]=0;
        temperature[i]=23+i;
        motion[i]=0;
        lock[i]=1;
    }
    printf("System Initialized");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights(int rooms, int lights[]) {
    int room_number, index;
    printf("Enter the room to toggle light: ");
    scanf("%d",&room_number);
    index=room_number-1;
    if(room_number<1 || room_number>rooms){
        printf("Invalid Room Number!");
    }
    else{
        lights[index]=!lights[index];
        if(lights[index]==1){
            printf("Light in Room %d is now ON",room_number);
        }
        else{
            printf("Lights in Room %d is now OFF",room_number);
        }
    }
}

void readTemperature(int rooms, int temperature[]) {
    int room_number,index;
    printf("Enter the room to read temperature: ");
    scanf("%d",&room_number);
    index=room_number-1;
    if(room_number<1 || room_number>rooms){
        printf("Invalid Room Number!");
    }
    else{
        printf("The temperatire of Room %d is %d",room_number,temperature[index]);  
        if(temperature[index]>30){
            printf("Warning! The Temperature of Room %d is greater than 30 degrees");
        }
    }
}
void detectMotion(int rooms,int motion[]) {
    int room_number,index;
    printf("Enter the room to read temperature: ");
    scanf("%d",&room_number);
    index=room_number-1;
    if(room_number<1 || room_number>rooms){
        printf("Invalid Room Number!");
    }
    else{
        int motiondetected;
        printf("Is any motion detected in Room %d... Enter 1 for Yes and 0 for No");
        scanf("%d",&motiondetected);
        motion[index]=motiondetected;
    }

}
void securitySystem(int rooms, int lock[]) {
    int room_number,index;
    printf("Enter the room to read temperature: ");
    scanf("%d",&room_number);
    index=room_number-1;
    if(room_number<1 || room_number>rooms){
        printf("Invalid Room Number!");
    }
    else{
        lock[index]=!lock[index];
        if(lock[index]==1){
            printf("Room %d is now UNLOCKED",room_number);
        }
        else{
            printf("Room %d is now LOCKED",room_number);
        }
    }
}
void analyzeHouseStatus(int rooms, int light[],int temperature[],int motion[], int lock[] ) {
    printf("House Status");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s, %s\n",i + 1,light[i] ? "ON" : "OFF",temperature[i],motion[i] ? "Motion Detected" : "No Motion",lock[i] ? "Locked" : "Unlocked");
    }

}
