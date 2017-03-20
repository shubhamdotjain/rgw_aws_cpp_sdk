
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/GetObjectRequest.h>
#include <fstream>

int main(int argc, char** argv)
{
    Aws::SDKOptions options;
    Aws::InitAPI(options);

    if(argc < 3) {
        std::cout << std::endl <<
            "To run this example, supply the name of an S3 bucket and object to"
            << std::endl << "download from it." << std::endl << std::endl <<
            "Ex: get_object <bucketname> <filename>\n" << std::endl;
        exit(1);
    }

    const Aws::String bucket_name = argv[1];
    const Aws::String key_name = argv[2];

    std::cout << "Downloading " << key_name << " from S3 bucket: " <<
        bucket_name << std::endl;

    {
        Aws::S3::S3Client s3_client;

        Aws::S3::Model::GetObjectRequest object_request;
        object_request.WithBucket(bucket_name).WithKey(key_name);

        auto get_object_outcome = s3_client.GetObject(object_request);

        if (get_object_outcome.IsSuccess()) {
            Aws::OFStream local_file;
            local_file.open(key_name.c_str(), std::ios::out | std::ios::binary);
            local_file << get_object_outcome.GetResult().GetBody().rdbuf();
            std::cout << "Done!" << std::endl;
        } else {
            std::cout << "GetObject error: " <<
                get_object_outcome.GetError().GetExceptionName() << " " <<
                get_object_outcome.GetError().GetMessage() << std::endl;
        }
    }

    Aws::ShutdownAPI(options);
}

