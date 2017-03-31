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


#include<iostream>
#include<string>
#include<cassert>
using namespace std;

//This function would create unique name for the bucket, but it is hardcoded right now

string get_new_bucket_name(){ 
    string s;
    getline(cin,s);
    return s;
  }


void create_bucket(string s)
{
    cout<<"Bucket created with bucket name"<<" "<<s;
}

void test_bucket_create_naming_good_long(long long int Length){

    string prefix;
    long long int len;
    // would create the unique name of the bucket
    prefix=get_new_bucket_name();  
    assert(prefix.length()<255);
    len=Length-prefix.length();
    string temp(len,'a');
    create_bucket(temp);
 }


int main()
{
    test_bucket_create_naming_good_long(300);



    return 0;
}