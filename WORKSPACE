workspace(name = "debug-pybind11")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "bazel_skylib",
    sha256 = "66ffd9315665bfaafc96b52278f57c7e2dd09f5ede279ea6d39b2be471e7e3aa",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.4.2/bazel-skylib-1.4.2.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.4.2/bazel-skylib-1.4.2.tar.gz",
    ],
)

# https://github.com/tensorflow/tensorflow/blob/v2.14.0/third_party/absl/workspace.bzl#L10-L12
http_archive(
    name = "com_google_absl",
    sha256 = "8eeec9382fc0338ef5c60053f3a4b0e0708361375fe51c9e65d0ce46ccfe55a7",  # SHARED_ABSL_SHA
    strip_prefix = "abseil-cpp-b971ac5250ea8de900eae9f95e06548d14cd95fe",
    urls = [
        # "https://storage.googleapis.com/mirror.tensorflow.org/github.com/abseil/abseil-cpp/archive/b971ac5250ea8de900eae9f95e06548d14cd95fe.tar.gz",
        "https://github.com/abseil/abseil-cpp/archive/b971ac5250ea8de900eae9f95e06548d14cd95fe.tar.gz",
    ],
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

# https://github.com/tensorflow/tensorflow/blob/v2.14.0/third_party/pybind11_bazel/workspace.bzl#L9C5-L17
PB_COMMIT = "72cbbf1fbc830e487e3012862b7b720001b70672"
PB_SHA256 = "516c1b3a10d87740d2b7de6f121f8e19dde2c372ecbfe59aef44cd1872c10395"
http_archive(
    name = "pybind11_bazel",
    strip_prefix = "pybind11_bazel-{commit}".format(commit = PB_COMMIT),
    sha256 = PB_SHA256,
    # patch_file = ["//third_party/pybind11_bazel:pybind11_bazel.patch"],
    urls = ["https://github.com/pybind/pybind11_bazel/archive/{commit}.tar.gz".format(commit = PB_COMMIT)],
)

http_archive(
    name = "pybind11",
    build_file = "@pybind11_bazel//:pybind11.BUILD",
    sha256 = "832e2f309c57da9c1e6d4542dedd34b24e4192ecb4d62f6f4866a737454c9970",
    strip_prefix = "pybind11-2.10.4",
    urls = [
        "https://storage.googleapis.com/mirror.tensorflow.org/github.com/pybind/pybind11/archive/v2.10.4.tar.gz",
        "https://github.com/pybind/pybind11/archive/v2.10.4.tar.gz",
    ],
)

load("@//third_party:python_configure.bzl", "python_configure")
python_configure(name = "local_config_python")

# https://github.com/tensorflow/tensorflow/blob/v2.14.0/third_party/pybind11_abseil/workspace.bzl#L10-L13
http_archive(
    name = "pybind11_abseil",
    sha256 = "0223b647b8cc817336a51e787980ebc299c8d5e64c069829bf34b69d72337449",
    strip_prefix = "pybind11_abseil-2c4932ed6f6204f1656e245838f4f5eae69d2e29",
    urls = [
        "https://github.com/pybind/pybind11_abseil/archive/2c4932ed6f6204f1656e245838f4f5eae69d2e29.tar.gz",
    ],
)

# local_repository(
#     name = "pybind11_abseil",
#     path = "./third_party/pybind11_abseil",
# )


http_archive(
    name = "hedron_compile_commands",
    strip_prefix = "bazel-compile-commands-extractor-ed994039a951b736091776d677f324b3903ef939",
    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/ed994039a951b736091776d677f324b3903ef939.tar.gz",
    # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'hedron_compile_commands' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()
