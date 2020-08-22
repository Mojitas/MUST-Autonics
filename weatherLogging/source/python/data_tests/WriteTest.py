import unittest
import os
import sys

delimiter = "\\" if sys.platform == "win32" else "/"  # OS Specific delimiter
root = os.getcwd().replace("%ssource%spython" % (delimiter, delimiter), "")  # Current Working Directory
directories = ["%sfigures" % delimiter, "%slogs" % delimiter]  # Directories used for logs and images


class WriteTest(unittest.TestCase):
    # Tests if the script has write access on root
    def test_rootIsWritable(self):
        self.assertTrue(os.access(root, os.W_OK), msg="No write access on project root!")

    # Tests if certain directories exists
    def test_directoriesExist(self):
        for i in directories:
            self.assertTrue(os.path.isdir(root + i), msg="No such directory: %s" % (root + i))

    # Tests if the script has write access in the directories
    def test_directoriesIsWritable(self):
        for i in directories:
            self.assertTrue(os.access(root + i, os.W_OK), msg="No write access on directory with path: %s" % (root + i))
