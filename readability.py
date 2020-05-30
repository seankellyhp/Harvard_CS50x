# Load dependencies
from cs50 import get_string

# Define a main function


def main():

    # Get user input
    t = get_string("Text:")

    # Calculate and return index
    index_out = cl_index(t)
    print_index(index_out)

# Functions


def count_letters(t):

    count = 0

    for i in range(len(t)):

        if t[i].isalpha():
            count += 1
        else:
            count += 0

    return count


def count_words(t):

    count = 1

    # Count the spaces
    for i in range(len(t)):
        if (t[i].isspace()):
            count += 1
        else:
            count += 0

    return count


def count_sentences(t):

    count = 0

    # Count the common sentence ends.
    for i in range(len(t)):

        t_cur = t[i]
        t_exc = '!'
        t_que = '?'
        t_per = '.'

        if (t_cur == t_exc or t_cur == t_que or t_cur == t_per):
            count += 1
        else:
            count += 0

    return count


def cl_index(t):

    # Run functions and apply algorithm
    letters_c = count_letters(t)
    words_c = count_words(t)
    sentences_c = count_sentences(t)

    avg_l = (letters_c / words_c) * 100
    avg_s = (sentences_c / words_c) * 100

    # Coleman-Liau formula for text complexity
    index = round((0.0588 * avg_l) - (0.296 * avg_s) - 15.8)

    return index


def print_index(index_out):

    # Print out a user friendly grade
    if index_out < 1:

        print("Before Grade 1")

    elif index_out >= 16:

        print("Grade 16+")

    else:

        print(f"Grade {index_out}")


# Execute main function
if __name__ == "__main__":
    main()
