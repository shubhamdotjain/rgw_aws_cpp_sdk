
Prerequsites
============

To build and run these examples, you'll need:

* CMake (version 2.8+)
* AWS SDK for C++ (downloaded, extracted and built on your machine)
  http://docs.aws.amazon.com/sdk-for-cpp/v1/developer-guide/setup.html
* AWS credentials, either configured in a local AWS credentials file or by setting the
  AWS_ACCESS_KEY_ID and AWS_SECRET_ACCESS_KEY environment variables
  http://docs.aws.amazon.com/sdk-for-cpp/v1/developer-guide/credentials.html


Building 
=========

To build, create a build directory::

    mkdir s3_build

Go into the directory and run ``cmake``, providing it with the path to where you built the SDK, and
the path to the directory that you want to build. For example::

    cd s3_build
    cmake -Daws-sdk-cpp_DIR=/path/to/aws_sdk_build/ ../s3

Finally, run ``make`` in the build directory:

    make


Running the examples
====================

The files are built right into the build directory, so you can run them by name. Go into the directory and run

    ./list_buckets


