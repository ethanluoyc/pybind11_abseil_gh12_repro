load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")

licenses(["notice"])

package(
    default_visibility = ["//visibility:public"],
)

pybind_extension(
    name = "debug_client",
    srcs = [
        "debug_client.cc",
    ],
    deps = [
        "@pybind11_abseil//pybind11_abseil:absl_casters",
        "@pybind11_abseil//pybind11_abseil:status_casters",
    ],
)

py_binary(
    name = "debug_client_test",
    srcs = ["debug_client_test.py"],
    data = [
        ":debug_client.so",
    ]
)
