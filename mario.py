# Load dependencies
from cs50 import get_int

# Define a main function


def main():

    # Ask user for number
    n = get_positive_int()

    for i in range(1, n + 1):
        nHash = i
        nDot = n - i

    # Draw shape
        for j in range(nDot):
            print(" ", end="")

    # Create newline if last hash
        for k in range(nHash):
            if k < (nHash - 1):
                print("#", end="")
            elif k == nHash - 1:
                print("#")

# Function


def get_positive_int():
    while True:
        n = get_int("Height: ")
        if n >= 1 and n <= 8:
            break
    return n


# Execute main function
if __name__ == "__main__":
    main()
