#include <torch/extension.h>
#include <pybind11/pybind11.h>
#include <torch/torch.h>
#include <iostream>

torch::Tensor sigmoid(torch::Tensor z) {
  auto s = torch::sigmoid(z);
  return s;//(1 - s) * s;
}

PYBIND11_MODULE(libCTE, m) {
    m.doc() = "pybind11 a plugin to calculate sigmoid"; // optional module docstring
    m.def("sigmoid",
          &sigmoid,
          "a standard sigmoid");
}

/*

#include <cuda.h>
#include <cuda_runtime.h>

template <typename scalar_t>
__device__ __forceinline__ scalar_t sigmoid(scalar_t z) {
  return 1.0 / (1.0 + exp(-z));
}

*/