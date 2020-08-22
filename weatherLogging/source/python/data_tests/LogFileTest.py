import unittest
import os
import pandas as pd


# Sets up each variable in the test that is necessary
# Four values:
# csvfile - a path to a csv file
# nrrows - number of rows in the csv file
# columns - an array of column names
# overview - a path to an image file preferably ending in .png
def setUpAndRun(csvfile, nrrows, columns, overview):
    LogFileTest.overview_file_path = overview
    LogFileTest.csv_nr_rows = nrrows
    LogFileTest.csv_file_path = csvfile
    LogFileTest.columns = columns
    unittest.main()


class LogFileTest(unittest.TestCase):
    csv_file_path = None
    csv_nr_rows = None
    overview_file_path = None
    columns = None

    def test_csvFile(self):
        # Check if the file really exists, should return true otherwise there is directory problems
        self.assertTrue(os.path.exists(self.csv_file_path))
        # Get the size of the csv file
        size = os.path.getsize(self.csv_file_path)
        # Check that the size is bigger than 0 else we have an empty file
        self.assertGreater(size, 0, msg="The file appears to be empty")
        # Read the csv file to memory
        df = pd.read_csv(self.csv_file_path)
        # Check if the number of columns are equal
        self.assertEqual(len(df.columns.values), len(self.columns), msg="Number of columns is not correct!")
        # Check that each column name is equal
        for i in self.columns:
            index = self.columns.index(i)
            self.assertEqual(i, df.columns.values[index])
        # Check that the number of rows are equal
        self.assertEqual(len(df.values), self.csv_nr_rows, msg="Number of rows does not match!")

    def test_overviewFile(self):
        # Check for a image file at a path nothing else
        self.assertTrue(os.path.exists(self.overview_file_path))
        # Get the size of the file
        size = os.path.getsize(self.overview_file_path)
        # Check if it's greater than 0 bytes
        self.assertGreater(size, 0, msg="The file doesn't appear to have anything in it!")
