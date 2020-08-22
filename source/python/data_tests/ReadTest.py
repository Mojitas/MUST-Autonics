import unittest
import os
import sys

delimiter = "\\" if sys.platform == "win32" else "/"  # OS specific delimiter
root = os.getcwd().replace("%ssource%spython" % (delimiter, delimiter), "")  # Current working directory
directories = ["%sfigures" % delimiter, "%slogs" % delimiter]  # Directories used for logs and images


class ReadTest(unittest.TestCase):
    # Tests if we can read on root of the project
    def test_rootIsReadable(self):
        self.assertTrue(os.access(root, os.R_OK), msg="No read acces on project root")

    # Tests if the directories exists
    def test_directoriesExist(self):
        for i in directories:
            self.assertTrue(os.path.exists(root + i), msg="Path does not exist: %s" % (root + i))

    # Tests if we have read access in the directories
    def test_directoryReadAccess(self):
        for i in directories:
            self.assertTrue(os.access(root + i, os.R_OK), msg="Subdirectory is not writable %s" % (root + i))
