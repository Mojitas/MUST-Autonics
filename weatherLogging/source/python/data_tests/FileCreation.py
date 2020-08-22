import unittest
import os
import pandas as pd
import sys

delimiter = "\\" if sys.platform == "win32" else "/"  # OS Specific delimiter
root = os.getcwd().replace("%ssource%spython" % (delimiter, delimiter), "")  # Current Working Directory
directories = ["%sfigures" % delimiter, "%slogs" % delimiter]  # Directories used for logs and images
fileNames = ["%stestFile.txt" % delimiter, "%slogFile.txt" % delimiter]  # Test files for creation and deletion


class FileCreation(unittest.TestCase):
    # Tests if we actually can create files, ignoring the fact that we may or may not have write access
    def test_createFiles(self):
        self.create_files()
        # Checks if the files were created
        for i in directories:
            for j in fileNames:
                self.assertTrue(os.path.exists(root + i + j), msg="Path doesn't exist: %s" % (root + i + j))

    # Tests if we actually can delete the files, ignoring the fact that we may or may not have write access
    def test_deleteFiles(self):
        self.delete_files()
        # checks if the files were deleted
        for i in directories:
            for j in fileNames:
                self.assertFalse(os.path.exists(root + i + j), msg="Path still exists: %s" % (root + i + j))

    # Deletes the files
    def delete_files(self):
        for i in directories:
            for j in fileNames:
                os.remove(root + i + j)

    # Creates the files
    def create_files(self):
        for i in directories:
            for j in fileNames:
                with open(root + i + j, "w") as f:
                    f.write("Hello World!")

    # Creates a 1.1 GB large file, takes up to 80 - 100 seconds to finish
    # The reason behind a 1.1 GB large dataframe is because sensor data in longer runs gets really huge
    # And we need to check that we can write 1.1 GB at least and test if the size is equal to following: 1178377784
    # The number is in bytes corresponding 1.178 GB to be exact
    # Lastly we remove the big file
    def test_largeFile(self):
        print("WARNING, LARGE FILE TEST MAY TAKE UP TO 100 SECONDS")
        df = pd.DataFrame(index=[c for c in range(100000)],
                          data={
                              i + 1: [c for c in range(100000)] for i in range(2000)
                          })
        fpath = root + directories[1] + fileNames[0].replace("txt", "csv")
        df.to_csv(fpath)
        self.assertTrue(os.path.exists(fpath))
        size = os.path.getsize(fpath)
        self.assertEqual(size, 1178377784, msg="The file is not correctly written.")
        os.remove(fpath)
        self.assertFalse(os.path.exists(fpath), msg="Path still exists!")
