from sys import argv, exit
import cs50
import csv
import numpy as np


def main():
    # Get command line args
    if len(argv) != 2:
        print("Missing command line argument")
        exit(1)

    # Open db connection and clear table
    db = cs50.SQL("sqlite:///students.db")
    db.execute("delete from students;")

    dbst = csv.DictReader(argv[1])

    # Upload roster into database
    with open(argv[1], newline='') as csvfile:

        reader = csv.DictReader(csvfile)
        upload_data(data=reader, db=db)

# Functions


def upload_data(data, db):

    for row in data:
        parts = []

        parts.append(row["house"])
        parts.append(row["birth"])

        # Clean name field
        for part in row["name"].split(" "):
            parts.append(part)

        house = str(parts[0])
        birth = int(parts[1])
        first = str(parts[2])
        middle = str(np.where(len(parts) == 5, parts[3], ""))
        last = str(parts[-1])

        db.execute("insert into students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)
        db.execute("update students SET middle = NULLIF(middle, '') ")


# Execute main function
if __name__ == "__main__":
    main()
