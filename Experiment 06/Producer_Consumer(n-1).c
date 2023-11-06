#include <stdio.h>

#define MAX 50
#define SIZE 5

int in = 0;
int out = 0;
int full = 0;
int empty = SIZE;
int mutex = 1;
int buffer[MAX];

int signal(int s) {
    return ++s;
}

int wait(int s) {
    while (s < 0) { // why are we using while if we are going to return s?
        return s;
    }
    return --s;
}

void producer() {
    int item;

    mutex = wait(mutex);
    empty = wait(empty);

    if((in + 1) % SIZE == out) {
        printf("Buffer is full\n");
        mutex = signal(mutex);
        empty = signal(empty);
    }
    else {
        printf("Enter the item to be produced : ");
        scanf("%d", &item);

        buffer[in] = item;
        printf("produced %d at location %d\n", item, in);

        in = (in + 1) % SIZE;
        mutex = signal(mutex);
        full = signal(full);
    }
}
void consumer() {
    int item;

    mutex = wait(mutex);
    full = wait(full);

    if(in == out) {
        printf("Buffer is Empty\n");
        mutex = signal(mutex);
        full = signal(full);
    }
    else {
        item = buffer[out];
        out = (out + 1) % SIZE;
        printf("Consumed %d\n", item);
        mutex = signal(mutex);
        empty = signal(empty);
    }
}

int main() {
    int choice;
    int execute = 1;

    while(execute) {
        printf("1)Produce\n2)Consume\n3)Exit\nEnter : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                execute = 0;
                break;
            default:
            printf("Invalid operation\n");
        }
    }
    return 0;
}

