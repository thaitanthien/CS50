from sys import argv, exit
import csv
from cs50 import SQL

# Function that parse a name
def parse_name(fullname):
    names = fullname.split()
    return names if len(names) > 2 else [names[0], None, names[1]]


# Check command_line arguments
if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

csv_path = argv[1]

# Set up a database connection so Python scrip interact with SQL database
db = SQL("sqlite:///students.db")


# Open csv file
with open(csv_path, "r") as csv_file:
    reader = csv.DictReader(csv_file)

    # Iterate over CSV file
    for row in reader:

        # parse name
        names = parse_name(row["name"])

        # Insert each student into students table of students.db
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   names[0], names[1], names[2], row["house"], row["birth"])

