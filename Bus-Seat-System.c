#include <stdio.h>
#include <stdlib.h>

struct SeatStruct{
	int person; 					// seating a person
	struct SeatStruct *next;
};
typedef struct SeatStruct *Seat;

struct BusStruct{
	int totalseats;
	int count;
	Seat last; 						//last seat, that is taken
};
typedef struct BusStruct *Bus;

//constructor function Seat
Seat NewSeat(int p){
	Seat new = malloc(sizeof(*Seat));
	new->person = p;
	return new;
}

//constructor function bus
Bus makeBus(int totalseats){
	Bus newb = malloc(sizeof(*Bus));
	newb->totalseats = totalseats;
	newb->count = 0;
	return newb;
}

int empty(Bus newb){
	if(newb->count == 0){
		return 1;
	}else{
		return 0;
	}
}

Bus assignSeat(Bus b, int p){
	if(b->count == b->totalseats){
		printf("Bus is full!");
		exit(-1);
	}
	Seat s = NewSeat(p);
	if(b->count == 0){
		b->last = s;
	}else{
		(b->last)->next = s;
		b->last = s;
	}
	b->count++;
	return b;
}

void freeSeats(Bus b){
	int freeseats = b->totalseats - b->count;
	if(b->totalseats == b->count){
		printf("This Bus is full - there are no more seats available!");
	}else{
		printf("There %d seats free", freeseats);
	}
	return;
}
	

	

int main(void){
	
	return 0;
}