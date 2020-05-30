# Load dependencies
from cs50 import get_float
from math import floor

# Define a main function


def main():

    # Ask for change owed
    c = change_owed()
    amount = floor(c * 100)

    # Get coin options
    coins = [1, 5, 10, 25]

    # Get minimum count of coins
    count = min_change(amount, coins)

    print(count)



# Functions
def change_owed():
    while True:
        n = get_float("Change owed: ")
        if n >= 0:
            break
    return n


def min_change(amount, coins=[]):

    count = 0

    # Start at highest coin and go down
    for i in reversed(range(len(coins))):

        while True:

            n = floor(amount/coins[i])

            if n > 0:
                amount -= n * coins[i]
                count += n

            #print(f"It will take {n} total {coins[i]} cent coins.")

            if amount < coins[i] and amount >= 0:
                break

    return count


# Execute main function
if __name__ == "__main__":
    main()
