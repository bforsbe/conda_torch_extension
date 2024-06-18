// #include <torch/extension.h>
#include <pybind11/pybind11.h>
#include <torch/torch.h>
#include <iostream>

torch::Tensor d_sigmoid(torch::Tensor z) {
  auto s = torch::sigmoid(z);
  return (1 - s) * s;
}

PYBIND11_MODULE(cte_module, m) {
    m.doc() = "pybind11 a plugin to calculate sigmoid derivative"; // optional module docstring
    m.def("d_sigmoid",
          &d_sigmoid,
          "derviative of sigmoid");
}

/*

#include <cuda.h>
#include <cuda_runtime.h>

template <typename scalar_t>
__device__ __forceinline__ scalar_t sigmoid(scalar_t z) {
  return 1.0 / (1.0 + exp(-z));
}

*/