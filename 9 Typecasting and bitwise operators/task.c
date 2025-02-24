#include <stdio.h>
#include <stdint.h>

void switchLights(uint8_t *state, int room) {
    *state ^= (1 << (room - 1));
}

void printState(uint8_t state) {
    printf("The light is on in rooms: ");
    for (int i = 0; i < 8; i++) {
        if (state & (1 << i)) { 
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main() {
    uint8_t state = 0; 
    int choice, room;
    while (1) {
        printf("Lighting Control:\n");
        printf("1. Switch lights\n");
        printf("2. Print state of lights\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number (1-8): ");
                scanf("%d", &room);
                if (room < 1 || room > 8) {
                    printf("Invalid room number. Please enter a number between 1 and 8.\n");
                } else {
                    switchLights(&state, room);
                    printf("The light in room %d has been toggled.\n", room);
                }
                break;

            case 2:
                printState(state);
                break;

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid option. Please choose 1, 2, or 3.\n");
                break;
        }
    }

    return 0;
}
