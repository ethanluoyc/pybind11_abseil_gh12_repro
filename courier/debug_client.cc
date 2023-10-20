#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/pytypes.h>

#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "pybind11_abseil/absl_casters.h"
#include "pybind11_abseil/status_casters.h"

namespace courier {

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

namespace {

PYBIND11_MODULE(debug_client, m) {
  py::google::ImportStatusModule();

  m.def("add", &add, "A function that adds two numbers");

}

}  // namespace
}  // namespace courier
