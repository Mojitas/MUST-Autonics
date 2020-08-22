import unittest

# Define testcases found in data_tests directory/module here
tests = ["data_tests.WriteTest", "data_tests.ReadTest", "data_tests.FileCreation"]


# Call this function to run all tests defined above
def run_data_tests():
    for i in tests:
        suite = unittest.TestLoader().loadTestsFromName(i)
        result = unittest.TextTestRunner(verbosity=2).run(suite)
        if len(result.failures) > 0:
            exit(1)
