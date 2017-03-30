/*for creds set/export AWS_ACCESS_KEY_ID AWS_SECRET_ACCESS_KEY
 * and pass -e = localhost:8000 if using vstart.sh 
 */

#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/Bucket.h>
#include <aws/s3/model/CreateBucketRequest.h>
#include <aws/s3/model/DeleteBucketRequest.h>
#include <network/uri.hpp>
#include <aws/iam/IAMClient.h>
#include <aws/iam/model/ListAccessKeysRequest.h>
#include <aws/iam/model/ListAccessKeysResult.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <assert.h>
#include <set>
using namespace std;

const char *my_endpoint;
const char *my_region;

int exitcode;

void get_new_bucket(const Aws::String bucket_name){
 std::cout << "Creating S3 bucket: " << bucket_name << std::endl;

    {
        Aws::S3::S3Client s3_client;

        Aws::S3::Model::CreateBucketRequest bucket_request;
        bucket_request.WithBucket(bucket_name);

        auto create_bucket_outcome = s3_client.CreateBucket(bucket_request);

        if (create_bucket_outcome.IsSuccess()) {
            std::cout << "Done!" << std::endl;
        } else {
            std::cout << "CreateBucket error: " <<
                create_bucket_outcome.GetError().GetExceptionName() << std::endl
                << create_bucket_outcome.GetError().GetMessage() << std::endl;
        }
    }
}
void delete_bucket(const Aws::String bucket_name){
	 std::cout << "Deleting S3 bucket: " << bucket_name << std::endl;

    {
        Aws::S3::S3Client s3_client;

        Aws::S3::Model::DeleteBucketRequest bucket_request;
        bucket_request.WithBucket(bucket_name);

        auto delete_bucket_outcome = s3_client.DeleteBucket(bucket_request);

        if (delete_bucket_outcome.IsSuccess()) {
            std::cout << "Done!" << std::endl;
        } else {
            std::cout << "DeleteBucket error: " <<
                delete_bucket_outcome.GetError().GetExceptionName() << std::endl
                << delete_bucket_outcome.GetError().GetMessage() << std::endl;
        }
    }
}

void get_all_buckets(){
	Aws::S3::S3Client s3_client;

	auto list_buckets_outcome = s3_client.ListBuckets();
	if (list_buckets_outcome.IsSuccess()) {
 		std::cout << "Your Amazon S3 buckets:" << std::endl;
 		Aws::Vector<Aws::S3::Model::Bucket> bucket_list =
 		list_buckets_outcome.GetResult().GetBuckets();
 		for (auto const &bucket: bucket_list) {
 			std::cout << "* " << bucket.GetName() << std::endl;
 		}
	} else {
 		std::cout << "ListBuckets error: " <<
 		list_buckets_outcome.GetError().GetExceptionName() << " " <<
 		list_buckets_outcome.GetError().GetMessage() << std::endl;
 		}
}


void list_access_keys(){
	Aws::IAM::IAMClient iam;
	Aws::IAM::Model::ListAccessKeysRequest request;
	request.SetUserName(userName);
	bool done = false;
	bool header = false;
	while (!done) {
	 	auto outcome = iam.ListAccessKeys(request);
	 	if (!outcome.IsSuccess()) {
	 		std::cout << "Failed to list access keys for user " << userName
			<< ": " << outcome.GetError().GetMessage() << std::endl;
	 		break;
	 	}
	 	if (!header) {
	 		std::cout << std::left << std::setw(32) << "UserName" <<
	 		std::setw(30) << "KeyID" << std::setw(20) << "Status" <<
	 		std::setw(20) << "CreateDate" << std::endl;
	 		header = true;
	 	}
	 	const auto &keys = outcome.GetResult().GetAccessKeyMetadata();
	 	for (const auto &key : keys) {
			Aws::String statusString =
			Aws::IAM::Model::StatusTypeMapper::GetNameForStatusType(
			key.GetStatus());
			std::cout << std::left << std::setw(32) << key.GetUserName() <<
			std::setw(30) << key.GetAccessKeyId() << std::setw(20) <<
			statusString << std::setw(20) <<
			key.GetCreateDate().ToGmtString(DATE_FORMAT) << std::endl;
			}
	 	if (outcome.GetResult().GetIsTruncated()) {
	 		request.SetMarker(outcome.GetResult().GetMarker());
	 	} else {
	 		done = true;
	}
}

/*def _test_bucket_create_naming_good_long(length):
    """
    Attempt to create a bucket whose name (including the
    prefix) is of a specified length.
    """
    prefix = get_new_bucket_name()
    assert len(prefix) < 255
    num = length - len(prefix)*/
    /*get_new_bucket(targets.main.default, '{prefix}{name}'.format(
            prefix=prefix,
            name=num*'a',
            ))*/



string get_new_bucket_name(){ //need to add the function that will create a unique name
    string s;
    getline(cin,name);
    return s;
  }




void _test_bucket_create_naming_good_long(long long int Length){

    string prefix;
    long long int len;

    prefix=get_new_bucket_name();  //would create the unique name of the bucket
    assert(prefix.length<255)
    len=Length-prefix.length();
    string temp(len,'a');
    create_bucket(temp);
 }


 /*@attr(resource='bucket')
@attr(method='get')
@attr(operation='list all buckets')
@attr(assertion='returns all expected buckets')
def test_buckets_create_then_list():
    create_buckets = [get_new_bucket() for i in xrange(5)]
    list_buckets = s3.main.get_all_buckets()
    names = frozenset(bucket.name for bucket in list_buckets)
    for bucket in create_buckets:
        if bucket.name not in names:
            raise RuntimeError("S3 implementation's GET on Service did not return bucket we created: %r", bucket.name)*/

void test_buckets_create_then_list(){
    vector<bucket> create_buckets(i);
    for(int i=0;i<5;i++){
    	name= get_new_bucket_name() // would create a unique name of the bucket
        create_buckets[i]=get_new_bucket();
        }

    vector<auto> list_buckets;
    list_buckets=get_all_buckets(); 
    set<string> name_temp;
    for(int i=0;i<list_buckets.size();i++){
        name_temp.insert(list_buckets[i].name);
        }

    const set<string> name=name_temp;
    std::set<string>::iterator it;
    for(int i=0;i<create_buckets.size();i++){
        it=s.find(create_buckets[i].name);
        if(*it!=create_buckets[i].name){
            throw std::runtime_error("S3 implementation's GET on Service did not return bucket we created: ", bucket.name);
        }
    }
}


      
       /* @attr(resource='bucket')
@attr(method='get')
@attr(operation='list')
@attr(assertion='empty buckets return no contents')
def test_bucket_list_empty():
    bucket = get_new_bucket()
    l = bucket.list()
    l = list(l)
    eq(l, [])*/
bool test_bucket_list_empty(){

    auto bucket;
    bucket=get_new_bucket();
    string* keys
    keys=list_access_keys();

    //contents=list.bucket();    will make function according to the data type 
    return (keys==NULL);
    }


int process()
{
	Aws::Client::ClientConfiguration clientconfig;
	if (my_region)
		clientconfig.region = my_region;
	if (my_endpoint) {
		Aws::String aws_my_endpoint(my_endpoint);
		network::uri u(my_endpoint);
		auto us = u.scheme().to_string();
		if (!us.compare("http")) {
			clientconfig.scheme = Aws::Http::Scheme::HTTP;
		}
		else if (!us.compare("https")) {
			clientconfig.scheme = Aws::Http::Scheme::HTTPS;
		} else {
			throw std::out_of_range("invalid scheme " + us);
		}
		std::string ur;
		ur = u.host().to_string();
		if (u.has_port()) {
			ur += ":" + u.port().to_string();
		}
		clientconfig.endpointOverride = ur.c_str();
	}

	Aws::S3::S3Client s3_client(clientconfig);

        /*
         * code to do things can go here
         */
}



int main(int ac, char **av)
{
	char *ap;
	while (--ac > 0) if (*(ap = *++av) == '-') while (*++ap) switch(*ap) {
	case 'e':
		if (--ac <= 0) {
			std::cerr << "-e: missing endpoint " << std::endl;
			goto Usage;
		}
		my_endpoint = *++av;
		my_region = "mexico";
		break;
	case '-':
		break;
	default:
		std::cerr << "bad flag " << *ap << std::endl;
	Usage:
		std::cerr << "Usage: lb2 [-e endpoint]" << std::endl;
		exit(1);
	}
	{
		Aws::SDKOptions options;
		Aws::InitAPI(options);
		process();
		Aws::ShutdownAPI(options);
	}
	exit(exitcode);
}

