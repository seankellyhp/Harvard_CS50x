#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){

float c;
do
    {
        c = get_float("How much change is owed? ");
    }
    while (c < 0);

// If Correct Input then convert to coins number

float c_adj = roundf(c * 100);

int amount = c_adj;
int coins [] = {1, 5, 10, 25};
int length = sizeof(coins) / sizeof(coins[0]);
int count = 0;

/// Turn into a function for style points

for (int i = length - 1; i >= 0; i --) {

  do {
  int n = amount/coins[i];

  if (n > 0) {
      //printf("amount: %i\n", amount);
      amount -= n * coins[i];
      //printf("coins: %i\n type: %i\n", n, coins[i]);
      count += n;
  }
  }
  while (amount >= coins[i] && amount >= 0);
}

printf("To make %.2f it takes a minimum of %i coins \n", c, count);
}


/// Optional Function
/*
void makeChange(int amount, int length) {

  int count = 0;
  for (int i = length - 1; i >= 0; i --) {

    do {
    int n = amount/coins[i];

    if (n > 0) {
        //printf("amount: %i\n", amount);
        amount -= n * coins[i];
        //printf("coins: %i\n type: %i\n", n, coins[i]);
        count += n;
    }
    }
    while (amount >= coins[i] && amount >= 0);
  }
  return count
}



int max_coin(int total, int length) {
  for(int i=0; i<length; i++){
      if(total > coins[i]) return i-1;
  }
  return -1;
}

int coin_amount(int total, int change[]) {

    int length = sizeof(coins)/sizeof(coins[0]);
    int count = 0;
    while(total){
        int k = max_coin(total, length);
        if(k == -1) {
                printf("No Solution");
                break;
        } else {
                total -= coins[k];
        change[count++] = coins[k];
            }
    }
    return count;
}
*/
