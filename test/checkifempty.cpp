       /* @attr(resource='bucket')
@attr(method='get')
@attr(operation='list')
@attr(assertion='empty buckets return no contents')
def test_bucket_list_empty():
    bucket = get_new_bucket()
    l = bucket.list()
    l = list(l)
    eq(l, [])*/

#include<iostream>
#include<string>
#include<cassert>
#include<vector>
using namespace std;


class bucket
{
	public:
	int num_key;
	vector<string> keys;
    vector<string> list_access_keys();

};


bucket get_new_bucket()
{
bucket b;
cin>>b.num_key;
string key;
for(int i=0;i<b.num_key;i++)
{
	cin>>key;
	b.keys.push_back(key);
}
return b;
}

//This function would get list of access keys from the bucket, but it is hardcoded right now
vector<string> bucket::list_access_keys()
{
	return keys;
}

bool test_bucket_list_empty(){

     
    bucket Bucket=get_new_bucket();
    vector<string> keys;
    keys=Bucket.list_access_keys();
    return (keys.size()==0);
    }

    int main()
    {
        bool temp=test_bucket_list_empty();
        cout<<temp;


    	return 0;
    }