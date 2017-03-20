
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/DeleteObjectRequest.h>
#include <fstream>


int main(int argc, char** argv)
{
    Aws::SDKOptions options;
    Aws::InitAPI(options);

    if(argc < 3) {
        std::cout << std::endl <<
            "To run this example, supply the name of an S3 bucket and object to"
            << std::endl << "delete from it." << std::endl << std::endl <<
            "Ex: delete_object <bucketname> <filename>\n" << std::endl;
        exit(1);
    }

    const Aws::String bucket_name = argv[1];
    const Aws::String key_name = argv[2];

    std::cout << "Deleting" << key_name << " from S3 bucket: " <<
        bucket_name << std::endl;

    {
        Aws::S3::S3Client s3_client;

        Aws::S3::Model::DeleteObjectRequest object_request;
        object_request.WithBucket(bucket_name).WithKey(key_name);

        auto delete_object_outcome = s3_client.DeleteObject(object_request);

        if (delete_object_outcome.IsSuccess()) {
            std::cout << "Done!" << std::endl;
        } else {
            std::cout << "DeleteObject error: " <<
                delete_object_outcome.GetError().GetExceptionName() << " " <<
                delete_object_outcome.GetError().GetMessage() << std::endl;
        }
    }

    Aws::ShutdownAPI(options);
}

