import sys
import unittest
import torch

try:
    import cte.build.lib.libCTE as libCTE
except ImportError:
    print("Could not find 'libCTE'.")
    sys.exit(1)


class TestSigmoid(unittest.TestCase):
    def test_cpp_impl(self):
        x = torch.linspace(-10, 10, 100)
        sigmoid_pytorch = torch.sigmoid(x)
        sigmoid_cpp = libCTE.sigmoid(x)

        diff = (sigmoid_pytorch - sigmoid_cpp).abs().max()
        self.assertLess(diff, 1e-4)  # add assertion here


if __name__ == '__main__':
    unittest.main()
