import unittest, time, subprocess


class PerformanceTest(unittest.TestCase):
    path = '../cmake-build-debug/sample'

    def print_time(self, message):
        print('{}: {:.3f}s'.format(message, time.clock() - self.start))

    def setUp(self):
        self.start = time.clock()

    def test_single_core(self):
        p = subprocess.Popen((self.path, '1'), stdout=subprocess.PIPE)
        p.communicate()[0].decode('utf-8')
        self.print_time('Single')

    def test_multiple_core(self):
        p = subprocess.Popen((self.path, '4'), stdout=subprocess.PIPE)
        p.communicate()[0].decode('utf-8')
        self.print_time('Multi')


if __name__ == '__main__':
    unittest.main()
