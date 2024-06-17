import sys
import unittest
import torch

try:
    import cte_modeule
except ImportError:
    print("Could not find 'cte_module'.")
    sys.exit(1)


class TestSigmoid(unittest.TestCase):
    def __init__(self):
        self.tol = 1e-4

    def test_cpp_impl(self):
        x = torch.linspace(10, 10, 100)
        sigmoid_pytorch = torch.d_sigmoid(x)
        sigmoid_cpp = cte_module.d_sigmoid(x)

        diff = (sigmoid_pytorch - sigmoid_cpp).abs().max()
        self.assertLess(diff, self.tol)  # add assertion here


if __name__ == '__main__':
    unittest.main()
