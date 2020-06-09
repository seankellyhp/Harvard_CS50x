from sys import argv, exit
import cs50


def main():
    # Get command line args
    if len(argv) != 2:
        print("Missing command line argument")
        exit(1)

    houses = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]

    # Check for correct input
    houses_l = []
    for i in range(len(houses)):
        houses_l.append(houses[i].lower())

    # If not, return error
    if argv[1].lower() not in houses_l:
        print(f"Provide {houses[0]}, {houses[1]}, {houses[2]} or {houses[3]} as command line argument")
        exit(1)
    else:
        house_f = argv[1]

        db = cs50.SQL("sqlite:///students.db")

        # Pass house name into select
        return_house(house_f, db)

# Functions


def return_house(house, db):
    roster = db.execute("select first, middle, last, birth from students where house = ? order by last, first", house.capitalize())

    for row in roster:

        if row['middle'] == None:
            print(f"{row['first']} {row['last']}, born {row['birth']}")
        else:
            print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")


# Execute main function
if __name__ == "__main__":
    main()
