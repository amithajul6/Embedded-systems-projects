/*Traffic light control system*/


#include <stdio.h>
#include <unistd.h>

// Define states for the traffic light state machine
typedef enum {
    GREEN_ROAD1,
    YELLOW_ROAD1,
    RED_ROAD1,
    GREEN_ROAD2,
    YELLOW_ROAD2,
    RED_ROAD2
} TrafficLightState;

// Function to simulate the traffic light sequence
void operateTrafficLight(TrafficLightState initial_state) {
    TrafficLightState current_state = initial_state;

    while (1) {
        switch (current_state) {
            case GREEN_ROAD1:
                printf("North-South Main Road: Green\n");
                sleep(30); // Green light duration
                current_state = YELLOW_ROAD1;
                break;

            case YELLOW_ROAD1:
                printf("North-South Main Road: Yellow\n");
                sleep(5); // Yellow light duration
                current_state = RED_ROAD1;
                break;

            case RED_ROAD1:
                printf("North-South Main Road: Red\n");
                sleep(30); // Red light duration
                current_state = GREEN_ROAD2;
                break;

            case GREEN_ROAD2:
                printf("East-West Side Road: Green\n");
                sleep(20); // Green light duration for side road
                current_state = YELLOW_ROAD2;
                break;

            case YELLOW_ROAD2:
                printf("East-West Side Road: Yellow\n");
                sleep(5); // Yellow light duration
                current_state = RED_ROAD2;
                break;

            case RED_ROAD2:
                printf("East-West Side Road: Red\n");
                sleep(30); // Red light duration
                current_state = GREEN_ROAD1;
                break;

            default:
                // Handle unexpected state
                break;
        }
    }
}

int main() {
    // Start the traffic light control system with an initial state
    operateTrafficLight(GREEN_ROAD1);

    return 0;
}
